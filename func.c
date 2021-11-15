/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <kennahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:31:41 by kennahi           #+#    #+#             */
/*   Updated: 2021/06/29 15:17:30 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isNumber(char *number)
{
	int	i;

	i = 0;
	while (number[i] == '-' || number[i] == '+')
		i++;
	while (number[i])
	{
		if (number[i] >= 48 && number[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

int	stacksize(t_stack *stack)
{
	t_stack	*list;
	int		i;

	i = 0;
	list = NULL;
	list = stack;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	split_arg(t_stack **list, char *arr)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(arr, " ", 0);
	while (split[i])
	{
		(*list)->content = ft_strdup(split[i]);
		i++;
		if (!split[i])
			break ;
		(*list)->next = (t_stack *)malloc(sizeof(t_stack));
		(*list) = (*list)->next;
	}
	ft_free(&split);
}

void	checkav(char **av, t_push *ps)
{
	t_stack	*list;
	int		i;

	i = 1;
	ps->stack_a = (t_stack *)malloc(sizeof(t_stack));
	ps->stack_a->next = NULL;
	list = ps->stack_a;
	while (av[i])
	{
		split_arg(&list, av[i]);
		i++;
		if (!av[i])
			break ;
		list->next = (t_stack *)malloc(sizeof(t_stack));
		list = list->next;
	}
	list->next = NULL;
	ps->len = stacksize(ps->stack_a);
}
