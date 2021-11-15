/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <kennahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:05:29 by kennahi           #+#    #+#             */
/*   Updated: 2021/07/10 10:55:17 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char *output)
{
	t_stack	*list;
	char	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	list = *stack;
	tmp = ft_strdup(list->content);
	free(list->content);
	list->content = ft_strdup(list->next->content);
	free(list->next->content);
	list->next->content = ft_strdup(tmp);
	free(tmp);
	if (output)
		ft_putstr_fd(output, 1);
}

void	push(t_stack **pop, t_stack **push, char *output)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!*pop)
		return ;
	tmp = (*pop);
	(*pop) = (*pop)->next;
	node = (t_stack *)malloc(sizeof(t_stack));
	node->content = ft_strdup(tmp->content);
	node->next = (*push);
	(*push) = node;
	free(tmp->content);
	free(tmp);
	if (output)
		ft_putstr_fd(output, 1);
}

void	rotate(t_stack **stack, char *output)
{
	t_stack	*list;
	t_stack	*last;
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	list = (t_stack *)malloc(sizeof(t_stack));
	list->content = ft_strdup(tmp->content);
	list->next = NULL;
	last = (*stack);
	while (last->next)
		last = last->next;
	last->next = list;
	free(tmp->content);
	free(tmp);
	if (output)
		ft_putstr_fd(output, 1);
}

void	reverse_rotate(t_stack **stack, char *output)
{
	t_stack	*list;
	t_stack	*last;
	t_stack	*prev;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = (*stack);
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	list = (t_stack *)malloc(sizeof(t_stack));
	list->content = ft_strdup(last->content);
	list->next = (*stack);
	(*stack) = list;
	free(last->content);
	free(last);
	if (output)
		ft_putstr_fd(output, 1);
}
