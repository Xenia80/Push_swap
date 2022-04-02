/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:02:53 by pnona             #+#    #+#             */
/*   Updated: 2022/04/02 16:09:04 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "check_bonus.h"

static int	do_instr(t_list **stack_a, t_list **stack_b, char *in)
{
	if (3 == ft_strlen(in) && !ft_strncmp(in, "sa\n", ft_strlen(in)))
		bonus_sa(stack_a);
	else if (3 == ft_strlen(in) && !ft_strncmp(in, "sb\n", ft_strlen(in)))
		bonus_sb(stack_b);
	else if (3 == ft_strlen(in) && !ft_strncmp(in, "ss\n", ft_strlen(in)))
		bonus_ss(stack_a, stack_b);
	else if (3 == ft_strlen(in) && !ft_strncmp(in, "ra\n", ft_strlen(in)))
		bonus_ra(stack_a);
	else if (3 == ft_strlen(in) && !ft_strncmp(in, "rb\n", ft_strlen(in)))
		bonus_rb(stack_b);
	else if (3 == ft_strlen(in) && !ft_strncmp(in, "rr\n", ft_strlen(in)))
		bonus_rr(stack_a, stack_b);
	else if (4 == ft_strlen(in) && !ft_strncmp(in, "rra\n", ft_strlen(in)))
		bonus_rra(stack_a);
	else if (4 == ft_strlen(in) && !ft_strncmp(in, "rrb\n", ft_strlen(in)))
		bonus_rrb(stack_b);
	else if (4 == ft_strlen(in) && !ft_strncmp(in, "rrr\n", ft_strlen(in)))
		bonus_rrr(stack_a, stack_b);
	else if (3 == ft_strlen(in) && !ft_strncmp(in, "pa\n", ft_strlen(in)))
		bonus_pa(stack_a, stack_b);
	else if (3 == ft_strlen(in) && !ft_strncmp(in, "pb\n", ft_strlen(in)))
		bonus_pb(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static int	read_instr(t_list **stack_a, t_list **stack_b)
{
	char	*instr;

	while (1)
	{
		instr = get_next_line(0);
		if (!instr)
			return (1);
		if (!do_instr(stack_a, stack_b, instr))
			ft_error(ERR_MSG);
		free (instr);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	make_stack_a(&stack_a, argc, argv);
	if (read_instr(&stack_a, &stack_b))
	{
		if (sorted(stack_a))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	ft_lstclear(&stack_a, free);
	return (0);
}
