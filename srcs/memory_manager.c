#include "push_swap.h"
#include <stdlib.h>

void	free_quit(t_push stacks, int flag)
{
	t_list	*tmp;
	t_list	*to_free;

	tmp = stacks.a.head;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
	}
	
	if (stacks.b.head)
		tmp = stacks.b.head;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
	}
	if (flag)
		write(2, "Error\n", 6);
	exit(0);
}

int	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	mat = NULL;
	return (0);
}
