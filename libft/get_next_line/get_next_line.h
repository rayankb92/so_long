/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:02:16 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/24 15:42:53 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *str, char c);
char	*fill_buffer(char *bufferleft, int fd);
int		count_line(char *str);
char	*cut_line(char *bufferleft);
char	*new_buff(char *bufferleft);

size_t	ft_strlen_gnl(const char *str);

#endif