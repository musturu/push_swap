#include "push_swap.h"

int	highest(t_list *stack);
int	is_sorted(t_list *list);

int main(int argc, char **argv)
{
	t_push stacks;

	if (validate(argc, argv) == 0)
		return (write(2, "Error\n", 6));
	if (get_stack(&stacks, argc, argv) == 0)
		free_quit(stacks, 1);
	if (check_duplicates(stacks.a) == 0)
		 free_quit(stacks, 0);
	stacks.highest = highest(stacks.a.head);
	tiny_solver(&stacks);
	print_both(stacks);
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

int	is_sorted(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->next && tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
