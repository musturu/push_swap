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
	cost = calculate_cost(stacks, current);
	while (current)
	{
		tmp = calculate_cost(stacks, current);
		if (tmp < cost)
		{
			cost = tmp;
			ret = current;
		}
		current = current->next;
	}
	return (ret);
}


static void		rotate_to_list(t_push *stacks, t_list *a, t_list *b)
{
	return ;
}


static int		calculate_cost(t_push stacks, t_list *current)
{
	int		i[2];
	int		cost;
	t_list	*target;

	i[0] = 0;
	i[1] = 0;
	target = find_target(stacks, *(int *)current->content);
	i[0] = find_corresponding_index(stacks.a.head, current);
	i[1] = find_corresponding_index(stacks.b.head, target);
	cost = check_shortest(i[0], i[1], stacks.a.size, stacks.b.size);
	return (cost);
}

static int	check_shortest(int ia, int ib, int asize, int bsize)
{
	int	ret;

	ret = 0;
	if (ia > asize / 2)
		ia = asize - ia;
	if (ib > bsize / 2)
		ib = bsize - ib;
	ret = ib + ia;
}

static int	find_corresponding_index(t_list *head, t_list *target)
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
	while (*(int *)(iter->content))
		iter = iter->next;
}