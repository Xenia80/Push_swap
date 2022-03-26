/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:53:05 by pnona             #+#    #+#             */
/*   Updated: 2022/03/26 18:02:08 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define ERR_MSG "Error"

void	min_max_step(t_list *stack_a, int number, int *a);
void	count_rotate(t_list *stack_a, t_list *stack_b, int *rot_a, int *rot_b);
void	instr_pb(t_list **stack_a, t_list **stack_b);
void	instr_pa(t_list **stack_a, t_list **stack_b);
void	instr_rra(t_list *stack_a);
void	instr_rrb(t_list *stack_b);
void	instr_rrr(t_list *stack_a, t_list *stack_b);
void	instr_ra(t_list **stack_a);
void	instr_rb(t_list **stack_b);
void	instr_rr(t_list **stack_a, t_list **stack_b);
void	instr_sa(t_list **stack_a);
void	instr_sb(t_list **stack_b);
void	instr_ss(t_list **stack_a, t_list **stack_b);
void	make_stack_a(t_list **stack_a, size_t argc, char **argv);
void	mid_algo(t_list **stack_a, t_list **stack_b);
int		find_min(t_list *stack);
int		find_max(t_list *stack);
void	sort_3(t_list **stack);
int		sorted(t_list *stack);
void	sort_morethen3(t_list **stack_a, t_list **stack_b);
int		ft_duplicat(int *arr, int len);
int		search_min(int a, int b);
int		ft_abs(int nbr);
void	rot_1(t_list **stack, int n, void (*f)(t_list **));
void	rot_2(t_list **a, t_list **b, int n, void (*f)(t_list **, t_list **));
void	ft_error(char *err_msg);
void	ft_split_free(char **split);

#endif