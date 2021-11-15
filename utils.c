/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <kennahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:27:18 by kennahi           #+#    #+#             */
/*   Updated: 2021/07/10 09:06:31 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_swap(t_stack **stack)
{
	reverse_rotate(stack, "rra\n");
	swap(stack, "sa\n");
}

void	rotate_swap(t_stack **stack)
{
	rotate(stack, "ra\n");
	swap(stack, "sa\n");
}

static char	*ft_ispace(const char *s)
{
	while (((*s == ' ') || (*s == '\t') || \
				(*s == '\n') || (*s == '\v') || \
				(*s == '\f') || (*s == '\r')))
		s++;
	return ((char *)s);
}

long	atoi_pushswap(t_push *ps, char *str)
{
	long	num;
	int		i;
	int		len;
	int		sign;

	num = 0;
	i = 0;
	len = 0;
	sign = 1;
	str = ft_ispace(str);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		len++;
	}
	if (len > 10)
		errored(ps);
	return (num * sign);
}
