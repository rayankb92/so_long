/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaypix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:01:59 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/25 18:13:36 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_pix2(t_data *img, t_position *map, int *i, int *j)
{
	while (++(*j) < map->x)
	{
		if (map->map[*i][*j] == '1')
			split_img(img, map, *i, *j);
		if (map->map[*i][*j] == 'P')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblock[11],
				((*j) * 64), ((*i) * 64));
		if (map->map[*i][*j] == '0' || map->map[*i][*j] == 'K')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblock[12],
				((*j) * 64), ((*i) * 64));
		if (map->map[*i][*j] == 'C')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblock[14],
				((*j) * 64), ((*i) * 64));
		if (map->map[*i][*j] == 'E')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblock[13],
				((*j) * 64), ((*i) * 64));
		if (map->map[*i][*j] == 'W' && img->countmouv % 2 == 0)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblock[20],
				((*j) * 64), ((*i) * 64));
		if (map->map[*i][*j] == 'W' && img->countmouv % 2 != 0)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblock[21],
				((*j) * 64), ((*i) * 64));
	}
}

void	display_pix(t_data *img, t_position *map)
{
	int	i;
	int	j;

	i = -1;
	if (is_e(map->map, 'C') == 0)
		map->map[map->ey][map->ex] = 'E';
	while (++i < map->y)
	{
		j = -1;
		display_pix2(img, map, &i, &j);
	}
}
