/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:12:38 by pnona             #+#    #+#             */
/*   Updated: 2021/10/23 14:26:03 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	len_s;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	new = (char *)malloc(len_s + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
