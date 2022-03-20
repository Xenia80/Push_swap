/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:37:35 by pnona             #+#    #+#             */
/*   Updated: 2022/03/20 15:37:45 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_duplicat(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len -1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	search_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void	rotate_1(t_list **stack, int n, void (*f)(t_list **))
{
	while (n)
	{
		(*f)(stack);
		--n;
	}
}

void	rotate_2(t_list **stack_a, t_list **stack_b, int n, void (*f)(t_list **, t_list **))
{
	while (n)
	{
		(*f)(stack_a, stack_b);
		--n;
	}
}