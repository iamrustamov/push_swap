#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXINT 2147483647
#define MININT -2147483648

typedef struct			s_data
{
	int					a[10000];
	int					b[10000];
	int					point_a;
}						t_data;

//__________________________StrSplit

static int		ft_countword(char const *s)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			count++;
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}

static int		ft_wordmalloc(char const *s, char **mass)
{
	int lenword;
	int i;

	i = 0;
	while (*s)
	{
		lenword = 0;
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
			{
				s++;
				lenword++;
			}
			if (!(mass[i++] = ((char *)malloc(sizeof(char) * (lenword + 1)))))
				return (i);
		}
		else
			s++;
	}
	return (0);
}

static void		ft_rewriting(char const *s, char **mass)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				mass[i][j++] = *s++;
			mass[i++][j] = '\0';
		}
		j = 0;
		if (*s != '\0')
			s++;
	}
}

char			**ft_strsplit(char const *s, int word)
{
	char	**mass;
	int		res;

	if (!s)
		return (NULL);
	if (!(mass = (char **)malloc(sizeof(char *) * (word + 1))))
		return (0);
	mass[word] = NULL;
	res = ft_wordmalloc(s, mass);
	if (res == 0)
		ft_rewriting(s, mass);
	else
	{
		while (res != 0)
		{
			free(mass[res]);
			mass[res--] = NULL;
		}
		free(mass);
	}
	return ((char **)mass);
}

//__________________________StrSplit

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putstr(char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        ++str;
    }
}

void	ft_putnbr(int n)
{
    if (n == -2147483648)
        ft_putstr("-2147483648");
    else
    {
        if (n < 0)
        {
            ft_putchar('-');
            n = -n;
        }
        if (n > 9)
        {
            ft_putnbr(n / 10);
        }
        ft_putchar((n % 10) + '0');
    }
}

void	ft_error()
{
	write(2, "Error!", 6);
	exit(1);
}
/*
** ft_valid_str - Проверяем строку на валидность.
** Все ли правильно записанно и нет ли лишних символов
** в строке. Нам требуются только числа которые могут
** быть разделенны пробелами и табами. Числа могут иметь
** положительный или отрицательные знаки.
*/

void		ft_valid_str(char *str)
{
	int i;
	int nbr;
	int sign;

	sign = 0;
	nbr = 0;
	i = 0;
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
		else if (((str[i] == '+' || str[i] == '-') && (sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

/*
** ft_number_availability - Проверяем строку на наличие цифр,
** тем самым обрабатываем навалидные строки.
** Например: строки содержащие только пробелы
** и табы и строки состоящие только из '+' или '-'.
*/

int		ft_number_availability(const char *str)
{
	int i;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
            return (1);
        i++;
    }
    ft_error();
	return (0);
}

//  "0-0924" 959 "59"
void ft_validate(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_number_availability(argv[i]);
		ft_valid_str(argv[i]);
		i++;
	}
}

/*
** ft_array_separation - В данной фунции мы будем
** разбивать строки(строку) на массив чисел.
** Будут использованы функции которые я написал
** во время провекта libft.
*/

void	ft_stacking(t_data *new,int *buff,int count)
{
	int i;

	i = -1;
	while (count > ++i)
		new->a[new->point_a + i] = buff[i];
	new->point_a += count;
	free(buff);
}


int		ft_atoi(const char *str)
{
	int		sign;
	int		dig;
	long	res;

	sign = 1;
	dig = 0;
	res = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v'
		|| *str == ' ' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		res = res * 10 + (*str - '0');
		dig++;
		if (dig > 10 || (res * sign) > MAXINT || (res * sign) < MININT)
			ft_error();
		str++;
	}
	return (res * sign);
}


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

int ft_partition(int *array, int start, int end)
{
	int pivot;
	int i;
	int temp;
	int j;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	return i + 1;
}

void ft_quick_sort(int *array, int start, int end)
{
	int q;


	if (start < end)
	{
		q =  ft_partition(array, start, end);
		ft_quick_sort(array, start, q - 1);
		ft_quick_sort(array, q + 1, end);
	}
}

int	*ft_intcpy(int *dst, const int *src, int count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void ft_search_duplicate(int *dup, int count)
{
	int i;

	i = 0;
 while(i != count)
	{
		if (dup[i] == dup[i + 1])
			ft_error();
		i++;
	}
	free(dup);
}

void	ft_duplicate_check(t_data *new)
{
	int 	*dup;

	dup = (int *)malloc(sizeof(int) * (new->point_a));
	dup = ft_intcpy(dup, new->a, new->point_a);
	ft_quick_sort(dup,0,new->point_a - 1);
	ft_search_duplicate(dup, new->point_a - 1);
}

int		main(int argc, char **argv)
{
	int i;
	t_data new;

	new.point_a = 0;
	i = 1;
	/*while (i < argc)
	{
		ft_putstr("argv[");
		ft_putnbr(i);
		ft_putstr("] : ");
		ft_putstr(argv[i]);
		i++;
		ft_putchar('\n');
	}*/
	ft_validate(argc, argv);
	ft_array_separation(argc, argv, &new);
	ft_duplicate_check(&new);
	int j = 0;
	while (j < new.point_a)
	{
		printf("[%d] [%d]\n",new.a[j],new.b[j]);
		j++;
	}
	printf(" A   B");
	return (0);
}