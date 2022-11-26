/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:31:44 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/08 20:14:46 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res || !s1 || !s2)
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
		res[j] = s1[j];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

// int main(int argc, char const *argv[])
// {
// 	char *res;
// 	res = ft_strjoin("suffixe ", "prefixe");
// 	printf("%s\n", res);
// 	return 0;
// }
