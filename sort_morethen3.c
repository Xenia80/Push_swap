/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_morethen3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:53:44 by pnona             #+#    #+#             */
/*   Updated: 2022/04/02 18:53:47 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	o_w_rot(t_list **stack_a, t_list **stack_b, int rot_a, int rot_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(rot_a);
	abs_b = ft_abs(rot_b);
	if (rot_a >= 0 && rot_b >= 0)
	{
		rot_2(stack_a, stack_b, search_min(rot_a, rot_b), instr_rr);
		if (rot_a < rot_b)
			rot_1(stack_b, rot_b - rot_a, instr_rb);
		else
			rot_1(stack_a, rot_a - rot_b, instr_ra);
	}
	else
	{
		rot_2(stack_a, stack_b, search_min(abs_a, abs_b), instr_rrr);
		if (abs_a < abs_b)
			rot_1(stack_b, abs_b - abs_a, instr_rrb);
		else
			rot_1(stack_a, abs_a - abs_b, instr_rra);
	}
}

static void	t_w_rot(t_list **stack_a, t_list **stack_b, int rot_a, int rot_b)
{
	if (rot_a >= 0 && rot_b < 0)
	{
		rot_1(stack_a, rot_a, instr_ra);
		rot_1(stack_b, ft_abs(rot_b), instr_rrb);
	}
	else
	{
		rot_1(stack_b, rot_b, instr_rb);
		rot_1(stack_a, ft_abs(rot_a), instr_rra);
	}
}

static void	ft_final(t_list **stack_a)
{
	int	min_step;

	min_max_step(*stack_a, find_min(*stack_a), &min_step);
	if (min_step > 0)
		rot_1(stack_a, min_step, instr_ra);
	else
		rot_1(stack_a, ft_abs(min_step), instr_rra);
}

void	sort_morethen3(t_list **stack_a, t_list **stack_b)
{
	int	rotate_a;
	int	rotate_b;

	rotate_a = 0;
	rotate_b = 0;
	if (ft_lstsize(*stack_a) < 50)
	{
		while (ft_lstsize(*stack_a) > 3)
			instr_pb(stack_a, stack_b);
		sort_3(stack_a);
	}
	else
		mid_algo(stack_a, stack_b);
	while (ft_lstsize(*stack_b))
	{
		count_rotate(*stack_a, *stack_b, &rotate_a, &rotate_b);
		if ((rotate_a >= 0 && rotate_b >= 0) || (rotate_a < 0 && rotate_b < 0))
			o_w_rot(stack_a, stack_b, rotate_a, rotate_b);
		else
			t_w_rot(stack_a, stack_b, rotate_a, rotate_b);
		instr_pa(stack_a, stack_b);
	}
	ft_final(stack_a);
}
