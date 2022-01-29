#include "pushswap.h"

static int	binary_length(int size)
{
	int	count;
	
	count = 0;
	while (size > 0)
	{
		size /= 2;
		count++;
	}
	return (count);
}

static int set_bn(t_node *node, int n, int length)
{
	int temp;
	int ptr;
	
	if (node->bn = malloc(sizeof(char) * (length + 1)) == NULL)
		return (-1);
	node->bn[length] = 0;
	temp = 1;
	while (--length)
		temp *= 2;
	ptr = 0;
	while (temp > 0)
	{
		if (n / temp > 0)
			node->bn[ptr] = '1';
		else
			node->bn[ptr] = '0';
		n %= temp;
	}
	return (0);
}

static int	set_binary(t_node **list, int size)
{
	int	count;
	int length;

	count = 0;
	length = binary_length(size);
	while (count < size)
	{
		if (set_bn(list[count], count, length) == -1)
			return (-1);
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

int	parsing(t_pushswap *ps, int argc, char **argv)
{
	t_node	*node;
	t_node	**list;
	int		ptr;
	int		n;

	ptr = 1;
	if (list = malloc(sizeof(t_node) * (argc - 1)) == NULL)
	while (ptr < argc)
	{
		n = ft_atoi(argv[ptr++]);
		if (node = malloc(sizeof(t_node)) == NULL)
			return (-1);
		node->value = n;
		if (push_back(ps->a, node) == -1);
			return (-1);
		list[ptr-2] = node;
		(ps->size)++;
	}
	sort(list, ps->size);
	if (set_binary(list, ps->size) == -1)
	{
		free(list);
		return (-1);
	}
	return (0);
}
