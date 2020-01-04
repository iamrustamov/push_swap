cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)

add_executable(push_swap
        includes/get_next_line.h
        includes/libft.h
        includes/push_swap.h
        libft/ft_atoi.c
        libft/ft_error.c
        libft/ft_intcpy.c
        libft/ft_putchar.c
        libft/ft_putnbr.c
        libft/ft_putstr.c
        libft/ft_strchr.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strcmp.c
        libft/ft_strjoin.c
        libft/ft_strlen.c
        libft/ft_strsplit.c
        libft/ft_strsub.c
        push_swap.c
        actions.c
        actions_2.c
        actions_3.c
        checker.c
        finding_place.c
        get_next_line.c
        global_sort.c
        initialization.c
        push_swap.c
        quick_sort.c
        separation.c
        sort_3_and_5_element.c
        validation.c)
