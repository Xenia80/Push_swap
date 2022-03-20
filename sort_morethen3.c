/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_morethen3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:36:47 by pnona             #+#    #+#             */
/*   Updated: 2022/03/20 15:57:56 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	one_way_rotate(t_list **stack_a, t_list **stack_b, int rot_a, int rot_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(rot_a);
	abs_b = ft_abs(rot_b);
	if (rot_a >= 0 && rot_b >= 0)
	{
		rotate_2(stack_a, stack_b, search_min(rot_a, rot_b), rr);
		if (rot_a < rot_b)
			rotate_1(stack_b, rot_b - rot_a, rb);
		else
			rotate_1(stack_a, rot_a - rot_b, ra);
	}
	else
	{
		rotate_2(stack_a, stack_b, search_min(abs_a, abs_b), rrr);
		if (abs_a < abs_b)
			rotate_1(stack_b, abs_b - abs_a, rrb);
		else
			rotate_1(stack_a, abs_a - abs_b, rra);
	}
}

static void	two_way_rotate(t_list **stack_a, t_list **stack_b, int rot_a, int rot_b)
{
	if (rot_a >= 0 && rot_b < 0)
	{
		rotate_1(stack_a, rot_a, ra);
		rotate_1(stack_b, ft_abs(rot_b), rrb);
	}
	else
	{
		rotate_1(stack_b, rot_b, rb);
		rotate_1(stack_a, ft_abs(rot_a), rra);
	}
}

static void	ft_final(t_list **stack_a)
{
	int	min_step;

	min_max_step(*stack_a, find_min(*stack_a), &min_step);
	if (min_step > 0)
		rotate_1(stack_a, min_step, instr_ra);
	else
		rotate_1(stack_a, ft_abs(min_step), instr_rra);
}

void	sort_morethen3(t_list **stack_a, t_list **stack_b)
{
	int	rotate_a;
	int	rotate_b;

	rotate_a = 0;
	rotate_b = 0;
	if (ft_latsize(*stack_a) < 50)
	{
		while (ft_lstsize(*stack_a) > 3)
			instr_pb(stack_a, stack_b);
		sort_3(stack_a);
	}
	else
		mid_algo(stack_a, stack_b);
	while (ft_lstsize(*stack_b))
	{
		count_rotate(*stack_a, *stack_b, &rotate_a, rotate_b);
		if ((rotate_a >= 0 && rotate_b >= 0) || (rotate_a < 0 && rotate_b < 0))
			one_way_rotate(stack_a, stack_b, rotate_a, rotate_b);
		else
			two_way_rotate(stack_a, stack_b, rotate_a, rotate_b);
		instr_pa(stack_a, stack_b);
	}
	ft_final(stack_a);
}