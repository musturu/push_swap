#include "push_swap.h"

static void	rotate(t_list **list);

void	ra(t_push *stacks, int flag)
{
	if (stacks->a.head && stacks->a.head->next)
	{
		rotate(&(stacks->a.head));
		if (flag)
			write(1, "ra\n", 3);
	}
}

void	rb(t_push *stacks, int flag)
{
	if (stacks->b.head && stacks->b.head->next)
	{
		rotate(&(stacks->b.head));
		if (flag)
			write(1, "rb\n", 3);
	}
}

void	rr(t_push *stacks, int flag)
{
	rotate(&(stacks->b.head));
	rotate(&(stacks->a.head));
	if (flag)
		write(1, "rr\n", 3);
}

static void	rotate(t_list **list)
{
	t_list	*first;
	t_list	*last;

	first = *list;
	last = ft_lstlast(*list);
	last->next = first;
	*list = first->next;
	first->next = NULL;
}
