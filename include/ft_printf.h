/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:53:22 by xadabunu          #+#    #+#             */
/*   Updated: 2022/11/03 19:53:23 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);

int	ft_putchar(const char c);
int	ft_putstr(const char *str);
int	ft_putnbr(const int n);
int	ft_putnbr_unsigned(const unsigned int n);
int	ft_puthexa(const unsigned int n);
int	ft_puthexa_upper(const unsigned int n);
int	ft_putptr(const void *ptr);

#endif