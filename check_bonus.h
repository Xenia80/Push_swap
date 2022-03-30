#ifndef BONUS_CHECK_H
# define BONUS_CHECK_H

# include "libft/libft.h"

void	bonus_pb(t_list **stack_a, t_list **stack_b);
void	bonus_pa(t_list **stack_a, t_list **stack_b);
void	bonus_rra(t_list **stack_a);
void	bonus_rrb(t_list **stack_b);
void	bonus_rrr(t_list **stack_a, t_list **stack_b);
void	bonus_ra(t_list **stack_a);
void	bonus_rb(t_list **stack_b);
void	bonus_rr(t_list **stack_a, t_list **stack_b);
void	bonus_sa(t_list **stack_a);
void	bonus_sb(t_list **stack_b);
void	bonus_ss(t_list **stack_a, t_list **stack_b);

#endif