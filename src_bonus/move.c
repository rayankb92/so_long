/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:45:33 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/25 03:08:07 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	next_position_col(t_data *img, int *i, int *y, int dir)
{
	if (img->ptrmapstruct->map[((*i) + dir)][(*y)] == 'W')
		return (ft_gameover(img));
	img->ptrmapstruct->map[*i][*y] = '0';
	if (dir == -1)
		(*i)--;
	else
		(*i)++;
	img->ptrmapstruct->map[(*i)][*y] = 'P';
	return (1);
}

int	next_position_row(t_data *img, int *i, int *y, int dir)
{
	if (img->ptrmapstruct->map[(*i)][(*y) + dir] == 'W')
		return (ft_gameover(img));
	img->ptrmapstruct->map[*i][*y] = '0';
	if (dir == -1)
		(*y)--;
	else if (dir == 1)
		(*y)++;
	img->ptrmapstruct->map[(*i)][*y] = 'P';
	return (1);
}

int	deal_key(int key, t_data *img)
{
	int			*yptr;
	int			*xptr;

	yptr = &img->ptrmapstruct->py;
	xptr = &img->ptrmapstruct->px;
	if (key == 'w' && img->ptrmapstruct->map[*yptr - 1][*xptr] != '1')
		img->countmouv += next_position_col(img, yptr, xptr, -1);
	if (key == 's' && img->ptrmapstruct->map[*yptr + 1][*xptr] != '1')
		img->countmouv += next_position_col(img, yptr, xptr, 1);
	if (key == 'd' && img->ptrmapstruct->map[*yptr][*xptr + 1] != '1')
		img->countmouv += next_position_row(img, yptr, xptr, 1);
	if (key == 'a' && img->ptrmapstruct->map[*yptr][*xptr - 1] != '1')
		img->countmouv += next_position_row(img, yptr, xptr, -1);
	display_pix(img, img->ptrmapstruct);
	if (img->test != img->countmouv)
		ft_printf("TOTAL MOUV = %i\n", img->countmouv);
	img->test = img->countmouv;
	if (key == 65307)
		mlx_loop_end(img->mlx);
	if ((*yptr == img->ptrmapstruct->ey && *xptr == img->ptrmapstruct->ex)
		&& is_e(img->ptrmapstruct->map, 'C') == 0)
		return (ft_goal(img));
	display_score(img, img->ptrmapstruct, img->countmouv,
		img->ptrmapstruct->x - 1);
	return (1);
}

int	ft_goal(t_data *img)
{
	ft_printf("\n\n!!!! GOOOAAAL !!!!\n\n");
	mlx_loop_end(img->mlx);
	return (0);
}
