#include "push_swap.h"

void	sa(t_push *stacks, int writeflag)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	if (stacks->a.head && stacks->a.head->next)
	{
		a = stacks->a.head;
		b = a->next;
		c = b->next;
		a->next = c;
		b->next = a;
		stacks->a.head = b;
		if (writeflag)
			write(1, "sa\n", 3);
	}
}

void	sb(t_push *stacks, int writeflag)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	if (stacks->b.head && stacks->b.head->next)
	{
		a = stacks->b.head;
		b = stacks->b.head->next;
		c = stacks->b.head->next->next;
		a->next = c;
		b->next = a;
		stacks->b.head = b;
		if (writeflag)
			write(1, "sb\n", 3);
	}
}

void	ss(t_push *stacks, int flag)
{
	sa(stacks, 0);
	sb(stacks, 0);
	if (flag)
		write(1, "ss\n", 3);
}

void	pa(t_push *stacks, int flag)
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
		stacks->a.size++;
		stacks->b.size--;
		if (flag)
			write(1, "pa\n", 3);
	}
}

void	pb(t_push *stacks, int flag)
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
		stacks->a.size--;
		stacks->b.size++;
		if (flag)
			write(1, "pb\n", 3);
	}
}
