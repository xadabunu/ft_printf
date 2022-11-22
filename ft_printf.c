/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:10:43 by xadabunu          #+#    #+#             */
/*   Updated: 2022/11/03 19:49:53 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flags_manager(const char c, va_list *ap, unsigned int *ctr)
{
	if (c == '%')
		(*ctr) += ft_putchar('%');
	else if (c == 'c')
		(*ctr) += ft_putchar(va_arg(*ap, int));
	else if (c == 's')
		(*ctr) += ft_putstr(va_arg(*ap, char *));
	else if (c == 'd' || c == 'i')
		(*ctr) += ft_putnbr(va_arg(*ap, int));
	else if (c == 'p')
		(*ctr) += ft_putaddress(va_arg(*ap, void *));
	else if (c == 'x')
		(*ctr) += ft_puthexa(va_arg(*ap, unsigned int));
	else if (c == 'X')
		(*ctr) += ft_puthexa_upper(va_arg(*ap, unsigned int));
	else if (c == 'u')
		(*ctr) += ft_putnbr_unsigned(va_arg(*ap, unsigned int));
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	pos;
	unsigned int	ctr;

	va_start(ap, str);
	ctr = 0;
	while (*str)
	{
		pos = 0;
		while (str[pos] && str[pos] != '%')
			++pos;
		write(1, str, pos);
		ctr += pos;
		if (str[pos] == '%')
		{
			++pos;
			if (ft_flags_manager(str[pos], &ap, &ctr))
				++pos;
		}
		str += pos;
	}
	va_end(ap);
	return (ctr);
}
