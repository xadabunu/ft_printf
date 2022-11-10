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

SRCS	=	ft_printf.c \
			ft_put_basic.c \
			ft_put_hexa.c \
			ft_utils.c

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

CC		=	@gcc

FLAGS	=	-Wall -Wextra -Werror

RM		=	@rm -f

.c.o	:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}	:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all		:	${NAME}

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re