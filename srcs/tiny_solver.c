#include "push_swap.h"
#include <limits.h>

static void	solve_three(t_push *stacks);
static void	solve_five(t_push *stacks);

void	tiny_solver(t_push *stacks)
{
	if (stacks->a.size == 3)
		return (solve_three(stacks));
	else if (stacks->a.size > 3 && stacks->a.size < 6)
		return (solve_five(stacks));
	else
		return (solve(stacks));
}

static void	solve_three(t_push *stacks)
{
	int high;

	high = highest(stacks->a.head);
	if (is_sorted(stacks->a.head))
		return ;
	if (stacks->a.head->content == high)
		ra(stacks);
	if (stacks->a.head->next->content == high)
		rra(stacks);
	if (stacks->a.head->content > stacks->a.head->next->content)
		sa(stacks, 1);
}

static int	find_second_lowest(t_list	*list, int highest)
{
	t_list	*tmp;
	int	ret;
	int		compare;

	compare = INT_MIN;
	tmp = list;
	while (tmp)
	{
		if (tmp->content > compare && tmp->content != highest)
		{
			compare = tmp->content;
			ret = tmp->content;
		}
		tmp = tmp->next;
	}
	return (ret);
}

static void	push_high(t_push *stacks)
{
	int     second;

	second = find_second_lowest(stacks->a.head, stacks->highest);
	while (stacks->a.size != 3)
	{
		if (stacks->a.head->content == stacks->highest)
			pb(stacks);
		if (stacks->a.head->content == second && (stacks->a.size + stacks->b.size == 5))
			pb(stacks);
		ra(stacks);
	}
}

static void	solve_five(t_push *stacks)
{
	push_high(stacks);
	if (stacks->b.head->next && stacks->b.head->content < stacks->b.head->next->content)
		sb(stacks, 1);
	solve_three(stacks);
	pa(stacks);
	pa(stacks);
	ra(stacks);
	ra(stacks);
}
