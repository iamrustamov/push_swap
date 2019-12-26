/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:18:13 by doberyn           #+#    #+#             */
/*   Updated: 2019/12/22 15:18:15 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**		ft_array_separation - Разбиваем получаемую
**		строку на массив чисел.
**		Состояние: На стадии проверки
**		Нормы: ✓
*/

void	ft_array_separation(int argc, char **argv, t_data *new)
{
	int i;
	char **mass;
	int count_element;
	int *buff;
	i = 1;
	int p;

	while (i < argc)
	{
		p = -1;
		count_element = ft_countword(argv[i]);
		mass = ft_strsplit(argv[i], count_element);
		buff = (int *)malloc(sizeof(int) * (count_element));
		while (count_element > ++p)
		{
			buff[p] = ft_atoi(mass[p]);
			free(mass[p]);
		}
		free(mass);
		ft_stacking(new,buff,count_element);
		i++;
	}
}

/*
**		ft_stacking - В данной фунции мы переписываем
**		данные из buff в new->а(массив int в структуре t_data)
**		определенное кол-во раз(count).
**		Состояние: На стадии проверки
**		Нормы: ✓
*/

void	ft_stacking(t_data *new, int *buff, int count)
{
	int i;

	i = -1;
	while (count > ++i)
		new->a[new->count_element + i] = buff[i];
	new->count_element += count;
	free(buff);
}
