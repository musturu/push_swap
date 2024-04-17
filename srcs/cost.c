#include "push_swap.h"

static int	check_shortest(t_rotation rot);

static int	get_rrr(int ia, int ib, int asize, int bsize)
{
	int	tmpa;
	int	tmpb;
	int	rrr;

	rrr = 0;
	tmpa = ia;
	tmpb = ib;
	while (tmpa != 0 && tmpb != 0)
	{
		tmpa = (tmpa + 1) % asize;
		tmpb = (tmpb + 1) % bsize;
		rrr++;
	}
	if (tmpa > asize / 2)
		tmpa = asize - tmpa;
	if (tmpb > bsize / 2)
		tmpb = bsize - tmpb;
	rrr += tmpa + tmpb;
	return  (rrr);
}

static int get_rr(int ia, int ib, int asize, int bsize)
{
	int	tmpa;
	int	tmpb;
	int	rr;

	rr = 0;
	tmpa = ia;
	tmpb = ib;
	while (tmpa != 0 && tmpb != 0)
	{
		tmpa = (tmpa - 1) % asize;
		tmpb = (tmpb - 1) % bsize;
		rr++;
	}
	if (tmpa > asize / 2)
		tmpa = asize - tmpa;
	if (tmpb > bsize / 2)
		tmpb = bsize - tmpb;
	rr += tmpa + tmpb;
	return (rr);
}

t_rotation	get_rot(int ia, int ib, int asize, int bsize)
{
	t_rotation ret;

	ret.rrarb = asize - ia + ib;
	ret.rrbra = bsize - ib + ia;
	ret.rr = get_rr(ia, ib, asize, bsize);
	ret.rrr = get_rrr(ia, ib, asize, bsize);
	return (ret);
}

int		calculate_cost(t_push stacks, t_list *current, t_list *target)
{
	int		i[2];
	int		cost;

	i[0] = find_corresponding_index(stacks.a.head, current);
	i[1] = find_corresponding_index(stacks.b.head, target);
	cost = check_shortest(get_rot(i[0], i[1], stacks.a.size, stacks.b.size));

	return (cost);
}

static int	check_shortest(t_rotation rot)
{
	int	ret;

	ret = rot.rrbra;
	if (ret > rot.rr)
		ret = rot.rr;
	if (ret > rot.rrr)
		ret = rot.rrr;
	if (ret > rot.rrarb)
		ret = rot.rrarb;
	return (ret);
}
