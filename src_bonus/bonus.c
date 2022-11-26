/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:34:59 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/25 17:57:45 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_score(t_data *img, t_position *map, int nbr, int i)
{
	if (nbr != 0)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblock[nbr % 10],
			(64 * i), (map->y * 64));
		display_score(img, map, (nbr / 10), i - 1);
	}
}

void	display_downpix(t_data *img, t_position *map)
{
	int	i;

	i = -1;
	img->countmouv = 0;
	while (++i < map->x)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblock[0], (64
				* i), (map->y * 64));
	}
}

int	ft_gameover(t_data *img)
{
	ft_printf("\n\nGAME OVER !!!\nGIROUD VOUS A RENVERSER AVEC SON KART\n\n");
	mlx_loop_end(img->mlx);
	return (0);
}
