#include "push_swap.h"

int	find_corresponding_index(t_list *head, t_list *target)
{
	int		i;
	t_list	*iter;

	if (head == NULL)
		return (0);
	i = 0;
	iter = head;
	while (iter != ft_lstlast(head))
	{
		if (iter == target)
			return (i);
		iter = iter->next;
		i++;
	}
	return (i);
}