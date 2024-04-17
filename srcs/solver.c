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
		printf("value to push:%i || index : %i\n", next->content, find_corresponding_index(stacks->a.head, next));
		next_targ = find_target(*stacks, next->content);
		if (next_targ != NULL)
			printf("TARGET: value to push:%i || TARGET: index : %i\n", next_targ->content, find_corresponding_index(stacks->b.head, next_targ));
		rotate_to_list(stacks, next, next_targ);
		pb(stacks);
	}
	printf("AJOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
	print_both(*stacks);
	while ((stacks->b.head->content) != stacks->highest)
		rb(stacks);
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

static t_list	*find_target(t_push stacks, int target)
{

}