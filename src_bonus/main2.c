/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:42:48 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/25 18:10:19 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	raschakal(t_data *param)
{
	mlx_loop_end(param->mlx);
	return (1);
}

int	ft_destroy(t_data *img, int j)
{
	int	i;

	i = -1;
	while (++i <= j && img->imgblock[i])
	{
		mlx_destroy_image(img->mlx, img->imgblock[i]);
		img->imgblock[i] = 0;
	}
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	return (0);
}

int	main(int argc, char const *argv[])
{
	int					fd;
	static t_position	data;
	static t_data		img;

	img.ptrmapstruct = &data;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || !fd)
		return (close(fd));
	if (!check_toutes_erreurs(argv[1], &data))
		return (0);
	if (!ft_graphical(&img, &data))
		return (clean_tab(data.map));
	ft_destroy(&img, 22);
	clean_tab(data.map);
	return (1);
}
