/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <kennahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 10:49:20 by kennahi           #+#    #+#             */
/*   Updated: 2021/07/02 13:03:32 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (!stack->next)
			return (1);
		if (ft_atoi(stack->content) > ft_atoi(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_dup(t_stack *stack, char *str)
{
	t_stack		*list;
	int			i;

	i = 0;
	list = stack;
	while (list)
	{
		if (ft_atoi(list->content) == ft_atoi(str) && !i)
			i++;
		else if (!ft_strcmp(list->content, str) && i)
			return (0);
		list = list->next;
	}
	return (1);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	checker(t_push *ps)
{
	t_stack		*list;
	long int	size;

	list = ps->stack_a;
	while (list)
	{
		size = atoi_pushswap(ps, list->content);
		if (!is_digit(list->content) || !is_dup(ps->stack_a, list->content))
			errored(ps);
		if (size > 2147483647 || size < -2147483648)
			errored(ps);
		list = list->next;
	}
}
