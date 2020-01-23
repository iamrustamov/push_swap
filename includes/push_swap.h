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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct		s_steps
{
	int				count_a;
	int				count_b;
	int				dest_a;
	int				dest_b;
}					t_steps;

typedef struct		s_data
{
	int				a[10000];
	int				count_element;
}					t_data;

typedef struct		s_stack
{
	int				data;
	int				step;
	int				rotate;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	int				count_a;
	int				count_b;
	int				min;
	int				max;
	int				med;
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

/*
**		push_swap.c - Начало
**			༺༻
**		Нормы:		✓
**			༺༻
*/

int					ft_only_spaces(const char *str);
int					ft_is_sorted(t_data *new);
void				ft_rrr(t_stacks *s, int i);

/*
**		validation.c - Валидация
**			༺༻
**		Нормы:		✓
**			༺༻
*/

int					ft_validation(int argc, char **argv);
void				ft_number_availability(const char *str);
void				ft_valid_str(const char *str);
void				ft_duplicate_check(t_data *new, t_stacks *stacks);
void				ft_search_duplicate(const int *dup, int count);

/*
**		separation.c - Разбивка массива
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				ft_array_separation(int argc, char **argv, t_data *new);
void				ft_stacking(t_data *new, int *buff, int count);

/*
**		initialization.c - Инициализация стека
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				ft_init_stack(t_data *new, t_stacks *stacks);
t_stack				*ft_create_stack(const int *buff, int count);
void				ft_free_stack(t_stacks *stacks);
void				ft_sort(t_stacks *stacks);
void				ft_null(t_stacks *stacks, t_data *new);

/*
**		sort_3_and_5_element.c - Сортировка 5-и и меньше чисел.
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				ft_sort_3_element(t_stacks *stacks);
void				ft_sort_5_element(t_stacks *stacks);
int					ft_max(t_stack *s);

/*
**		 quick_sort.c - Алгоритм быстрой сортировки
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				ft_quick_sort(int *array, int start, int end);
int					ft_partition(int *array, int start, int end);

/*
**		 global_sort.c - Алгоритм для сортировки любого количества чисел
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				ft_global_sort(t_stacks *stacks);
void				ft_start_sort(t_stacks *stacks);
void				ft_steps_markup(t_stack *b, int count);
void				ft_minimum_insertion_steps(t_stacks *stacks,
							t_steps *steps);
void				ft_instruction_execution(t_stacks *stacks, t_steps *steps);

/*
**		 finding_place.c - Основная часть главного алгоритма
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				ft_help_finding_place(t_stacks *s, t_stack *b,
							int *action, int *buff);
int					ft_finding_place(t_stacks *s, t_stack *b,
							t_steps *steps, int min);
int					ft_smaller_element_detection(t_stack *a, int buff, int src);
int					ft_count_to_min(t_stack *a, int min);

/*
**		 actions.c - Действия
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				ft_ra(t_stack **a, int i);
void				ft_rb(t_stack **b, int i);
void				ft_rr(t_stacks *s, int i);
void				ft_rra(t_stack **a, int i);
void				ft_rrb(t_stack **b, int i);

/*
**		 actions_2.c - Действия
**			༺༻
**		Нормы:		✓
**			༺༻
*/

void				ft_sa(t_stack *a, int i);
void				ft_sb(t_stack *a, int i);
void				ft_ss(t_stacks *s, int i);
void				ft_pa(t_stacks *s, int i);
void				ft_pb(t_stacks *s, int i);

/*
**		 checker.c - Чекер
**			༺༻
**		Нормы:		✓
**			༺༻
*/

int					ft_stack_sorted(t_stacks *s);
void				ft_read_action(t_stacks *s);
void				ft_action_processing(char *line, t_stacks *s);

#endif
