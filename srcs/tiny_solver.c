#include "push_swap.h"

static void	solve_three(t_push *stacks);
static void	solve_five(t_push *stacks);

void	tiny_solver(t_push *stacks)
{
	if (is_sorted(stacks->a.head))
		return ;
	if (stacks->a.size <= 3)
		return (solve_three(stacks));
	else if (stacks->a.size > 3 && stacks->a.size < 6)
		return (solve_five(stacks));
	else
		return (solve(stacks));
}

static void	solve_three(t_push *stacks)
{
	int	high;

	high = highest(stacks->a.head);
	if (stacks->a.head->content == high)
		ra(stacks, 1);
	if (is_sorted(stacks->a.head))
		return ;
	if (stacks->a.head->next->content == high)
		rra(stacks, 1);
	if (stacks->a.head->content > stacks->a.head->next->content)
		sa(stacks, 1);
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
	while (tmp)
	{
		if (ret > tmp->content && tmp->content != lowest)
			ret = tmp->content;
		tmp = tmp->next;
	}
	return (ret);
}

static void	push_high(t_push *s)
{
	int		second;
	int		i;
	int		low;
	t_list	*highlist;
	t_list	*lowlist;

	low = find_lowest(s->a.head);
	second = find_second_lowest(s->a.head, low);
	highlist = find_list_by_value(s->a.head, low);
	lowlist = find_list_by_value(s->a.head, second);
	while (s->a.size != 3)
	{
		i = find_corresponding_index(s->a.head, highlist);
		if (!find_list_by_value(s->a.head, low))
			i = find_corresponding_index(s->a.head, lowlist);
		if (s->a.head->content == low)
			pb(s, 1);
		if (s->a.head->content == second && (s->a.size + s->b.size == 5))
			pb(s, 1);
		if (i * 2 > s->a.size)
			rra(s, 1);
		else
			ra(s, 1);
	}
}

static void	solve_five(t_push *s)
{
	push_high(s);
	if (s->b.head->next && s->b.head->content < s->b.head->next->content)
		sb(s, 1);
	solve_three(s);
	pa(s, 1);
	pa(s, 1);
}
