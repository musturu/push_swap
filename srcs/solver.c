#include "push_swap.h"

static t_list	*next_move(t_push stacks);
static t_list	*find_target(t_push stacks, int target);
static void		rotate_to_list(t_push *stacks, t_list *a, t_list *b);
static int		calculate_cost(t_push stacks, t_list *current);

void	solve(t_push *stacks)
{
	t_list *next;

	while (stacks->a.head != NULL)
	{
		next = next_move(*stacks);
		rotate_to_list(stacks, next, find_target(*stacks, *(int*)next->content));
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
	int		cost;
	int		tmp;

	current = stacks.a.head;
	cost = -1;
	while (current)
	{
		tmp = calculate_cost(stacks, current);
		current = current->next;
	}
	return (ret);
}


static void		rotate_to_list(t_push *stacks, t_list *a, t_list *b)
{

}


static int		calculate_cost(t_push stacks, t_list *current)
{
	int cost;
	int	ia;
	int	ib;
	t_list	*iter;
	t_list	*target;

	ia = 0;
	ib = 0;
	iter = stacks.a.head;
	target = find_target(stacks, *(int *)current->content);
	while (iter != current && ++ia > -900)
		iter = iter->next;
	while (iter != target && ++ib > -900)
		iter = iter->next;
	cost = check_shortest(ia, ib, stacks.a.size, stacks.b.size);
	return (cost);
}
