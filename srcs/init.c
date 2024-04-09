#include "push_swap.h"
#include <stdio.h>

static void	split_stack(t_push *stack, char **argv);
void		append_list(char **argv, t_list **list, int i);

void	get_stack(t_push *stack, int argc, char **argv)
{
    int	*headcont;
    int	i;

    i = 2;
    if (argc == 2)
		return (split_stack(stack, argv));
	headcont = malloc(sizeof(int));
    *headcont = ft_atoi(argv[1]);
	printf("inside list: %i\n", *headcont);
    stack->a.head = ft_lstnew(headcont);
	stack->b.head = NULL;
    while (i < argc)
    {
        append_list(argv, &(stack->a.head), i);
        i++;
    }
    stack->a.size = i - 1;
}

void	append_list(char **argv, t_list **list, int i)
{
    int		*content;
    t_list	*new;

    content = malloc(sizeof(int));
    *content = ft_atoi(argv[i]);
	printf("inside list: %i\n", *content);
    new = ft_lstnew(content);
    ft_lstadd_back(list, new);
}

static void	split_stack(t_push *stack, char **argv)
{
    char	**split;
    int		headcont;
    int		i;
    int		size;

    split = ft_split(argv[1], ' ');
    size = 0;
    while (split[size])
        size++;
    i = 1;
    headcont = ft_atoi(split[0]);
    stack->a.size = size;
    stack->a.head = ft_lstnew(&headcont);
    while (i < size)
        append_list(split, &(stack->a.head), i++);
    while (size--)
        free(split[size]);
    free(split);
}
