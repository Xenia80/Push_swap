/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:02:36 by pnona             #+#    #+#             */
/*   Updated: 2021/10/24 16:41:47 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_length(int a)
{
	size_t	len;

	len = 0;
	if (a <= 0)
		len++;
	while (a != 0)
	{
		a = a / 10;
		len++;
	}
	return (len);
}

static int	ft_modul(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}

static void	ft_rev(char *str)
{
	size_t	i;
	size_t	len;
	char	buf;

	len = ft_strlen(str) - 1;
	i = 0;
	while (i <= (len / 2))
	{
		buf = str[i];
		str[i] = str[len - i];
		str[len - i] = buf;
		i++;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*nstr;
	size_t	i;

	len = ft_length(n);
	nstr = (char *)malloc(len + 1);
	if (!nstr)
		return (NULL);
	if (n < 0)
		nstr[len - 1] = '-';
	if (n == 0)
		nstr[0] = '0';
	i = 0;
	while (n != 0)
	{
		nstr[i] = ft_modul(n % 10) + '0';
		n = n / 10;
		i++;
	}
	nstr[len] = '\0';
	ft_rev(nstr);
	return (nstr);
}
