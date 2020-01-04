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

#include "includes/push_swap.h"



int		main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;

	new = (t_data *)malloc(sizeof(t_data));
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	new->count_element = 0;
	stacks->a = NULL;
	stacks->b = NULL;
	if (ft_validation(argc, argv)) {
		ft_array_separation(argc, argv, new);
		ft_duplicate_check(new, stacks);
		if (ft_is_sorted(new))
		{
			ft_init_stack(new, stacks);
			ft_sort(stacks);
			ft_free_stack(stacks);
		}
	}
	free(new);
	free(stacks);
	return (0);
}
