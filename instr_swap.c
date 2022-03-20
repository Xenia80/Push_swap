#include "push_swap.h"

static void	ft_swap_upper(t_list **first)
{
	t_list	*second;

	second = *first;
	*first = (*first)->next;
	second->next = (*first)->next;
	(*first)->next = second;
}

void	instr_sa(t_list **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		ft_swap_upper(stack_a);
		ft_putendl_fd("sa", 1);
	}
}

void	instr_sb(t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		ft_swap_upper(stack_b);
		ft_putendl_fd("sb", 1);
	}
}

void	instr_ss(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		ft_swap_upper(stack_a);
		ft_swap_upper(stack_b);
		ft_putendl_fd("ss", 1);
	}
}