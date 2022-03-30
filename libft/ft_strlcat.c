/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:39:34 by pnona             #+#    #+#             */
/*   Updated: 2021/10/16 19:46:16 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	i;
	size_t	len_src;

	len_src = ft_strlen(src);
	len_dst = 0;
	i = 0;
	while (dst[len_dst] && len_dst < dstsize)
	{
		len_dst++;
	}
	while (src[i] && (i + len_dst + 1) < dstsize)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	if (dstsize > len_dst)
		dst[len_dst + i] = '\0';
	return (len_src + ft_min(dstsize, len_dst));
}
