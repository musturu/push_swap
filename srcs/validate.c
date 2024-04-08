#include "push_swap.h"

static int is_num(char *str);
static int  check_duplicates(t_stack stack);

int    validate(int argc, char **argv)
{
    char    **split;
    int     i;

    if (argc > 2)
    {
        while(--argc)
        {
            if (!is_num(argv[argc]))
                return (0);
        }
    }
    else
    {
        i = -1;
        split = ft_split(argv[1], ' ');
        while (split[++i])
        {
            if (!is_num(split[i]))
                return (0);
        }
        free(split);
    }
    return (1);
}

static int is_num(char *str)
{
    int i;

    i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] != 0)
        return (0);
    else
        return 1;;
}

static int  check_duplicates(t_stack stack)
{
    t_list  *current;
    t_list  *iter;

    current = stack.head;
    while (current->next != NULL)
    {
        iter = current->next;
        while (iter->next != NULL)
        {
            if (current->content == iter->content)
                return (0);
            iter = iter->next;
        }
        current = current->next;
    }
    return (1);
}
