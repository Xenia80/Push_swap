/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:38:23 by pnona             #+#    #+#             */
/*   Updated: 2021/10/16 17:39:11 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		j;
	const char	*str;

	i = 0;
	j = (char)c;
	str = (const char *)s;
	while (i < n)
	{
		if (str[i] == j)
		{
			return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
