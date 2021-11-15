/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <kennahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:54:18 by kennahi           #+#    #+#             */
/*   Updated: 2021/06/29 15:29:55 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	which_half_smaller(t_stack *stack, char *median)
{
	int	len;
	int	i;

	len = stacksize(stack);
	i = 0;
	while (stack)
	{
		if (ft_atoi(stack->content) < ft_atoi(median))
			break ;
		i++;
		stack = stack->next;
	}
	if (i <= (len / 2))
		return (1);
	return (0);
}

int	which_half_equals(t_stack *stack, char *max)
{
	int		len;
	int		i;

	len = stacksize(stack);
	i = 0;
	while (stack)
	{
		if (!ft_strcmp(stack->content, max))
			break ;
		i++;
		stack = stack->next;
	}
	if (i <= (len / 2))
		return (1);
	return (0);
}

int	smaller_than(t_stack *stack, char *median)
{
	while (stack)
	{
		if (ft_atoi(stack->content) < ft_atoi(median))
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	get_max(t_stack *stack, char **max)
{
	if (!stack)
		return ;
	(*max) = ft_strdup(stack->content);
	while (stack)
	{
		if (ft_atoi((*max)) < ft_atoi(stack->content))
		{
			free(*max);
			(*max) = ft_strdup(stack->content);
		}
		stack = stack->next;
	}
}
