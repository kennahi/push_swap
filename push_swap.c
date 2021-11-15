/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <kennahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:24:54 by kennahi           #+#    #+#             */
/*   Updated: 2021/07/10 09:50:42 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push	ps;

	if (ac == 1)
		return (0);
	ps.stack_a = (t_stack *){0};
	ps.stack_b = (t_stack *){0};
	ps = (t_push){0};
	checkav(av, &ps);
	checker(&ps);
	sorting(&ps);
	if (ps.len == 3)
		case_of_three(&ps.stack_a);
	else if (ps.len <= 5)
		case_of_five(&ps);
	else if (ps.len > 5)
		more_than_five(&ps);
	free_stack(&ps.stack_a);
	free_stack(&ps.stack_b);
	ft_free(&ps.sorted);
}
