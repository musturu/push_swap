#include "push_swap.h"
#include <limits.h>

static t_list	*next_move(t_push stacks);
static t_list	*find_target(t_push stacks, int target);

void	solve(t_push *s)
{
	t_list		*next;
	t_list		*next_targ;
	int			last_flag;

	while (s->a.head != NULL)
	{
		next = next_move(*s);
		next_targ = find_target(*s, next->content);
		rotate_to_list(s, next, next_targ);
		pb(s, 1);
	}
	next = find_list_by_value(s->b.head, s->highest);
	last_flag = find_corresponding_index(s->b.head, next) > s->b.size / 2;
	while ((s->b.head->content) != s->highest)
	{
		if (last_flag)
			rrb(s, 1);
		else
			rb(s, 1);
	}
	while (s->b.head != NULL)
		pa(s, 1);
}

static t_list	*next_move(t_push s)
{
	t_list	*lists[3];
	int		i[3];

	i[2] = 0;
	lists[0] = s.a.head;
	i[0] = INT_MAX;
	while (lists[0] && ++i[2])
	{
		if (i[0] == 0 || i[0] == 1)
			return (lists[2]);
		if (!((i[2] < s.a.size / 2 && i[0] < i[2])
			|| ( i[2] > s.a.size / 2 && i[0] < s.a.size - i[2])))
		{
			lists[1] = find_target(s, lists[0]->content);
			i[1] = calculate_cost(s, lists[0], lists[1]);
			if (i[1] < i[0])
			{
				i[0] = i[1];
				lists[2] = lists[0];
			}
		}
		lists[0] = lists[0]->next;
	}
	return (lists[2]);
}

static	t_list	*big_target(t_push stacks)
{
	t_list	*ret;
	int		compare;
	t_list	*iter;

	compare = INT_MIN;
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

	compare = INT_MIN;
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
