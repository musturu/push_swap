#include "push_swap.h"

void	sa(t_push *stacks)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	if (stacks->a.head->next)
	{
		a = stacks->a.head;
		b = a->next;
		c = b->next;
		a->next = c;
		b->next = a;
		stacks->a.head = b;
	}
	print_stack(stacks->a.head);
}

void	sb(t_push *stacks)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	if (stacks->b.head->next)
	{
		a = stacks->b.head;
		b = stacks->b.head->next;
		c = stacks->b.head->next->next;
		a->next = c;
		b->next = a;
	}
	print_stack(stacks->b.head);
}

void	ss(t_push *stacks)
{
	sa(stacks);
	sb(stacks);
}

void	pa(t_push *stacks)
{
	t_list	*bfirst;
	t_list	*afirst;

	if (stacks->b.head)
	{
		bfirst = stacks->b.head;
		afirst = stacks->a.head;
		stacks->b.head = bfirst->next;
		bfirst->next = afirst;
		stacks->a.head = bfirst;
	}
}

void	pb(t_push *stacks)
{
	t_list	*bfirst;
	t_list	*afirst;

	if (stacks->a.head)
	{
		bfirst = stacks->b.head;
		afirst = stacks->a.head;
		stacks->a.head = afirst->next;
		afirst->next = bfirst;
		stacks->b.head = afirst;
	}
}
