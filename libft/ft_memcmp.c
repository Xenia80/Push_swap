/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:39:32 by pnona             #+#    #+#             */
/*   Updated: 2021/10/16 17:40:04 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*one;
	unsigned char	*two;
	int				count;

	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	count = 0;
	while (n > 0)
	{
		if (one[count] == two[count])
		{
			n--;
			count++;
		}
		else
			return (one[count] - two[count]);
	}
	return (0);
}
