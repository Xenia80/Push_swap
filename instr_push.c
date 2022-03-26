/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:36:26 by pnona             #+#    #+#             */
/*   Updated: 2022/03/26 17:36:30 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_on_top(t_list **src, t_list **dst)
{
	t_list	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;
	ft_lstadd_front(dat, ft_lstnew(ft_strdup(tmp->content)));
	ft_lstdelone(tmp, free);
}

void	instr_pb(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
	{
		push_on_top(stack_a, stack_b);
		ft_putendl_fd("pb", 1);
	}
}

void	instr_pa(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b)
	{
		push_on_top(stack_b, stack_a);
		ft_putendl_fd("pa", 1);
	}
}
