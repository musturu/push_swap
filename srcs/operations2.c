#include "push_swap.h"

void	ra(t_push stacks)
{
	t_list *current;
	t_list *last;

	current = stacks.a.head;
	while(current->next->next != NULL)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = stacks.a.head;
	stacks.a.head = last;
}

void	rb(t_push stacks)
{

}

void	rr(t_push stacks)
{

}

