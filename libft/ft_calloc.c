/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:15:34 by pnona             #+#    #+#             */
/*   Updated: 2021/10/17 19:37:47 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	a;

	a = 0;
	str = malloc(count * size);
	if (!str)
		return (NULL);
	while (a < count * size)
	{
		str[a] = 0;
		a++;
	}
	return (str);
}
