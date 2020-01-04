# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile1                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doberyn <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 18:14:41 by doberyn           #+#    #+#              #
#    Updated: 2019/04/10 18:13:02 by doberyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I. -c

CFILE = 	ft_atoi.c ft_strsub.c \
            ft_error.c ft_strjoin.c \
            ft_intcpy.c ft_strdup.c \
            ft_putchar.c ft_strdel.c \
            ft_putnbr.c ft_strchr.c\
            ft_putstr.c ft_strlen.c \
            ft_strsplit.c ft_strcmp.c

OFILE = $(CFILE:.c=.o)

all: $(NAME)

$(NAME): $(OFILE)
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)

clean:
	rm -f $(OFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all