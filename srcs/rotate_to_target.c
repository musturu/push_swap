#include "push_swap.h"

static void double_single(t_push *stacks, t_list *a, t_list *b);
static int direction(t_rotation rot);
static void toomuch_r(t_push *stacks, t_rotation rot);
static void rotate_single(t_push *stacks, t_list *list, char abflag);

void		rotate_to_list(t_push *stacks, t_list *a, t_list *b)
{
    t_rotation  rot;
    int ia;
    int ib;

   	ia = find_corresponding_index(stacks->a.head, a);
	ib = find_corresponding_index(stacks->b.head, b);
	rot = get_rot(ia, ib, stacks->a.size, stacks->b.size);
    while (stacks->a.head != a || stacks->b.head != b)
    {
        if ((stacks->a.head != a && stacks->b.head != b) && direction(rot) == 1)
            double_single(stacks, a, b);
        else if ((stacks->a.head != a && stacks->b.head != b))
            toomuch_r(stacks, rot);
        if (stacks->a.head == a && stacks->b.head != b)
            rotate_single(stacks, b, 'b');
        if (stacks->b.head == b && stacks->a.head != a)
            rotate_single(stacks, a, 'a');
    }
}

static int direction(t_rotation rot)
{
        if (rot.rrarb < rot.rr && rot.rrarb < rot.rrr)
            return (1); // 1 = rrarb
        if (rot.rrbra < rot.rr && rot.rrbra < rot.rrr)
            return (1);
        if (rot.rr < rot.rrbra && rot.rr < rot.rrr && rot.rr < rot.rrarb)
            return (2); // 2 == rr
        return (3); // 3 == rrr
}

static void toomuch_r(t_push *stacks, t_rotation rot)
{
    if (rot.rr < rot.rrr)
        rr(stacks, 1);
    else
        rrr(stacks, 1);
}

static void rotate_single(t_push *stacks, t_list *list, char abflag)
{
    int i;

    if (abflag == 'b')
    {
		i = find_corresponding_index(stacks->b.head, list);
        if (i > stacks->b.size / 2)
            rrb(stacks, 1);
        else
            rb(stacks, 1);

    }
    else
    {
		i = find_corresponding_index(stacks->a.head, list);
        if (i > stacks->a.size / 2)
            rra(stacks, 1);
        else
            ra(stacks, 1);
    }
}

static void double_single(t_push *stacks, t_list *a, t_list *b)
{
    rotate_single(stacks, a, 'a');
    rotate_single(stacks, b, 'b');
}
