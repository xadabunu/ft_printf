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

static void	ft_flags_manager(const char c, va_list ap, unsigned int pos)
{
	if (c == '%')
		ft_putchar('%');
	else if (c == 'c')
		ft_putchar(va_arg(ap, char));
	else if (c == 's')
		ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, double));
	else if (c == 'p')
		ft_putadd(va_arg(ap, void *));
	else if (c == 'x')
		ft_puthexa(va_arg(ap, int));
	else if (c == 'X')
		ft_puthexa_upper(va_arg(ap, int));
	else if (c == 'u')
		ft_putunsint(va_arg(ap, unsigned int));
	else
		pos -= 1;
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	pos;

	va_start(ap, str);
	while (str[pos])
	{
		pos = 0;
		while (str[pos] && str[pos] != '%')
			++pos;
		write(1, str, pos);
		if (str[pos] == '%' && str[pos + 1])
		{
			++pos;
			ft_flags_manager(str[pos], ap, pos);
		}
		str += pos + 1;
	}
	va_end(ap);
	return (0);
}
