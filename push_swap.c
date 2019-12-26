#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"




/*

void 	ft_sb(t_stack_a *first)
{
	int		buff;

	buff = first->data;
	first->data = first->next->data;
	first->next->data = buff;
}*/


//pb: push b - возьмите первый элемент вверху  a и поместите его вверху  b.
//Ничего не делать, если  b пусто.




void    ft_print_stack(t_stacks *s)
{
    t_stack     *a;
    t_stack     *b;

    a = s->a;
    b = s->b;
    printf("\t   Начало\n\t\t  ↓");
    printf("\nSTACK A: ");
    while (s->a) {
        printf("[%d] ", s->a->data);
        s->a = s->a->next;
    }
    printf("\nSTACK B: ");
    if (s->b != NULL)
    {
        while (s->b)
        {
            printf("[%d] ", s->b->data);
            s->b = s->b->next;
        }
    }
    printf("\n\n");
    s->a = a;
    s->b = b;
}

int		main(int argc, char **argv)
{
	t_data new;
	t_stacks staks;

	new.count_element = 0;
	ft_validate(argc, argv);
	ft_array_separation(argc, argv, &new);
	ft_duplicate_check(&new, &staks);
	ft_init_stack(&new,&staks);

	return (0);
}