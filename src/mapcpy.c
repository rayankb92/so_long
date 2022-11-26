/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:43:39 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/23 22:44:49 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bigtab_cpy(char ***str, char **src, t_position data)
{
	int	i;

	i = 0;
	(*str) = malloc(sizeof(char *) * (data.y + 1));
	while (i < data.y)
	{
		(*str)[i] = ft_strdup(src[i]);
		i++;
	}
	(*str)[i] = 0;
}

int	mapcheck(char **tab, t_position *pos)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	get_pos(tab, pos);
	while (tab[++i])
	{
		if (pos->x != (int)ft_strlen(tab[i]))
			return (0);
		j = -1;
		while (tab[i][++j])
			if (((i == 0 || i == pos->y - 1) || (j == 0 || j == pos->x - 1))
				&& tab[i][j] != '1')
				return (0);
	}
	if (!check_pe(tab, 'P') || !check_pe(tab, 'E'))
		return (0);
	return (1);
}

int	check_toutes_erreurs(const char *argv, t_position *data)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (!check_ext(argv) || fd == -1)
		return (0);
	data->map = readfile(fd);
	if (!data->map || !mapcheck(data->map, data))
	{
		ft_printf("Map Invalide !\n");
		return (clean_tab(data->map));
	}
	bigtab_cpy(&data->mapcpy, data->map, *data);
	while ((data->mapcpy[data->ey][data->ex] == 'E') || ((data->isnewpath)
			&& (is_e(data->mapcpy, 'C'))))
	{
		ft_covid(data);
		if (!data->isnewpath)
		{
			ft_printf("Sortie ou Collectible inatteignable !\n");
			clean_tab(data->map);
			return (clean_tab(data->mapcpy));
		}
	}
	clean_tab(data->mapcpy);
	return (1);
}
