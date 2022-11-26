/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferradi <rferradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:44:56 by rferradi          #+#    #+#             */
/*   Updated: 2022/11/11 16:07:45 by rferradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int *count)
{
	long long int	nb;

	nb = (long long int)n;
	if (n < 0)
	{
		write(1, "-", 1);
		(*count)++;
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_putchar((nb + '0'));
		(*count)++;
	}
	else
	{
		ft_putnbr((nb / 10), count);
		ft_putchar(((nb % 10) + '0'));
		(*count)++;
	}
	return (*count);
}

int	ft_putnbr_u(unsigned int nb, int *count)
{
	if (nb < 10)
	{
		ft_putchar((nb + '0'));
		(*count)++;
	}
	else
	{
		ft_putnbr_u((nb / 10), count);
		ft_putchar(((nb % 10) + '0'));
		(*count)++;
	}
	return (*count);
}
