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

int	is_sorted(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->next && tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	find_lowest(t_list *list)
{
	t_list	*tmp;
	int		ret;

	tmp = list;
	ret = tmp->content;
	while(tmp)
	{
		if (ret > tmp->content)
			ret = tmp->content;
		tmp = tmp->next;
	}
	return (ret);
}
