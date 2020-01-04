#include "includes/push_swap.h"

void    ft_print_stacks(t_stacks *s)
{
	t_stack     *a;
	t_stack     *b;

	a = s->a;
	b = s->b;
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

void	readin1(char *line, t_stacks *s)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(s->a,0);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(s->b,0);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(s, 0);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(s, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(s, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(&s->a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(&s->b,0);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(s, 0);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(&s->a,0);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(&s->b,0);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(s, 0);
	else
		ft_error();
}

void	readin(t_stacks *s)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		readin1(line,s);
		//ft_print_stacks(s);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}
int		ft_stack_sorted(t_stacks *s)
{
	int i;
	int buff;
	t_stack *save;

	i = 0;
	save = s->a;
	while (i < (s->count_a - 1))
	{
		buff = s->a->data;
		s->a = s->a->next;
		if (buff > s->a->data)
		{
			s->a = save;
			return (1);
		}
		i++;
	}
	s->a = save;
	return (0);
}
/*

int		main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;

	if (argc < 2)
		exit(0);
	new = (t_data *)malloc(sizeof(t_data));
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	new->count_element = 0;
	stacks->a = NULL;
	stacks->b = NULL;
	if (ft_validation(argc, argv))
	{
		ft_array_separation(argc, argv, new);
		ft_duplicate_check(new, stacks);
		ft_init_stack(new, stacks);
		readin(stacks);
		//printf("cound_a:%d\ncoudn_b:%d\nresult sort:%d",stacks->count_a,stacks->count_b,ft_stack_sorted(stacks));
		if ((stacks->count_a == 1 || !(ft_stack_sorted(stacks))) && stacks->count_b == 0)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		*/
/*if ((check_ok(p) == 1 || p->s_a == 0) && p->s_b < 0)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");*//*

	}
	ft_free_stack(stacks);
	free(new);
	free(stacks);
	return (0);
}*/
