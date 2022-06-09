/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:47:24 by iha               #+#    #+#             */
/*   Updated: 2022/06/08 10:56:07 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_ex2()
{
	int a = 471;
	int b = 30;
	while(a > 0)
	{
	int temp = a+b;

	while (a < temp)
	{
		printf("%d ", a);
		a++;
	}
	a-=60;
	}
}

void	print_ex(int ps_size, int chunk_size)
{
	if (chunk_size % 2 == 1)
		chunk_size--;
	int a = chunk_size;
	int b = 1;
	
	while (a <= ps_size)
	{
		printf("%d %d ", a, b);
		a+=2;
		b+=2;
	}
	a = 2;
	while (b < ps_size)
	{
		printf("%d %d ", a, b);
		a+=2;
		b+=2;
	}
}

void	print_b(t_pushswap *ps)
{
	t_node *node;

	node = ps->b->head->next;
	while(node->next)
	{
		printf("%d\n", node->bn);
		node = node->next;
	}
}

int	main(int argc, char **argv)
{
	t_pushswap	*ps;

	// print_ex(100, 15);
	// print_ex2();
	// return (0);./p
	if (argc == 1)
		return (0);
	ps = new_pushswap();
	if (ps == NULL)
		return (-1);
	if (parsing(ps, argc, argv) == -1)
	{
		write(2, "Error\n", 6);
		return (free_pushswap(ps));
	}
	if (is_sorted(ps->a, ps->size) == 0)
		return (free_pushswap(ps));
	if (ps->size == 3)
		three_sort_all(ps, 0);
	else if (ps->size == 5)
		five_sort_all(ps);
	else
	{
		shift_a_to_b(ps);
		shift_b_to_a(ps);
	}
	free_pushswap(ps);
	return (0);
}
