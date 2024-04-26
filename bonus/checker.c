
#include "checker.h"
void	readloop(t_push *stacks);

int	main(int argc, char **argv)
{
	t_push stacks;

	if (validate(argc, argv) == 0)
		return (write(2, "Error\n", 6));
	if (get_stack(&stacks, argc, argv) == 0)
		free_quit(stacks, 1);
	if (check_duplicates(stacks.a) == 0)
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
	if (strncmp(str, "pa\n", 3))
		pa(stacks);
	if (strncmp(str, "pb\n", 3))
		pb(stacks);
	if (strncmp(str, "ra\n", 3))
		ra(stacks);
	if (strncmp(str, "rb\n", 3))
		rb(stacks);
	if (strncmp(str, "sa\n", 3))
		sa(stacks, 0);
	if (strncmp(str, "sb\n", 3))
		sb(stacks, 0);
	if (strncmp(str, "rra\n", 4))
		rra(stacks);
	if (strncmp(str, "rrb\n", 4))
		rrb(stacks);
	if (strncmp(str, "rrr\n", 4))
		rrr(stacks);
	if (strncmp(str, "rr\n", 4))
		rr(stacks);
	else
	{
		free(str);
		free_quit(*stacks, 1);
	}
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
