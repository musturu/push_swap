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
		next_targ = find_target(*stacks, next->content);
		rotate_to_list(stacks, next, next_targ);
		pb(stacks);
	}
	while ((stacks->b.head->content) != stacks->highest)
	{
		rb(stacks);
	}
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
	curtarget = find_target(stacks, current->content);
	cost = calculate_cost(stacks, current, curtarget);
	ret = current;
	while (current)
	{
		tmp = calculate_cost(stacks, current, curtarget);
		if (tmp < cost)
		{
			cost = tmp;
			ret = current;
		}
		current = current->next;
		if (current)
			curtarget = find_target(stacks, current->content);
	}
	return (ret);
}

static	t_list	*big_target(t_push stacks)
{
	t_list	*ret;
	int		compare;
	t_list	*iter;

	compare = -1232131;  //max_int
	ret = NULL;
	iter = stacks.b.head;
	while (iter)
	{
		if (iter->content > compare)
		{
			compare = iter->content;
			ret = iter;
		}
		iter = iter->next;
	}
	return (ret);
}

static t_list	*small_target(t_push stacks, int target)
{
	t_list	*ret;
	int		compare;
	t_list	*iter;

	compare = -1232131;  //min_int
	ret = NULL;
	iter = stacks.b.head;
	while (iter)
	{
		if (iter->content > compare && iter->content < target)
		{
			compare = iter->content;
			ret = iter;
		}
		iter = iter->next;
	}
	return (ret);
}

static t_list	*find_target(t_push stacks, int target)
{
	t_list	*ret;

		ret = small_target(stacks, target);
	if (ret == NULL)
		ret = big_target(stacks);
	return (ret);
}
