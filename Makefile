# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doberyn <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 23:40:57 by tyasmine          #+#    #+#              #
#    Updated: 2019/12/18 23:41:01 by tyasmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap

NAME2	= checker

CFLAGS 	= -Wall -Wextra

SRC1 	= push_swap.c actions.c actions_3.c actions_2.c finding_place.c global_sort.c initialization.c quick_sort.c \
			separation.c sort_3_and_5_element.c validation.c

SRC2 	= get_next_line.c checker.c actions.c actions_3.c actions_2.c finding_place.c global_sort.c initialization.c quick_sort.c \
                    			separation.c sort_3_and_5_element.c validation.c

OBJSFD 	= temporary

OBJS1 	= $(addprefix $(OBJSFD)/,$(SRC1:.c=.o))

OBJS2 	= $(addprefix $(OBJSFD)/,$(SRC2:.c=.o))

HDR         = -I./includes

LIBFT_HDR   = -I./includes

LIB_BINARY  = -L./libft -lft

LIBFT       = ./libft/libft.a

all: $(LIBFT) $(NAME1) $(NAME2)

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	gcc -g $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(LIBFT):
	make -C ./libft

$(NAME1): $(OBJS1) $(LIBFT)
	gcc -g $(OBJS1) $(LIB_BINARY) -o $@

$(NAME2): $(OBJS2) $(LIBFT)
	gcc -g $(OBJS2) $(LIB_BINARY) -o $@

clean:
	/bin/rm -f $(OBJS)
	rm -rf $(OBJSFD)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)
	make -C ./libft fclean

re: fclean all

