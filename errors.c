/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <kennahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 13:14:26 by kennahi           #+#    #+#             */
/*   Updated: 2021/07/02 12:56:24 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char ***arr)
{
	int		i;

	i = 0;
	while ((*arr) && (*arr)[i])
	{
		if ((*arr)[i])
			free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	if ((*arr))
		free((*arr));
	(*arr) = NULL;
}

void	free_stack(t_stack **stack)
{
	t_stack	*prev;

	if (!(*stack))
		return ;
	while ((*stack))
	{
		prev = (*stack);
		(*stack) = (*stack)->next;
		free(prev->content);
		free(prev);
	}
}

void	error(char **r, int j)
{
	while (r[j])
	{
		if (isNumber(r[j]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		j++;
	}
}

void	errored(t_push *ps)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(&ps->stack_a);
	exit (1);
}
