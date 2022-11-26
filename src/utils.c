/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:41:47 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/24 19:04:21 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ext(const char *file)
{
	int	three;
	int	len;

	len = ft_strlen(file) - 1;
	three = 3;
	while (file[len] && file[len] == EXT[three] && three >= 0)
	{
		if (three == 0)
			return (1);
		three--;
		len--;
	}
	ft_printf("Extension incorrect\n");
	return (0);
}

int	ft_strlen_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	get_pos(char **map, t_position *pos)
{
	int	i;
	int	j;

	i = -1;
	pos->y = ft_strlen_double(map);
	pos->x = ft_strlen(map[0]);
	pos->isnewpath = 1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				pos->py = i;
				pos->px = j;
			}
			if (map[i][j] == 'E')
			{
				pos->ey = i;
				pos->ex = j;
			}
		}
	}
}

int	clean_tab(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (0);
}

void	display(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		ft_printf("%s\n", map[i++]);
	write(1, "\n", 1);
}
