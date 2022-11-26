/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:19:26 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/24 19:42:01 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_graphical(t_data *img, t_position *map)
{
	if (!init_mlx(img, map))
		return (ft_destroy(img, 9));
	map->map[map->ey][map->ex] = 'K';
	display_pix(img, map);
	mlx_hook(img->mlx_win, .5, 1L << 0, deal_key, img);
	mlx_key_hook(img->mlx_win, deal_key, img);
	mlx_hook(img->mlx_win, 17, 0, raschakal, img);
	mlx_loop(img->mlx);
	if (img->mlx)
		mlx_loop_end(img->mlx);
	ft_printf("FIN\n");
	return (1);
}

int	init_mlx(t_data *img, t_position *map)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		return (0);
	img->mlx_win = mlx_new_window(img->mlx, map->x * 64, map->y * 64, "FOOTIX");
	if (!img->mlx_win)
		return (0);
	return (set_img(img));
}

void	split_img(t_data *img, t_position *map, int i, int j)
{
	void	**imtab;
	void	*win;

	imtab = img->imgblock;
	win = img->mlx_win;
	if (((j == 0) && (i != 0) && (i != map->y - 1)) || ((j == map->x - 1)
			&& (j != map->x) && i != 0 && i != map->y - 1))
		mlx_put_image_to_window(img->mlx, win, imtab[5], (j * 64), (i * 64));
	else if (i == map->y - 1 && j == 0)
		mlx_put_image_to_window(img->mlx, win, imtab[7], (j * 64), (i * 64));
	else if (j == 0 && i == 0)
		mlx_put_image_to_window(img->mlx, win, imtab[6], j * 64, i * 64);
	else if (j == map->x - 1 && i == map->y - 1)
		mlx_put_image_to_window(img->mlx, win, imtab[9], j * 64, i * 64);
	else if (j == map->x - 1 && i == 0)
		mlx_put_image_to_window(img->mlx, win, imtab[8], j * 64, i * 64);
	else
		mlx_put_image_to_window(img->mlx, win, imtab[0], (j * 64), (i * 64));
}

int	set_img(t_data *img)
{
	void		*mlx;
	int			tab[2];
	int			j;
	int			i;
	static char	*ta[10] = {
		WALL, P, GROUND, EXIT, COLLECT, CO, COINHG, COINBG, COINHD, COINBD};

	j = -1;
	i = -1;
	mlx = img->mlx;
	while (++i < 10)
	{
		img->imgblock[i] = mlx_xpm_file_to_image(mlx, ta[i], &tab[0], &tab[1]);
		if (!img->imgblock[i])
		{
			while (++j <= i && img->imgblock[i])
			{
				mlx_destroy_image(img->mlx, img->imgblock[i]);
				img->imgblock[i] = 0;
			}
			return (0);
		}
	}
	return (1);
}

/* ************************************************************************** */