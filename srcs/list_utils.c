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

t_list	*find_list_by_value(t_list	*head, int	value)
{
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->content == value)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
