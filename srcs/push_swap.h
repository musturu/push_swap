
# include "../libft/libft.h"
#include <stdio.h>


typedef struct s_stack
{
    t_list  *head;
    int     size;
}   t_stack;

typedef struct s_push
{
    t_stack a;
    t_stack b;
}   t_push;

int		validate(int argc, char **argv);
void	get_stack(t_push *stacks, int argc, char **argv);
int		check_duplicates(t_stack stack);
void	print_stack(t_list *list);
void	sa(t_push *stacks);
