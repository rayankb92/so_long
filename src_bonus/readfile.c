/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:51:48 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/24 18:51:36 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**readfile(int fd)
{
	int		reader;
	char	*res;
	char	temp[2];
	char	**tab;

	reader = 1;
	res = NULL;
	while (reader != 0)
	{
		reader = read(fd, temp, 1);
		if (reader < 0)
			return (NULL);
		temp[reader] = 0;
		res = ft_strjoin_gnl(res, temp);
	}
	if (res[ft_strlen(res) - 1] == '\n' || empty_line(res) || !res[0])
	{
		free(res);
		return (NULL);
	}
	tab = ft_split(res, '\n');
	free(res);
	return (tab);
}
