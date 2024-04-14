
# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_rotation
{
	int	rrarb;
	int	rrbra;
	int	rr;
	int	rrr;
} t_rotation;

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
void	sa(t_push *stacks, int flag);
void	pb(t_push *stacks);
void	pa(t_push *stacks);
void	ss(t_push *stacks);
void	rra(t_push *stacks);
void	rrb(t_push *stacks);
void	rrr(t_push *stacks);
void	sb(t_push *stacks, int flag);
void	rb(t_push *stacks);
void	ra(t_push *stacks);
void	rr(t_push *stacks);
int		is_sorted(t_stack stack);
int		calculate_cost(t_push stacks, t_list *current, t_list *target);
int		find_corresponding_index(t_list *head, t_list *target);
void	rotate_to_list(t_push *stacks, t_list *a, t_list *b);
