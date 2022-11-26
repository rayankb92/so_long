/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:56:11 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/24 19:03:54 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	empty_line(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (1);
	return (0);
}

int	check_pe(char **tab, char c)
{
	int	i;
	int	j;
	int	isintab;

	i = -1;
	isintab = 0;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (!is_incharset(tab[i][j], CHAREST))
				return (0);
			if (tab[i][j] == c)
				isintab++;
		}
	}
	if ((c == 'P' && isintab == 1) || (c == 'E' && isintab == 1))
		return (1);
	return (0);
}

int	is_e(char **map, char c)
{
	int	i;
	int	j;
	int	isintab;

	i = -1;
	isintab = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == c)
				isintab++;
	}
	return (isintab);
}

int	is_incharset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}
