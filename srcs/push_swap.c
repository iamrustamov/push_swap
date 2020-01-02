/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 23:34:19 by doberyn           #+#    #+#             */
/*   Updated: 2020/01/02 23:34:20 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**		rrr: rrа и rrb одновременно.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	ft_rrr(t_stacks *s)
{
	ft_rra(&s->a, 0);
	ft_rrb(&s->b, 0);
	write(1, "rrr\n", 4);
}

int		main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;

	new = (t_data *)malloc(sizeof(t_data));
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	new->count_element = 0;
	stacks->a = NULL;
	stacks->b = NULL;
	ft_validation(argc, argv);
	ft_array_separation(argc, argv, new);
	ft_duplicate_check(new, stacks);
	ft_init_stack(new, stacks);
	free(new);
	free(stacks);
	return (0);
}
