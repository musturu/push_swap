#include "push_swap.h"

int	highest(t_list *stack);

int	main(int argc, char **argv)
{
	t_push	stacks;

	if (validate(argc, argv) == 0)
		return (write(2, "Error\n", 6));
	get_stack(&stacks, argc, argv);
	stacks.highest = highest(stacks.a.head);
	tiny_solver(&stacks);
	free_quit(stacks, 0);
}

int	highest(t_list *stack)
{
	t_list	*cur;
	int		ret;

	cur = stack;
	ret = cur->content;
	while (cur)
	{
		if (ret < cur->content)
			ret = cur->content;
		cur = cur->next;
	}
	return (ret);
}
