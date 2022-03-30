/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:37:03 by pnona             #+#    #+#             */
/*   Updated: 2022/03/28 21:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_args(size_t argc, char **argv)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (!len)
			ft_error(ERR_MSG);
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])) || argv[i][j] == ' '
				|| ((argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))))
				ft_error(ERR_MSG);
			j++;
		}
		i++;
	}
}

static void	check_min_max_int(t_list *stack)
{
	long	num;

	while (stack)
	{
		num = ft_atol(stack->content);
		if (num < -2147483648 || num > 2147483647)
			ft_error(ERR_MSG);
		stack = stack->next;
	}
}

static void	check_dublicat(t_list *stack)
{
	int	i;
	int	len;
	int	*arr;

	len = ft_lstsize(stack);
	arr = (int *) ft_calloc(len, sizeof(int));
	i = 0;
	while (stack)
	{
		arr[i++] = ft_atoi(stack->content);
		stack = stack->next;
	}
	if (ft_duplicat(arr, len))
	{
		free(arr);
		ft_error(ERR_MSG);
	}
	free(arr);
}

static	int	check_composite_args(char *arg)
{
	int	i;
	int	space;
	int	digit;

	i = 0;
	space = 0;
	digit = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			++space;
		if (ft_isdigit(arg[i]))
			++digit;
		if (space && digit)
			return (1);
		i++;
	}
	return (0);
}

void	make_stack_a(t_list **stack_a, size_t argc, char **argv)
{
	size_t	i;
	size_t	j;
	char	**arg;

	check_args(argc, argv);
	i = 1;
	while (i < argc)
	{
		if (check_composite_args(argv[i]))
		{
			j = 0;
			arg = ft_split(argv[i], ' ');
			while (arg[j])
			{
				ft_lstadd_back(stack_a, ft_lstnew(ft_strdup(arg[j])));
				++j;
			}
			ft_split_free(arg);
		}
		else
			ft_lstadd_back(stack_a, ft_lstnew(ft_strdup(argv[i])));
		++i;
	}
	check_min_max_int(*stack_a);
	check_dublicat(*stack_a);
}
