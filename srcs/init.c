#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static void	split_stack(t_push *stack, char **argv, int *ret);
void		append_list(char **argv, t_list **list, int i, int *ret);

int	get_stack(t_push *stack, int argc, char **argv)
{
    long	headcont;
    int	i;
	int	ret;

	ret = 1;
    i = 2;
    if (argc == 2)
    {
        split_stack(stack, argv, &ret);
        return (ret);
    }
    headcont = ft_atoi(argv[1]);
	if (headcont > INT_MAX || headcont < INT_MIN)
		ret = 0;
    stack->a.head = ft_lstnew(headcont);
	stack->b.head = NULL;
    while (i < argc)
    {
        append_list(argv, &(stack->a.head), i, &ret);
        i++;
    }
    stack->a.size = ft_lstsize(stack->a.head);
    stack->b.size = 0;
	return (ret);
}

void	append_list(char **argv, t_list **list, int i, int *ret)
{
    long	content;
    t_list	*new;

    content = ft_atoi(argv[i]);
	if (content > INT_MAX || content < INT_MIN)
		*ret = 0;
    new = ft_lstnew(content);
    ft_lstadd_back(list, new);
}

static void	split_stack(t_push *stack, char **argv, int *ret)
{
    char	**split;
    long		headcont;
    int		i;
    int		size;

    split = ft_split(argv[1], ' ');
    size = 0;
    while (split[size])
        size++;
    i = 1;
    headcont = ft_atoi(split[0]);
	if (headcont > INT_MAX || headcont < INT_MIN)
		*ret = 0;
    stack->a.size = size;
    stack->a.head = ft_lstnew(headcont);
    stack->b.head = NULL;
    while (i < size)
        append_list(split, &(stack->a.head), i++, ret);
    while (size--)
        free(split[size]);
    free(split);
}
