/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:47:30 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 13:37:27 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	set_binary(t_node **list, int size)
{
	int	count;

	count = 0;
	while (++count < size)
	{
		if (list[count - 1]->value == list[count]->value)
			return (-1);
	}
	count = 0;
	while (count < size)
	{
		list[count]->bn = count;
		count++;
	}
	return (0);
}

static void	sort(t_node **list, int size)
{
	t_node	*temp;
	int		i;
	int		j;

	i = size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (list[j]->value > list[j + 1]->value)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			j++;
		}
		i--;
	}
	return ;
}

static int	set_node(t_pushswap *ps, char **sp)
{
	t_node		*node;
	int			ptr;
	long long	n;

	ptr = 0;
	while (sp[ptr])
	{
		n = ft_atoi(sp[ptr++]);
		if (n > INT32_MAX || n < INT32_MIN)
			return (free_split(sp));
		node = malloc(sizeof(t_node));
		if (node == NULL)
			return (free_split(sp));
		node->value = n;
		if (push_back(ps->a, node) == -1)
			return (free_split(sp));
		(ps->size)++;
	}
	return (0);
}

static int	binary_parsing(t_pushswap *ps, t_node **list)
{
	t_node	*cur;
	int		ptr;

	ptr = 0;
	cur = ps->a->head->next;
	while (ptr < ps->size)
	{
		list[ptr++] = cur;
		cur = cur->next;
	}
	sort(list, ps->size);
	if (set_binary(list, ps->size) == -1)
	{
		free(list);
		return (-1);
	}
	free(list);
	return (0);
}

int	parsing(t_pushswap *ps, int argc, char **argv)
{
	t_node	**list;
	int		ptr;
	char	**sp;

	ptr = 1;
	while (ptr < argc)
	{
		sp = ft_split(argv[ptr++], ' ');
		if (sp == NULL)
			return (-1);
		if (sp[0] == NULL)
		{
			free_split(sp);
			return (-1);
		}
		if (set_node(ps, sp) == -1)
			return (-1);
		free_split(sp);
	}
	list = malloc(sizeof(t_node) * (ps->size));
	if (list == NULL)
		return (-1);
	return (binary_parsing(ps, list));
}
