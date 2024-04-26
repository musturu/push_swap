#include "push_swap.h"

static t_list	*next_move(t_push stacks);
static t_list	*find_target(t_push stacks, int target);

void	solve(t_push *stacks)
{
	t_list		*next;
	t_list		*next_targ;
	int			last_flag;

	while (stacks->a.head != NULL)
	{
		next = next_move(*stacks);
		next_targ = find_target(*stacks, next->content);
		rotate_to_list(stacks, next, next_targ);
		pb(stacks, 1);
	}
	next = find_list_by_value(stacks->b.head, stacks->highest);
	last_flag = find_corresponding_index(stacks->b.head, next) > stacks->b.size / 2;
	while ((stacks->b.head->content) != stacks->highest)
	{
		if (last_flag)
			rrb(stacks, 1);
		else
			rb(stacks, 1);
	}
	while (stacks->b.head != NULL)
		pa(stacks, 1);
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
