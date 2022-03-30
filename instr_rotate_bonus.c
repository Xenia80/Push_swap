/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:37:22 by pnona             #+#    #+#             */
/*   Updated: 2022/03/30 20:45:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

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

void	bonus_ra(t_list **stack_a)
{
	if (*stack_a && (*stack_a)->next)
		ft_rotate(stack_a);
}

void	bonus_rb(t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next)
		ft_rotate(stack_b);
}

void	bonus_rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && *stack_b && (*stack_a)->next && (*stack_b)->next)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
}
