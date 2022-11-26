/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:38:45 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/25 03:12:25 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_virus_col(t_position *data, int y, int x, int direction)
{
	while ((y >= 0 && y <= data->y) && (data->mapcpy[y][x] != '1')
			&& (data->mapcpy[y][x] != 'W'))
	{
		if (!data->isnewpath)
			data->isnewpath = data->mapcpy[y][x] != '*';
		data->mapcpy[y][x] = '*';
		y += direction;
	}
}

void	ft_virus_row(t_position *data, int y, int x, int direction)
{
	while ((x >= 0 && x <= data->x) && (data->mapcpy[y][x] != '1')
			&& (data->mapcpy[y][x] != 'W'))
	{
		if (!data->isnewpath)
			data->isnewpath = data->mapcpy[y][x] != '*';
		data->mapcpy[y][x] = '*';
		x += direction;
	}
}

void	ft_propagation(int y, int x, t_position *data)
{
	ft_virus_col(data, y, x, 1);
	ft_virus_col(data, y, x, -1);
	ft_virus_row(data, y, x, 1);
	ft_virus_row(data, y, x, -1);
}

int	ft_covid(t_position *data)
{
	int	i;
	int	j;

	i = 0;
	data->isnewpath = 0;
	while (i < data->y)
	{
		j = 0;
		while (j < data->x)
		{
			if (data->mapcpy[i][j] == 'P' || data->mapcpy[i][j] == '*')
			{
				ft_propagation(i, j, data);
			}
			j++;
		}
		i += 1;
	}
	return (0);
}
