#include "push_swap.h"

static int is_num(char *str);

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
	else if (argc == 2)
    {
        i = -1;
        split = ft_split(argv[1], ' ');
        while (split[++i])
        {
            if (!is_num(split[i]))
				return (free_mat(split));
        }
		free_mat(split);
    }
	else if (argc == 1)
		return (0);
    return (1);
}

static int is_num(char *str)
{
    int i;

    i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        i++;
        if (!str[i])
            return (0);
    }
    while(str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] != 0)
        return (0);
    else
        return 1;;
}

int  check_duplicates(t_stack stack)
{
    t_list  *current;
    t_list  *iter;

    current = stack.head;
    while (current != NULL)
    {
        iter = current->next;
        while (iter != NULL)
        {
            if (current->content == iter->content)
                return (0);
            iter = iter->next;
        }
        current = current->next;
    }
    return (1);
}
