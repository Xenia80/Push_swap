/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:52:13 by pnona             #+#    #+#             */
/*   Updated: 2021/10/26 19:52:15 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		y = 0;
		while (haystack[i + y] == needle[y] && haystack[i + y]
			&& needle[y] && i + y < len)
		{
			y++;
		}
		if (needle[y] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
