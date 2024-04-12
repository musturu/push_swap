#include "push_swap.h"

static void	revrotate(t_list *list);

void	rrb(t_push *stacks)
{
	if (stacks->b.head && stacks->b.head->next)
		revrotate(stacks->b.head);
	write(1, "rrb\n", 4);
}

void	rra(t_push *stacks)
{
	if (stacks->a.head && stacks->a.head->next)
		revrotate(stacks->a.head);
	write(1, "rra\n", 4);

}

void	rrr(t_push *stacks)
{
    revrotate(stacks->a.head);
	revrotate(stacks->b.head);
	write(1, "rrr\n", 4);

}

static void	revrotate(t_list *list)
{
	t_list *current;
	t_list *last;
    t_list *first;

    first = list;
	current = list;
	while(current->next->next != NULL)
		current = current->next;
	last = current->next;
    last->next = list;
    list = list->next;
    first->next = NULL;
}
