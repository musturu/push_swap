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
	//print_stack(stacks->a.head);
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
	sa(stacks);
}

void	pb(t_push *stacks)
{
	sa(stacks);
}
