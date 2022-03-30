/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_reverse_rotate_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:59:16 by pnona             #+#    #+#             */
/*   Updated: 2022/03/30 20:45:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

static void	ft_reverse_rotate(t_list **top)
{
	t_list	*do_last;
	t_list	*last;

	last = *top;
	while (last->next)
	{
		do_last = last;
		last = last->next;
	}
	last->next = *top;
	*top = last;
	do_last->next = NULL;
}

void	bonus_rra(t_list **stack_a)
{
	if (*stack_a && (*stack_a)->next)
		ft_reverse_rotate(stack_a);
}

void	bonus_rrb(t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next)
		ft_reverse_rotate(stack_b);
}

void	bonus_rrr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && stack_b && (*stack_a)->next && (*stack_b)->next)
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
	}
}
