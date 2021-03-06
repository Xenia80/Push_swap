/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:37:22 by pnona             #+#    #+#             */
/*   Updated: 2022/04/02 19:04:18 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_list **top)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = *top;
	second = (*top)->next;
	last = (*top)->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*top = second;
}

void	instr_ra(t_list **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		ft_rotate(stack_a);
		ft_putendl_fd("ra", 1);
	}
}

void	instr_rb(t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		ft_rotate(stack_b);
		ft_putendl_fd("rb", 1);
	}
}

void	instr_rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && *stack_b && (*stack_a)->next && (*stack_b)->next)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		ft_putendl_fd("rr", 1);
	}
}
