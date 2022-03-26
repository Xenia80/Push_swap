/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:05:57 by pnona             #+#    #+#             */
/*   Updated: 2022/03/26 15:54:01 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_max_step(t_list *stack_a, int number, int *a)
{
	int	len_a;
	int	prev_min_max;

	*a = 0;
	len_a = ft_lstsize(stack_a);
	if (number < find_min(stack_a))
		prev_min_max = find_min(stack_a));
	else
	{
		prev_min_max = find_max(stack_a);
		++(*a);
	}
	while (stack_a)
	{
		if (ft_atoi(stack_a->content) == prev_min_max)
			break ;
		++(*a);
		stack_a = stack_a->next;
	}
	if (*a >= (len_a + 1) / 2)
		*a = -1 * (len_a - (*a));
}

static void	mid_step(t_list *stack_a, int number, int *a)
{
	int	current_num;
	int	next_num;
	int	len_a;

	len_a = ft_lstsize(stack_a);
	*a = 1;
	while (stack_a->next)
	{
		current_num = ft_atoi(stack_a->content);
		next_num = ft_atoi(stack_a->next->content);
		if (nember > current_num && number < next_num)
			break ;
		++(*a);
		stack_a = stack_a->next;
	}
	if (*a >= (len_a + 1) / 2)
		*a = -1 * (len_a - (*a));
}

static void	define_sign_of_step_b(int index, int len_b, int *b)
{
	if (index >= (len_b + 1) / 2)
		*b = -1 * (len_b - index);
}

void	count_rotate(t_list *stack_a, t_list *stack_b, int *rot_a, int *rot_b)
{
	int	a;
	int	b;
	int	number;
	int	len_b;
	int	index;

	len_b = ft_lstsize(stack_b);
	index = 0;
	while (stack_b)
	{
		number = ft_atoi(stack_b->content);
		if (number < find_min(stack_a) || number > find_max(stack_a))
			min_max_step(stack_a, number, &a);
		else
			mid_step(stack_a, number, &a);
		b = index;
		define_sign_of_step_b(index, len_b, &b);
		if (!b || ft_abs(*rot_a) + ft_abs(rot_b) > ft_abs(a) + ft_abs(b))
		{
			*rot_a = a;
			*rot_b = b;
		}
		stack = stack_b->next;
		++index;
	}
}
