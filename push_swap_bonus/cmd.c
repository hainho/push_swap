#include "pushswap.h"

static int run_two_char_cmd(t_pushswap *ps, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa(ps);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sb(ps);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(ps);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa(ps);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pb(ps);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra(ps);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rb(ps);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(ps);
	else
		return (-1);
	return (0);
}

static int run_three_char_cmd(t_pushswap *ps, char *cmd)
{
	if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rra(ps);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrb(ps);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(ps);
	else
		return (-1);
	return (0);
}

int 	run_cmd(t_pushswap *ps)
{
	int 	len;
	int		rt;
	char    *cmd;

	cmd = get_next_line(0);
	if (cmd == NULL)
		return (1);
	len = ft_strlen(cmd);
	rt = -1;
	if (len == 3)
		rt = run_two_char_cmd(ps, cmd);
	else if (len == 4)
		rt = run_three_char_cmd(ps, cmd);
	free(cmd);
	return (rt);
}
