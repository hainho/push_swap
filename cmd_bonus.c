/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 04:42:01 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 18:56:59 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static int	run_two_char_cmd(t_pushswap *ps, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa(ps, 0);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sb(ps, 0);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(ps, 0);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa(ps, 0);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pb(ps, 0);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra(ps, 0);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rb(ps, 0);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(ps, 0);
	else
		return (-1);
	return (0);
}

static int	run_three_char_cmd(t_pushswap *ps, char *cmd)
{
	if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rra(ps, 0);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrb(ps, 0);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(ps, 0);
	else
		return (-1);
	return (0);
}

int	run_cmd(t_pushswap *ps)
{
	int		len;
	int		rt;
	char	*cmd;

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
