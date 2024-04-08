#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_push	stacks;

    printf("%i\n ", validate(argc, argv));
    if (validate(argc, argv) == 0)
		return (0);
	get_stack(&stacks, argc, argv);
	if (check_duplicates(stacks.a) == 0)
		return (printf("no duplicati\n"));
    // solve
    // exit
}
