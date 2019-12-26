/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:35:15 by doberyn           #+#    #+#             */
/*   Updated: 2019/12/22 17:35:16 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_data *new,t_stacks *stacks)
{
	stacks->a = ft_create_stack(new->a, new->count_element);
	stacks->b = NULL;
	ft_print_stack(stacks);
	ft_sort(stacks);
	ft_print_stack(stacks);
	/*while (s.a)
	{
		printf("[%d]\n", s.a->data);
		s.a = s.a->next;
	}*/
}

void	ft_steps_markup(t_stack *b, int count)
{
	t_stack *buff;
	int i;
	int iter;
	int prom;

	iter = count/2;
	i = -1;
	buff = b;
	while (++i <= iter)
	{
		buff->step = i;
		buff = buff->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff = buff->next;
	}
}

void	ft_global_sort(t_stacks *stacks)
{
	while (stacks->count_a > 2)
	{
		if (stacks->a->data != stacks->min && stacks->a->data != stacks->max) {
			ft_pb(stacks);
			ft_print_stack(stacks);
			if (stacks->b->data > stacks->med) {
				ft_rb(&stacks->b);
				ft_print_stack(stacks);
			}
			else
				printf("pass");
		}
		else
			ft_ra(&stacks->a);
	}
	if (stacks->a->data < stacks->a->next->data)
		ft_sa(stacks->a);
	ft_pa(stacks);
	ft_print_stack(stacks);
	ft_steps_markup(stacks->b, stacks->count_b);
}

void	ft_sort(t_stacks *stacks)
{
	if (stacks->count_a <= 3)
		ft_sort_3_element(stacks);
	else if (stacks->count_a <= 5)
		ft_sort_5_element(stacks);
	else
		ft_global_sort(stacks);
}


void	ft_sort_3_element(t_stacks *stacks)
{
	int max;

	max = ft_max(stacks->a);
	if (stacks->count_a == 1)
		return ;
	else if (stacks->count_a == 2)
	{
		if (stacks->a->data > stacks->a->next->data)
			ft_sa(stacks->a);
		return;
	}
	else if (stacks->count_a == 3)
	{
		if (stacks->a->data == max)
			ft_ra(&stacks->a);
		if (stacks->a->next->data == max)
		{
			ft_rra(&stacks->a);
			ft_print_stack(stacks);
		}
		if (stacks->a->data > stacks->a->next->data)
			ft_sa(stacks->a);
	}
}

int 	ft_max(t_stack *s)
{
	int max;

	max = s->data;
	while(s)
	{
		if (s->data > max)
			max = s->data;
		s = s->next;
	}
	return (max);
}

void	ft_sort_5_element(t_stacks *stacks)
{
	while(stacks->count_b < 2)
	{
		if(stacks->a->data == stacks->min || stacks->a->data == stacks->max)
			ft_pb(stacks);
		else
			ft_ra(&stacks->a);
		ft_print_stack(stacks);
	}
	ft_sort_3_element(stacks);
	ft_pa(stacks);
	ft_print_stack(stacks);
	ft_pa(stacks);
	ft_print_stack(stacks);
	if (stacks->a->data == stacks->max)
	{
		ft_ra(&stacks->a);
	}
	else
	{
		ft_sa(stacks->a);
		ft_print_stack(stacks);
		ft_ra(&stacks->a);
	}
	ft_print_stack(stacks);
}

/*
**		ft_create_stack - Получаем массив чисел и
** 		переписываем определенное количество элементов в листы.
**		Состояние: На стадии проверки
**		Нормы:
*/

t_stack  *ft_create_stack(const int *buff, int count)
{
	int i;
	t_stack	*new_list;
	t_stack *first_element;

	i = 0;
	new_list = (t_stack *)malloc(sizeof(t_stack));
	first_element = new_list;
	while (i < count)
	{
		new_list->next = (t_stack *)malloc(sizeof(t_stack));
		new_list->data = buff[i];
		if (i == (count - 1))
			new_list->next = NULL;
		else
			new_list = new_list->next;
		i++;
	}
	printf("\n   -*-*-* INIT *-*-*- \n");
	return (first_element);
}
