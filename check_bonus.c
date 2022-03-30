#include "push_swap.h"
#include "check_bonus.h"

static int	do_instr(t_list **stack_a, t_list **stack_b, char *instr)
{
	if (3 == ft_strlen(instr) && !ft_strncmp(instr, "sa\n", ft_strlen(instr)))
		bonus_sa(stack_a);
	else if (3 == ft_strlen(instr) && !ft_strncmp(instr, "sb\n", ft_strlen(instr)))
		bonus_sb(stack_b);
	else if (3 == ft_strlen(instr) && !ft_strncmp(instr, "ss\n", ft_strlen(instr)))
		bonus_ss(stack_a, stack_b);
	else if (3 == ft_strlen(instr) && !ft_strncmp(instr, "ra\n", ft_strlen(instr)))
		bonus_ra(stack_a);
	else if (3 == ft_strlen(instr) && !ft_strncmp(instr, "rb\n", ft_strlen(instr)))
		bonus_rb(stack_b);
	else if (3 == ft_strlen(instr) && !ft_strncmp(instr, "rr\n", ft_strlen(instr)))
		bonus_rr(stack_a, stack_b);
	else if (4 == ft_strlen(instr) && !ft_strncmp(instr, "rra\n", ft_strlen(instr)))
		bonus_rra(stack_a);
	else if (4 == ft_strlen(instr) && !ft_strncmp(instr, "rrb\n", ft_strlen(instr)))
		bonus_rrb(stack_b);
	else if (4 == ft_strlen(instr) && !ft_strncmp(instr, "rrr\n", ft_strlen(instr)))
		bonus_rrr(stack_a, stack_b);
	else if (3 == ft_strlen(instr) && !ft_strncmp(instr, "pa\n", ft_strlen(instr)))
		bonus_pa(stack_a, stack_b);
	else if (3 == ft_strlen(instr) && !ft_strncmp(instr, "pb\n", ft_strlen(instr)))
		bonus_pb(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static int	read_instr(t_list **stack_a, t_list **stack_b)
{
	char *instr;

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
