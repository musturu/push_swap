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
    else
    {
        i = -1;
        split = ft_split(argv[1], ' ');
        while (split[i++])
        {
            if (!is_num(split[i]))
                return (0);
        }
        free(split);
    }
    return (1);
}

int *get_stack(int argc, char **argv)
{
    int     *ret;
    char    **split;
    int i;

    i = 0;
    if (argc == 2)
    {
        split = ft_split(argv[1], ' ');
        while (split[i])
            i++;
        ret = ft_calloc(i, sizeof(int));
        i = -1;
        while (split[++i])
            ret[i] = ft_atoi(split[i]);
        free(split);
    }
    else
    {
        ret = ft_calloc(argc - 1, sizeof(int));
        while (i < argc)
            ret[i] = ft_atoi(argv[i]);
    }
    return (ret);
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
