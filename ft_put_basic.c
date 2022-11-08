/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:16:32 by xadabunu          #+#    #+#             */
/*   Updated: 2022/11/05 15:16:34 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_putchar(const char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	ft_nbrlen(long n)
{
	int	ctr;

	ctr = 1;
	if (n < 0)
	{
		++ctr;
		n = -n;
	}
	while (n > 9)
	{
		++ctr;
		n /= 10;
	}
	return (ctr);
}

int	ft_putnbr(const int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_nbrlen(n));
}

int	ft_putnbr_unsigned(const unsigned int n)
{
	if (n > 9)
		ft_putunsnbr(n / 10);
	ft_putchar('0' + n % 10);
	return (ft_nbrlen(n));
}