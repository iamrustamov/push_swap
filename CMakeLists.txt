cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)

add_executable(push_swap
        includes/libft.h
        includes/push_swap.h
        libft/ft_atoi.c
        libft/ft_error.c
        libft/ft_intcpy.c
        libft/ft_putchar.c
        libft/ft_putnbr.c
        libft/ft_putstr.c
        libft/ft_strsplit.c
        srcs/actions.c
        srcs/initialization.c
        srcs/push_swap.c
        srcs/separation.c
        srcs/quick_sort.c
        srcs/validation.c
        checker.c srcs/sort_3_and_5_element.c srcs/global_sort.c srcs/finding_place.c srcs/actions_2.c)
