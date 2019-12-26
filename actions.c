/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:43:33 by doberyn           #+#    #+#             */
/*   Updated: 2019/12/22 14:43:37 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**		sa: swap a - поменяйте местами первые 2 элемента в
**		верхней части стека  a.  Ничего не делать, если есть
**		только один или нет элементов).
**		Состояние: Работает ✓
**		Нормы: ✓
*/

void 	ft_sa(t_stack *a)
{
  int		buff;

  if (a == NULL || a->next == NULL)
	return ;
  printf("\n  -*-*-* SA *-*-*- \n");
  buff = a->data;
  a->data = a->next->data;
  a->next->data = buff;
}

/*
**		sb: swap b - поменять первые 2 элемента в
**		верхней части стека  b. Ничего не делать, если есть
**		только один или нет элементов).
**		Состояние: Работает ✓
**		Нормы: ✓
*/

void 	ft_sb(t_stack *b)
{
  int		buff;

  if (b == NULL || b->next == NULL)
	return ;
  printf("\n-*-*-* SB *-*-*- \n");
  buff = b->data;
  b->data = b->next->data;
  b->next->data = buff;
}

/*
**		ss: sa и sb одновременно.
**		Состояние: Работает ✓
**		Нормы: ✓
*/

void  ft_ss(t_stacks *s)
{
	printf("\n\t-*-*-* SS *-*-*- \n");
	ft_sa(s->a);
	ft_print_stack(s);
	ft_sb(s->b);
	ft_print_stack(s);
}

/*
**		pa: push a - возьмите первый элемент вверху
**		b и поместите его вверху  a. Ничего не делать,
**		если b пусто.
**		Состояние: Работает ✓
**		Нормы: ✓
*/

void	ft_pa(t_stacks *s)
{
	t_stack     *buff;

	if (s->b == NULL)
		return ;
	s->count_a += 1;
	s->count_b -= 1;
	printf("\n\t-*-*-* PA *-*-*- \n");
	buff = s->b;
	s->b = s->b->next;
	buff->next = s->a;
	s->a = buff;
}

/*
**		pb: push b - возьмите первый элемент в верхней части
**		a и поместите его в верхней части  b.
**		Ничего не делать, если  a пусто.
**		Состояние: Работает ✓
**		Нормы: ✓
*/

void	ft_pb(t_stacks *s)
{
	t_stack     *buff;

	if (s->a == NULL)
		return ;
	printf("\n\t-*-*-* PB *-*-*- \n");
	s->count_a -= 1;
	s->count_b += 1;
	buff = s->a;
	s->a = s->a->next;
	buff->next = s->b;
	s->b = buff;
}

/*
**		ra: rotate a -  сдвинуть вверх все элементы стека  a  на 1.
**		Верхний элемент отправляется вниз.
**		Состояние: Работает ✓
**		Нормы: ✓
*/

void ft_ra(t_stack **a)
{
	t_stack		*first_list;
	t_stack		*rotate_list;
	t_stack		*last_list;

	printf("\n  -*-*-* RA *-*-*- \n");
	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	rotate_list = *a;
	first_list = (*a)->next;
	last_list = *a;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*a = first_list;
}

/*
**		rb: rotate b -  сдвинуть вверх все элементы стека  b  на 1.
**		Верхний элемент отправляется вниз.
**		Состояние: -
**		Нормы: -
*/

void ft_rb(t_stack **b)
{
	t_stack		*first_list;
	t_stack		*rotate_list;
	t_stack		*last_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	printf("\n  -*-*-* RB *-*-*- \n");
	rotate_list = *b;
	first_list = (*b)->next;
	last_list = *b;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*b = first_list;
}

/*
**		rr: ra и rb одновременно.
**		Состояние: -
**		Нормы: -
*/

void  ft_rr(t_stacks *s)
{
	printf("\n\t-*-*-* RR *-*-*- \n");
	ft_ra(&s->a);
	ft_print_stack(s);
	ft_rb(&s->b);
	ft_print_stack(s);
}

/*
**		rra: reverse rotate a -  сдвинуть вниз все элементы стека  a на 1.
**		Нижний элемент отправляется наверх.
**		Состояние: -
**		Нормы: -
*/

void ft_rra(t_stack **a)
{
	t_stack		*first_list;
	t_stack		*rotate_list;
	t_stack		*penultimate_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	first_list = *a;
	penultimate_list = *a;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	*a = rotate_list;
	printf("\n  -*-*-* RRA *-*-*- \n");
}


/*
**		rrb: reverse rotate b -  сдвинуть вниз все элементы стека  b на 1.
**		Нижний элемент отправляется наверх.
**		Состояние: -
**		Нормы: -
*/

void ft_rrb(t_stack **b)
{
	t_stack		*first_list;
	t_stack		*rotate_list;
	t_stack		*penultimate_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	first_list = *b;
	penultimate_list = *b;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	*b = rotate_list;
	printf("\n  -*-*-* RRB *-*-*- \n");
}

/*
**		rrr: rrа и rrb одновременно.
**		Состояние: -
**		Нормы: -
*/

void  ft_rrr(t_stacks *s)
{
	printf("\n\t-*-*-* RRR *-*-*- \n");
	ft_rra(&s->a);
	ft_print_stack(s);
	ft_rrb(&s->b);
	ft_print_stack(s);
}