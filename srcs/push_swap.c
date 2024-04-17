#include "push_swap.h"
#include <stdio.h>

void	highest(t_push *stack);

void print_stack(t_list *list)
{
	t_list *tmp;
	int i;
	tmp = list;
	while (tmp)
	{
		i = (tmp->content);
		printf("current: [%p]  next: [%p] value : \t%d\n ", tmp, tmp->next, i);
		tmp = tmp->next;
	}
}

void print_both(t_push stack)
{
	(void)write(1, "\na:\n", 4);
	print_stack(stack.a.head);
	(void)write(1, "\nb:\n", 4);
	print_stack(stack.b.head);
}

int main(int argc, char **argv)
{
	t_push stacks;

	if (validate(argc, argv) == 0)
		return (0);
	get_stack(&stacks, argc, argv);
	if (check_duplicates(stacks.a) == 0)
		return (printf("no duplicati\n"));
	highest(&stacks);
	solve(&stacks);
	//print_both(stacks);
	// exit
}

void	highest(t_push *stack)
{
	t_list	*cur;
	int		ret;

	cur = stack->a.head;
	ret = cur->content;
	while (cur)
	{
		if (ret < cur->content)
			ret = cur->content;
		cur = cur->next;
	}
	stack->highest = ret;
}
