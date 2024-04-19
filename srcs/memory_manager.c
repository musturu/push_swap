#include "push_swap.h"
#include <stdlib.h>

void	free_quit(t_push stacks)
{
	t_list	*tmp;
	t_list	*to_free;

	tmp = stacks.a.head;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
	}
	
	if (stacks.b.head)
		tmp = stacks.b.head;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
	}
	exit(0);
}
