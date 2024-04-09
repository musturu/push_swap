#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		printf("current: [%p]  next: [%p] value : %d \n", tmp, tmp->next, *(int *)(tmp->content));
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
	printf("\n???%p\n", stacks.a.head);
	print_stack(stacks.a.head);
	printf("\n???%p\n", stacks.a.head);
	sa(&stacks);
	print_stack(stacks.a.head);
	printf("\n???%p\n", stacks.a.head);
    // solve
    // exit
}
