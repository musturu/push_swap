#include "checker.h"

void	readloop(t_push *stacks);

int	main(int argc, char **argv)
{
	t_push	stacks;

	if (validate(argc, argv) == 0)
		return (write(2, "Error\n", 6));
	if (get_stack(&stacks, argc, argv) == 0)
		free_quit(stacks, 1);
	readloop(&stacks);
	if (is_sorted(stacks.a.head) && !stacks.b.head)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_quit(stacks, 0);
}

void	execute(char *str, t_push *stacks)
{
	if (!strncmp(str, "pa\n", 4))
		return (pa(stacks, 0));
	else if (!strncmp(str, "pb\n", 4))
		return (pb(stacks, 0));
	else if (!strncmp(str, "ra\n", 4))
		return (ra(stacks, 0));
	else if (!strncmp(str, "rb\n", 4))
		return (rb(stacks, 0));
	else if (!strncmp(str, "sa\n", 4))
		return (sa(stacks, 0));
	else if (!strncmp(str, "sb\n", 4))
		return (sb(stacks, 0));
	else if (!strncmp(str, "rra\n", 5))
		return (rra(stacks, 0));
	else if (!strncmp(str, "rrb\n", 5))
		return (rrb(stacks, 0));
	else if (!strncmp(str, "rrr\n", 5))
		return (rrr(stacks, 0));
	else if (!strncmp(str, "rr\n", 4))
		return (rr(stacks, 0));
	free(str);
	free_quit(*stacks, 1);
}

void	readloop(t_push *stacks)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		execute(tmp, stacks);
		free(tmp);
	}
}
