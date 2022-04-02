/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:54:31 by pnona             #+#    #+#             */
/*   Updated: 2022/04/02 16:55:15 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *err_msg)
{
	ft_putendl_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

void	ft_split_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

long	ft_atol(const char *str)
{
	size_t	i;
	long	sign;
	long	res;

	sign = 1;
	res = 0;
	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		++i;
	}
	return (res * sign);
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
