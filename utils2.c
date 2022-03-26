/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:54:31 by pnona             #+#    #+#             */
/*   Updated: 2022/03/26 18:00:05 by pnona            ###   ########.fr       */
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
	while (split[i]
	{
		free(split[i]);
		++;
	}
	free(split);
}