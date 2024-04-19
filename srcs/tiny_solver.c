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

static int	find_lowest(t_list *list)
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

static int	find_second_lowest(t_list *list, int lowest)
{
	t_list	*tmp;
	int		ret;

	tmp = list;
	if (tmp->content != lowest)
		ret = tmp->content;
	else
		ret = tmp->next->content;
	while(tmp)
	{
		if (ret > tmp->content && tmp->content != lowest)
			ret = tmp->content;
		tmp = tmp->next;
	}
	return (ret);
}

static void	push_high(t_push *stacks)
{
	int		second;
	int		low;
	t_list	*highlist;
	t_list	*lowlist;
	int		i;

	low = find_lowest(stacks->a.head);
	second = find_second_lowest(stacks->a.head, low);
	highlist = find_list_by_value(stacks->a.head, low);
	lowlist = find_list_by_value(stacks->a.head, second);
	while (stacks->a.size != 3)
	{
		i = find_corresponding_index(stacks->a.head, highlist);
		if (!find_list_by_value(stacks->a.head, low))
			i = find_corresponding_index(stacks->a.head, lowlist);
		if (stacks->a.head->content == low)
		{
			pb(stacks);
		}
		if (stacks->a.head->content == second && (stacks->a.size + stacks->b.size == 5))
			pb(stacks);
		if (i * 2 > stacks->a.size)
			rra(stacks);
		else
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
	print_both(*stacks);
}
