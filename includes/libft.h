/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:30:37 by doberyn           #+#    #+#             */
/*   Updated: 2019/04/20 00:15:06 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "push_swap.h"
#define MAXINT 2147483647
#define MININT -2147483648

int		ft_atoi(const char *str);
int		*ft_intcpy(int *dst, const int *src, int count);
void	ft_error();
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
char			**ft_strsplit(char const *s, int word);
void		ft_rewriting(char const *s, char **mass);
int		ft_wordmalloc(char const *s, char **mass);
int		ft_countword(char const *s);

#endif