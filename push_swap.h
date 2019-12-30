/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:43:48 by doberyn           #+#    #+#             */
/*   Updated: 2019/12/22 14:43:49 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP__PUSH_SWAP_H
#define PUSH_SWAP__PUSH_SWAP_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct			s_steps
{
	int					count_a;
	int 				count_b;
	int 				dest_a;
	int 				dest_b;
}						t_steps;


typedef struct			s_data
{
  int					a[10000];
  int					count_element;
}						t_data;

typedef struct 			s_stack
{
  int 				data;
  int 				step;
  int				rotate;
  struct s_stack		*next;
}						t_stack;

typedef struct			s_stacks
{
	int					count_a;
	int 				count_b;
	int 				min;
	int 				max;
	int 				med;
	t_stack				*a;
	t_stack				*b;
}						t_stacks;

void 		ft_sa(t_stack *a);
void 		ft_sb(t_stack *b);
void  		ft_ss(t_stacks *s);
void	ft_pa(t_stacks *s);
void	ft_pb(t_stacks *s);
void    ft_ra(t_stack **a);
void ft_rb(t_stack **b);
void  ft_rr(t_stacks *s);
void ft_rra(t_stack **a);
void ft_rrb(t_stack **b);
void  ft_rrr(t_stacks *s);


void	ft_sort(t_stacks *stacks);
void	ft_sort_3_element(t_stacks *stacks);
void	ft_sort_5_element(t_stacks *stacks);

void    ft_print_stack(t_stacks *stacks);
void	ft_init_stack(t_data *new,t_stacks *stacks);
int 	ft_max(t_stack *stack);
void	ft_global_sort(t_stacks *stacks);

void		ft_error();

/* validation.c - Валидация - Нормы ✓ */

void	ft_validate(int argc, char **argv);
int		ft_number_availability(const char *str);
void	ft_valid_str(char *str);
void	ft_duplicate_check(t_data *new,t_stacks *stacks);
void ft_search_duplicate(int *dup, int count);

/* separation.c - Разбивка массива - Нормы ✓ */

void	ft_array_separation(int argc, char **argv, t_data *new);
void	ft_stacking(t_data *new,int *buff,int count);

/* sort_algorithms.c - Алгоритм сортировки - Нормы ✓ */

void	ft_quick_sort(int *array, int start, int end);
int		ft_partition(int *array, int start, int end);

/* init.c - Инициализация стека - Нормы */

t_stack  *ft_create_stack(const int *buff, int count);

#endif //PUSH_SWAP__PUSH_SWAP_H
