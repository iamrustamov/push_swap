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
		buff->rotate = 1;
		buff = buff->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->rotate = -1;
		buff = buff->next;
	}
}

void kuda_kogo(t_steps *steps,int a,int c_a,int b, int c_b)
{

}

int	idti_dalshe(t_stack *a,int buff,int src)
{
	t_stack *save;
	int ret;

	ret = 0;
	save = a;
	while (a && ret == 0)
	{
		if (a->data < buff && a->data > src)
			ret = 1;
		a = a->next;
	}
	a = save;
	return (ret);
}

int	poisk_svoego_mesta(t_stacks *s, t_stack *b, t_steps *steps,int min)
{
	int action;
	int res;

	int buff;
	buff = 0;
	action = 0;
	/*while (s->a)
	{
		if (s->a->data < b->data)
		{
			buff = s->a->data;
			s->a = s->a->next;
			break;
		}
		else
			s->a = s->a->next;
	}
	while (s->a) {
		if (s->a->data > buff && s->a->data < b->data) {
			buff = s->a->data;
			pos++;
		}
		else
			s->a = s->a->next;
	}
	s->a = first_a;*/
	while (s->a) {
		buff = s->a->data;
		if (b->data > s->a->data) {
			action++;
			if (b->data < s->a->next->data)
				break;
			s->a = s->a->next;
		}
		else {
			break;
		}
	}
	if (idti_dalshe(s->a, buff, b->data) == 1)
	{
		while (s->a) {
			if (s->a->data < buff && s->a->data > b->data)
				break;
			action++;
			s->a = s->a->next;
		}
	}
	//action += b->step;
	//if (action > ((s->count_a - 1) / 2))
	//{
	//	action = s->count_a - action;
	//	steps->dest_a = -1;
	//}
	//else
	//	return min;
	if (s->a->rotate == -1)
		action = s->count_a - action;
	if (min == -1 || (action + b->step) < min)
	{
		steps->dest_a = s->a->rotate;
		steps->dest_b = b->rotate;
		steps->count_a = action;
		steps->count_b = b->step;
		res = action + b->step;
	}
	else
		res = min;
	return (res);
}

void ft_search(t_stacks *s,t_steps *steps)
{
	int min_action;
	int i;
	t_stack *first_b;
	t_stack *first_a;

	min_action = -1;
	first_b = s->b;
	first_a = s->a;
	while (s->b)
	{
		min_action = poisk_svoego_mesta(s,s->b,steps,min_action);
		s->a = first_a;
		s->b = s->b->next;
	}
	//s->a = first_a;
	s->b = first_b;
}

void instrukciya(t_stacks *s,t_steps *steps)
{
	while (steps->count_a > 0)
	{
		if (steps->dest_a == 1)
			ft_ra(&s->a);
		else
			ft_rra(&s->a);
		steps->count_a--;
	}
	while (steps->count_b > 0)
	{
		if (steps->dest_b == 1)
			ft_rb(&s->b);
		else
			ft_rrb(&s->b);
		steps->count_b--;
	}
	ft_pa(s);
}

void		ft_napravlenie(t_stacks *s,t_steps *step)
{
	if (step->count_a > ((s->count_a - 1) / 2))
		step->dest_a = -1;
	else
		step->dest_a = 1;
	if (step->count_b > ((s->count_b - 1)/ 2))
		step->dest_b = -1;
	else
		step->dest_b = 1;
}

void	ft_start_sort(t_stacks *s)
{
	t_steps step;

	while (s->count_b != 0)
	{
		step.count_b = -1;
		step.count_a = -1;
		step.dest_a = 0;
		step.dest_b = 0;
		ft_steps_markup(s->b, s->count_b);
		ft_steps_markup(s->a, s->count_a);
		ft_search(s ,&step);
		//ft_napravlenie(s, &step);
		instrukciya(s,&step);
		ft_print_stack(s);
	}
	while (s->a->data != s->min)
		ft_ra(&s->a);
	ft_print_stack(s);
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
		}
		else
			ft_ra(&stacks->a);
	}
	if (stacks->a->data < stacks->a->next->data)
		ft_sa(stacks->a);
	ft_pa(stacks);
	ft_print_stack(stacks);
	ft_start_sort(stacks);
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
	//printf("\n   -*-*-* INIT *-*-*- \n");
	return (first_element);
}
