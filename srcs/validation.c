/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:43:19 by doberyn           #+#    #+#             */
/*   Updated: 2019/12/22 14:43:21 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**		ft_validation - функция, которая принимает введенные пользователем
** 		данные и проверяет их, отправляя данные в другие функции.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	ft_validation(int argc, char **argv)
{
	size_t	i;

	i = 1;
	while (i < argc)
	{
		ft_number_availability(argv[i]);
		ft_valid_str(argv[i]);
		i++;
	}
}

/*
**		ft_number_availability - Проверяем строку на наличие цифр,
**		тем самым обрабатываем навалидные строки.
**		Например: строки содержащие только пробелы
**		и табы и строки состоящие только из '+' или '-'.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	ft_number_availability(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	ft_error();
}

/*
**		ft_valid_str - Проверяем строку на валидность.
**		Все ли правильно записанно и нет ли лишних символов
**		в строке. Нам требуются только числа которые могут
**		быть разделенны пробелами и табами. Числа могут иметь
**		положительный или отрицательные знаки.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	ft_valid_str(const char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				ft_error();
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-') &&
				(sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

/*
**		ft_duplicate_check - Запуск процесса проверки данных
**		на наличие дубликатов.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	ft_duplicate_check(t_data *new, t_stacks *stacks)
{
	int			*dup;

	if (!(dup = (int *)malloc(sizeof(int) * (new->count_element))))
		exit(1);
	dup = ft_intcpy(dup, new->a, new->count_element);
	ft_quick_sort(dup, 0, new->count_element - 1);
	ft_search_duplicate(dup, new->count_element - 1);
	stacks->count_a = new->count_element;
	stacks->count_b = 0;
	stacks->min = dup[0];
	stacks->med = dup[new->count_element / 2];
	stacks->max = dup[new->count_element - 1];
	free(dup);
}

/*
**		ft_search_duplicate - Проверяем массив чисел на
**		наличие дубликатов.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	ft_search_duplicate(const int *dup, int count)
{
	int i;

	i = 0;
	while (i != count)
	{
		if (dup[i] == dup[i + 1])
			ft_error();
		i++;
	}
}
