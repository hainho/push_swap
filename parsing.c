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
	printf("length : %d\n", count);
	return;
}

// static int set_bn(t_node *node, int n, int length)
// {
// 	int temp;
// 	int ptr;
	
// 	if ((node->bn = malloc(sizeof(char) * (length + 1))) == NULL)
// 		return (-1);
// 	node->bn[length] = 0;
// 	printf("length : %d\n", length);
// 	temp = 1;
// 	while (--length)
// 		temp *= 2;
// 	printf("temp : %d\n", temp);

// 	ptr = 0;
// 	while (temp > 0)
// 	{
// 		if (n / temp > 0)
// 			node->bn[ptr] = '1';
// 		else
// 			node->bn[ptr] = '0';
// 		n %= temp;
// 		temp /= 2;
// 		ptr++;
// 		printf("temp : %d\n", temp);
// 	}
// 		printf("set_bn : %s\n", node->bn);
	

// 	return (0);
// }

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
	printf("set binary end");
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
	if ((list = malloc(sizeof(t_node) * (argc - 1))) == NULL)
		return (-1);
	while (ptr < argc)
	{
		n = ft_atoi(argv[ptr++]);
		if ((node = malloc(sizeof(t_node))) == NULL)
			return (-1);
		node->value = n;
		if (push_back(ps->a, node) == -1)
			return (-1);
		list[ptr-2] = node;
		(ps->size)++;
	}
	sort(list, ps->size);
	printf("sort end\n");
	if (set_binary(ps, list, ps->size) == -1)
	{
		free(list);
		return (-1);
	}
	free(list);
	return (0);
}
