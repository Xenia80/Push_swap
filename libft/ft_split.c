/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:52:34 by pnona             #+#    #+#             */
/*   Updated: 2021/10/25 21:04:54 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	word_count(const char *s1, char a)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s1[i])
	{
		if (s1[i] == a)
			i++;
		else
		{
			w++;
			while (s1[i] != '\0' && s1[i] != a)
				i++;
		}
	}
	return (w);
}

static	char	*create_word(const char *s1, char a)
{
	int		i;
	char	*new;

	i = 0;
	while (*s1 && *s1 == a)
		s1++;
	while (s1[i] && s1[i] != a)
		i++;
	new = (char *)malloc(i + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != a)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static	void	freearr(int i, char **arr)
{
	while (i > 0)
	{
		free(arr[i - 1]);
		i--;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		word;

	if (!s)
		return (NULL);
	word = word_count(s, c);
	arr = (char **)malloc((word + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < word)
	{
		while (*s && *s == c)
			s++;
		arr[i] = create_word(s, c);
		if (!arr[i])
			freearr(i, arr);
		while (*s && *s != c)
			s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
