#include "push_swap.h"

int	find_corresponding_index(t_list *head, t_list *target)
{
	int		i;
	t_list	*iter;

	i = 0;
	iter = head;
	while (iter != target)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}