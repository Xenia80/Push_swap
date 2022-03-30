/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_swap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:38:03 by pnona             #+#    #+#             */
/*   Updated: 2022/03/30 20:45:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

static void	ft_swap_upper(t_list **first)
{
	t_list	*second;

	second = *first;
	*first = (*first)->next;
	second->next = (*first)->next;
	(*first)->next = second;
}

void	bonus_sa(t_list **stack_a)
{
	if (*stack_a && (*stack_a)->next)
		ft_swap_upper(stack_a);
}

void	bonus_sb(t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next)
		ft_swap_upper(stack_b);
}

void	bonus_ss(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		ft_swap_upper(stack_a);
		ft_swap_upper(stack_b);
	}
}
