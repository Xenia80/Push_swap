/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:05:42 by pnona             #+#    #+#             */
/*   Updated: 2022/03/28 21:09:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *array, int len)
{
	int	x;
	int	y;
	int	min;
	int	temp;

	x = 0;
	while (x < len - 1)
	{
		min = x;
		y = x + 1;
		while (y < len)
		{
			if (array[y] < array[min])
				min = y;
			++y;
		}
		temp = array[x];
		array[x] = array[min];
		array[min] = temp;
		++x;
	}
}

static int	find_mid(t_list *stack)
{
	int	i;
	int	mid;
	int	len_s;
	int	*array;

	len_s = ft_lstsize(stack);
	array = (int *) ft_calloc(len_s, sizeof(int));
	if (!array)
		return (0);
	i = 0;
	while (stack)
	{
		array[i++] = ft_atoi(stack->content);
		stack = stack->next;
	}
	sort_array(array, len_s);
	mid = array[len_s / 2];
	free (array);
	return (mid);
}

static void	push_half_b(t_list **stack_a, t_list **stack_b, int half, int mid)
{
	t_list	*end;
	int		num;

	while (half)
	{
		num = ft_atoi((*stack_a)->content);
		if (num < mid)
		{
			instr_pb(stack_a, stack_b);
			half--;
		}
		else
		{
			end = ft_lstlast(*stack_a);
			num = ft_atoi(end->content);
			if (num < mid)
				instr_rra(stack_a);
			else
				instr_ra(stack_a);
		}
	}
}

void	mid_algo(t_list **stack_a, t_list **stack_b)
{
	int	len_a;
	int	mid;
	int	half;

	len_a = ft_lstsize(*stack_a);
	while (len_a > 2)
	{
		mid = find_mid(*stack_a);
		half = len_a / 2;
		push_half_b(stack_a, stack_b, half, mid);
		len_a = ft_lstsize(*stack_a);
	}
	if (!sorted(*stack_a))
		instr_sa(stack_a);
}
