#include "push_swap.h"

static void split_stack(t_push *stack, char **argv);
static void    append_list(char **argv, t_list **list, int i);

void    get_stack(t_push *stack, int argc, char **argv)
{
    int headcont;
    int i;

    i = 1;
    if (argc == 2)
        return (split_stack(stack, argv));
    headcont = ft_atoi(argv[1]);
    stack->a.head = ft_lstnew(&headcont);
    while (i < argc)
    {
        append_list(argv, &(stack->a.head), i);
        i++;
    }
}

static void    append_list(char **argv, t_list **list, int i)
{
    int content;
    t_list *new;

    content = ft_atoi(argv[i]);
    new = ft_lstnew(&content);
    ft_lstadd_back(list, new);
}

static void split_stack(t_push *stack, char **argv)
{
    char    **split;
    int     size;

    split = ft_split(argv[1], ' ');
    size = 0;
    while (split[size])
        size++;
    get_stack(stack, size, split);
    while (--size != -1)
        free(split[size]);
    free(split);
}
