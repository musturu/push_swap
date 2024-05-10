#include "push_swap.h"

static int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 0)
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (!str[i])
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != 0)
		return (0);
	else
		return (1);
}

static int	check_errors(char **mat)
{
	int i;
	int j;

	i = 0;
	while (mat[i])
	{
		j = i + 1;
		if (!is_num(mat[i]))
			return (0);
		if (ft_atoi(mat[i]) > INT_MAX || ft_atoi(mat[i]) < INT_MIN)
			return  (0);
		while (mat[j])
		{
			if (ft_atoi(mat[i]) == ft_atoi(mat[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int validate(int argc, char **argv)
{
	char **mat;
	int ret;

	ret = 1;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		mat = ft_split(argv[1], ' ');
		if (!mat[0])
			ret = 0;
		else 
			ret = check_errors(mat);
		free_mat(mat);
	}
	else
		return (check_errors(argv + 1));
	return (ret);
}
