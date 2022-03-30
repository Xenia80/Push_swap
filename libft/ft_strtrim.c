/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:07:09 by pnona             #+#    #+#             */
/*   Updated: 2021/10/23 13:47:13 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	bcut;
	size_t	ecut;
	char	*res;

	if (!s1)
		return (NULL);
	bcut = 0;
	ecut = ft_strlen(s1);
	while (s1[bcut] && ft_strchr(set, s1[bcut]))
		bcut++;
	while (ft_strchr(set, s1[ecut - 1]) && ecut > bcut)
		ecut--;
	res = (char *)malloc(ecut - bcut + 1);
	if (!res)
		return (NULL);
	if (res)
		ft_strlcpy(res, &s1[bcut], ecut - bcut + 1);
	return (res);
}
