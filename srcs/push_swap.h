#ifndef PS_SP_H
#define PS_SP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

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
    int     highest;
}   t_push;

int			validate(int argc, char **argv);
int			get_stack(t_push *stacks, int argc, char **argv);
int			check_duplicates(t_stack stack);
void		sa(t_push *stacks, int flag);
void		pb(t_push *stacks);
void		pa(t_push *stacks);
void		ss(t_push *stacks);
void		rra(t_push *stacks);
void		rrb(t_push *stacks);
void		rrr(t_push *stacks);
void		sb(t_push *stacks, int flag);
void		rb(t_push *stacks);
void		ra(t_push *stacks);
void		rr(t_push *stacks);
int			is_sorted(t_list *stack);
int			calculate_cost(t_push stacks, t_list *current, t_list *target);
int			find_corresponding_index(t_list *head, t_list *target);
t_list		*find_list_by_value(t_list	*head, int	value);
void		rotate_to_list(t_push *stacks, t_list *a, t_list *b);
t_rotation	get_rot(int ia, int ib, int asize, int bsize);
void		free_quit(t_push stacks, int flag);
int			free_mat(char **mat);
void		solve(t_push *stacks);
void		tiny_solver(t_push *stacks);
int			highest(t_list *stack);
void		print_stack(t_list *list);
void		print_both(t_push stack);

#endif
