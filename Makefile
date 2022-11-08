# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xadabunu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 15:28:29 by xadabunu          #+#    #+#              #
#    Updated: 2022/11/08 15:28:32 by xadabunu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c /
			ft_put_basic.c /
			ft_put_hexa.c

OBJS	=	${SRCS:.c=.o}

DEP		=	libft.a

LIB_P	=	libft/

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

