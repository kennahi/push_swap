/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <kennahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:58:25 by kennahi           #+#    #+#             */
/*   Updated: 2021/07/02 13:27:43 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_stack
{
	char			*content;
	struct s_stack	*next;
}				t_stack;

typedef struct s_push
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			len;
	char		**sorted;
	int			median;
	char		**medians;
	int			div;
	int			add;
	char		*max;
}				t_push;

int		isNumber(char *number);
void	error(char **r, int j);
void	errored(t_push *ps);
void	duplicate(char **r);
void	checkav(char **av, t_push *ps);
void	initstack(char **r, t_push *ps);
void	ft_free(char ***arr);
void	split_arg(t_stack **list, char *arr);
int		stacksize(t_stack *stack);
void	free_stack(t_stack **stack);
int		is_digit(char *str);
void	checker(t_push *ps);
int		is_dup(t_stack *stack, char *str);
int		stack_is_sorted(t_stack *stack);
int		partition(char ***arr, int l, int r);
void	swaping(char ***arr, int i, int j);
void	quicksort(char ***arr, int l, int r);
void	sorting(t_push *ps);
void	rotate(t_stack **stack, char *output);
void	reverse_rotate(t_stack **stack, char *output);
void	double_instructions(t_push *ps);
void	swap(t_stack **stack, char *output);
void	push(t_stack **pop, t_stack **push, char *output);
void	case_of_three(t_stack **stack);
void	case_of_five(t_push *ps);
int		smaller_than(t_stack *stack, char *median);
int		which_half_smaller(t_stack *stack, char *median);
int		which_half_equals(t_stack *stack, char *max);
void	more_than_five(t_push *ps);
int		smaller_than(t_stack *stack, char *median);
void	get_max(t_stack *stack, char **max);
void	rotate_swap(t_stack **stack);
void	reverse_rotate_swap(t_stack **stack);
long	atoi_pushswap(t_push *ps, char *str);

#endif
