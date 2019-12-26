cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(libft)

add_executable(push_swap
        libft/ft_atoi.c
        libft/ft_error.c
        libft/ft_intcpy.c
        libft/ft_putchar.c
        libft/ft_putnbr.c
        libft/ft_putstr.c
        libft/ft_strsplit.c
        libft/libft.h
        actions.c
        checker.c
        push_swap.c
        push_swap.h
        separation.c
        sort_algorithms.c
        validation.c init.c)
