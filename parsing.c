#include "pushswap.h"

static void	binary_length(t_pushswap *ps, int size)
{
	int	count;
	
	count = 0;
	while (size > 0)
	{
		size /= 2;
		count++;
	}
	ps->length = count;
	return;
}

static int	set_binary(t_pushswap *ps, t_node **list, int size)
{
	int	count;

	count = 0;
	binary_length(ps, size);
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
	int 	j;

	i = size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (list[j]->value > list[j+1]->value)
			{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
			j++;				
		}
		i--;
	}
	return;
}

static int set_node(t_pushswap *ps, char* c)
{
	t_node	*node;
	char	**sp;
	int	ptr;
	long long	n;

	ptr = 0;
	if ((sp = ft_split(c, ' ')) == NULL)
		return (-1);
	while (sp[ptr])
	{
		if (ft_strlen(sp[ptr]) > 11)
			return (-1);
		n = ft_atoi(sp[ptr++]);
		if (n > INT32_MAX || n < INT32_MIN)
			return (-1);
		if ((node = malloc(sizeof(t_node))) == NULL)
			return (-1);
		node->value = n;
		if (push_back(ps->a, node) == -1)
			return (-1);
		(ps->size)++;
	}
	return (0);
}

int	parsing(t_pushswap *ps, int argc, char **argv)
{
	t_node	*cur;
	t_node	**list;
	int		ptr;

	ptr = 1;
	while (ptr < argc)
	{
		if ((set_node(ps, argv[ptr++])) == -1)
			return (-1);
	}
	if ((list = malloc(sizeof(t_node) * (ps->size))) == NULL)
		return (-1);
	ptr = 0;
	cur = ps->a->head->next;
	while(ptr < ps->size)
	{
		list[ptr++] = cur;
		cur = cur->next;
	}
	sort(list, ps->size);
	if (set_binary(ps, list, ps->size) == -1)
	{
		free(list);
		return (-1);
	}
	free(list);
	return (0);
}
