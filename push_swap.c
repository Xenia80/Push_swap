/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:51:59 by pnona             #+#    #+#             */
/*   Updated: 2022/03/26 17:48:09 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *stack)
{
	int	min;
	int	current;

	min = ft_atoi(stack->content);
	while (stack->next)
	{
		stack = stack->next;
		current = ft_atoi(stack->content);
		if (min > current)
			min = current;
	}
	return (min);
}

int	find_max(t_list *stack)
{
	int	max;
	int	current;

	max = ft_atoi(stack->content);
	while (stack->next)
	{
		stack = stack->next;
		current = ft_atoi(stack->content);
		if (max < current)
			max = current;
	}
	return (max);
}

void	sort_3(t_list **stack)
{
	int	min;
	int	max;
	int	first;
	int	second;

	min = find_min(*stack);
	max = find_max(*stack);
	first = ft_atoi((*stack)->content);
	second = ft_atoi((*stack)->next->content);
	if (fist == max)
	{
		instr_ra(stack);
		max = find_max(*stack);
		second = ft_atoi((*stack)->next->content);
	}
	if (second == max)
	{
		instr_rra(stack);
		max = find_max(*stack);
		second = ft_atoi((*stack)->next->content);
	}
	if (second == min)
		instr_sa(stack);
}

int	sorted(t_list *stack)
{
	while (stack->next)
	{
		if (ft_atoi(stack->content) > ft_atoi(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	make_stack_a(&stack_a, argc, argv);
	size = ft_lstsize(stack_a);
	if (!sorted(stack_a))
	{
		if (size == 2)
			instr_sa(&stack_a);
		else if (size == 3)
			sort_3(&stack_a);
		else
			sort_morethen3(&stack_a, stack_b);
	}
	ft_lstclear(&stack_a, free);
	return (0);
}
