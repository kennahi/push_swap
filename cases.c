/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <kennahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 12:54:52 by kennahi           #+#    #+#             */
/*   Updated: 2021/07/10 09:57:30 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_of_three(t_stack **stack)
{
	if ((ft_atoi((*stack)->content) < ft_atoi((*stack)->next->content) && \
		(ft_atoi((*stack)->next->content)
				> ft_atoi((*stack)->next->next->content))) && \
		(ft_atoi((*stack)->next->next->content) > ft_atoi((*stack)->content)))
		reverse_rotate_swap(stack);
	else if ((ft_atoi((*stack)->content) > ft_atoi((*stack)->next->content) && \
		(ft_atoi((*stack)->next->content)
				< ft_atoi((*stack)->next->next->content))) && \
		(ft_atoi((*stack)->next->next->content) > ft_atoi((*stack)->content)))
		swap(stack, "sa\n");
	else if ((ft_atoi((*stack)->content) < ft_atoi((*stack)->next->content) && \
		(ft_atoi((*stack)->next->content)
				> ft_atoi((*stack)->next->next->content))))
		reverse_rotate(stack, "rra\n");
	else if ((ft_atoi((*stack)->content) > ft_atoi((*stack)->next->content) && \
		(ft_atoi((*stack)->next->content)
				< ft_atoi((*stack)->next->next->content))))
		rotate(stack, "ra\n");
	else if ((ft_atoi((*stack)->content) > ft_atoi((*stack)->next->content) && \
		(ft_atoi((*stack)->next->content)
				> ft_atoi((*stack)->next->next->content))))
		rotate_swap(stack);
}

void	loop_stack(t_push *ps, char *pivot)
{
	while (smaller_than(ps->stack_a, pivot))
	{
		if (ft_atoi(ps->stack_a->content) < ft_atoi(pivot))
			push(&ps->stack_a, &ps->stack_b, "pb\n");
		else if (which_half_smaller(ps->stack_a, pivot))
			rotate(&ps->stack_a, "ra\n");
		else
			reverse_rotate(&ps->stack_a, "rra\n");
	}
}

void	case_of_five(t_push *ps)
{
	char	*pivot;
	int		len;

	len = 1;
	if (ps->len == 2)
	{
		if (ft_atoi(ps->stack_a->content) > ft_atoi(ps->stack_a->next->content))
			swap(&ps->stack_a, "sa\n");
		return ;
	}
	if (ps->len == 5)
		len = 2;
	pivot = ft_strdup(ps->sorted[len]);
	loop_stack(ps, pivot);
	free(pivot);
	case_of_three(&ps->stack_a);
	while (len--)
		push(&ps->stack_b, &ps->stack_a, "pa\n");
	if (ft_atoi(ps->stack_a->content) > ft_atoi(ps->stack_a->next->content))
		swap(&ps->stack_a, "sa\n");
}

void	push_to_b(t_push *ps)
{
	int	i;

	i = -1;
	while (++i < ps->div)
	{
		if (ps->median == ps->len)
			ps->median--;
		ps->medians[i] = ft_strdup(ps->sorted[ps->median]);
		while (smaller_than(ps->stack_a, ps->medians[i]))
		{
			if (ft_atoi(ps->stack_a->content) < ft_atoi(ps->medians[i]))
				push(&ps->stack_a, &ps->stack_b, "pb\n");
			else if (which_half_smaller(ps->stack_a, ps->medians[i]))
				rotate(&ps->stack_a, "ra\n");
			else
				reverse_rotate(&ps->stack_a, "rra\n");
		}
		ps->median += ps->add;
	}
	ft_free(&ps->medians);
	while (ps->stack_a)
		push(&ps->stack_a, &ps->stack_b, "pb\n");
}

void	more_than_five(t_push *ps)
{
	if (ps->len <= 20)
		ps->median = ps->len / 2;
	else if (ps->len <= 100)
		ps->median = ps->len / 7;
	else
		ps->median = ps->len / 12;
	ps->div = (ps->len / ps->median);
	ps->medians = (char **)malloc(sizeof(char *) * (ps->div + 1));
	ps->medians[ps->div] = NULL;
	ps->add = ps->median;
	push_to_b(ps);
	while (ps->stack_b)
	{
		get_max(ps->stack_b, &ps->max);
		if (!ft_strcmp(ps->stack_b->content, ps->max))
			push(&ps->stack_b, &ps->stack_a, "pa\n");
		else if (which_half_equals(ps->stack_b, ps->max))
			rotate(&ps->stack_b, "rb\n");
		else
			reverse_rotate(&ps->stack_b, "rrb\n");
		free(ps->max);
	}
}
