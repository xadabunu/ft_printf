/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:52:46 by xadabunu          #+#    #+#             */
/*   Updated: 2022/11/10 13:52:48 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	ft_nbrlen(long n)
{
	unsigned int	ctr;

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

static void	ft_subputnbr(const unsigned int n)
{
	if (n > 9)
		ft_subputnbr(n / 10);
	ft_putchar(48 + n % 10);
}

int	ft_putnbr(const int n)
{
	unsigned int	uns_n;

	if (n < 0)
	{
		ft_putchar('-');
		uns_n = -n;
	}
	else
		uns_n = n;
	ft_subputnbr(uns_n);
	return (ft_nbrlen(n));
}
