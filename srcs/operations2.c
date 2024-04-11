#include "push_swap.h"

static void	rotate(t_list *list);

void	ra(t_push *stacks)
{
	rotate(stacks->a.head);
	write(1, "ra\n", 3);
}

void	rb(t_push *stacks)
{
	rotate(stacks->b.head);
	write(1, "rb\n", 3);
}

void	rr(t_push *stacks)
{
	rotate(stacks->b.head);
	rotate(stacks->a.head);
	write(1, "rr\n", 3);
}

static void	rotate(t_list *list)
{
	t_list *current;
	t_list *last;

	current = list;
	while(current->next->next != NULL)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = list;
	list = last;
}
