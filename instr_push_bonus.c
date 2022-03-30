/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:36:26 by pnona             #+#    #+#             */
/*   Updated: 2022/03/30 20:45:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_bonus.h"

static void	push_on_top(t_list **src, t_list **dst)
{
	t_list	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;
	ft_lstadd_front(dst, ft_lstnew(ft_strdup(tmp->content)));
	ft_lstdelone(tmp, free);
}

void	bonus_pb(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
		push_on_top(stack_a, stack_b);
}

void	bonus_pa(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b)
		push_on_top(stack_b, stack_a);
}
