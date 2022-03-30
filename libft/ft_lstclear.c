/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:04:47 by pnona             #+#    #+#             */
/*   Updated: 2022/01/29 16:21:28 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*i;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		i = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = i;
	}
	*lst = NULL;
}
