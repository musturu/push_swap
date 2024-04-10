#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_list *list)
{
	t_list *tmp;
	int i;
	tmp = list;
	while (tmp)
	{
		i = *((int *)tmp->content);
		printf("current: [%p]  next: [%p] value : %d \n", tmp, tmp->next, i);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_push	stacks;

    if (validate(argc, argv) == 0)
		return (0);
	get_stack(&stacks, argc, argv);
	if (check_duplicates(stacks.a) == 0)
		return (printf("no duplicati\n"));
	print_stack(stacks.a.head);
	pb(&stacks);
	printf("\nA:\n");
	print_stack(stacks.a.head);
	printf("\nB:\n");
	print_stack(stacks.b.head);
	pa(&stacks);
	printf("\nA:\n");
	print_stack(stacks.a.head);
	printf("\nB:\n");
	print_stack(stacks.b.head);
    // solve
    // exit
}
