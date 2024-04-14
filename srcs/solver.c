#include "push_swap.h"
#include <stdio.h>

static t_list	*next_move(t_push stacks);
static t_list	*find_target(t_push stacks, int target);

void	solve(t_push *stacks)
{
	t_list		*next;
	t_list		*next_targ;

	while (stacks->a.head != NULL)
	{
		next = next_move(*stacks);
		next_targ = find_target(*stacks, *(int *)next->content);
		rotate_to_list(stacks, next, next_targ);
		pb(stacks);
	}
	//rotate until B.head is smallest
	while (stacks->b.head != NULL)
		pa(stacks);
}

static t_list	*next_move(t_push stacks)
{
	t_list	*current;
	t_list	*ret;
	t_list	*curtarget;
	int		cost;
	int		tmp;

	current = stacks.a.head;
	curtarget = find_target(stacks, *(int *)current->content);
	cost = calculate_cost(stacks, current, curtarget);
	while (current)
	{
		tmp = calculate_cost(stacks, current, curtarget);
		if (tmp < cost)
		{
			cost = tmp;
			ret = current;
		}
		current = current->next;
		curtarget = find_target(stacks, *(int *)current->content);
	}
	return (ret);
}

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

static t_list	*find_target(t_push stacks, int target)
{
	t_list	*iter;

	iter = stacks.b.head;
	while (*(int *)(iter->content) > target)
		iter = iter->next;
	return (iter);
}
