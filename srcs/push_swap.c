#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_push stacks;

    printf("%i\n ", validate(argc, argv));
    if (validate(argc, argv) == 0)
        return (0);
    get_stack(&stacks, argc, argv);
    // get_stack
    // check_duplicates
    // solve
    // exit
}
