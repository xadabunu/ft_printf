/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:44:18 by xadabunu          #+#    #+#             */
/*   Updated: 2022/11/06 00:44:20 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	ft_hexalen(unsigned int n)
{
	unsigned int	ctr;

	ctr = 1;
	while (n > 15)
	{
		++ctr;
		n /= 16;
	}
	return (ctr);
}

static void	ft_recur(const unsigned int n, const char *base)
{
	if (n > 15)
		ft_recur(n / 16, base);
	ft_putchar(base[n % 16]);
}

int	ft_puthexa(const unsigned int n)
{
	ft_recur(n, "0123456789abcdef");
	return (ft_hexalen(n));
}

int	ft_puthexa_upper(const unsigned int n)
{
	ft_recur(n, "0123456789ABCDEF");
	return (ft_hexalen(n));
}

int	ft_putptr(const void* ptr)
{
	return (ft_putstr("0x") + ft_puthexa((unsigned int)ptr));
}
