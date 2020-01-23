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
# define MAXINT 2147483647
# define MININT -2147483648
# define BUFF_SIZE 32
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **line);
int		ft_atoi(const char *str);
int		*ft_intcpy(int *dst, const int *src, int count);
void	ft_error(void);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
char	**ft_strsplit(char const *s, int word);
void	ft_rewriting(char const *s, char **mass);
int		ft_wordmalloc(char const *s, char **mass);
int		ft_countword(char const *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	ft_strdel(char **as);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

#endif
