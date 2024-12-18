/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:34:53 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/18 16:16:10 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack **stack_a, t_stack **stack_b)
{
	int		top;
	t_stack	*mid;

	mid = (*stack_a)->next;
	top = (mid->next)->number;
	if (check_sorted(*stack_a))
		mid = (*stack_a)->next;
	else if (top < mid->number && mid->number < (*stack_a)->number)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (top < (*stack_a)->number && (*stack_a)->number > mid->number)
		ra(stack_a);
	else if (mid->number > top && top < (*stack_a)->number)
		rra(stack_a);
	else if (mid->number > (*stack_a)->number && (*stack_a)->number < top)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->number < top && top > mid->number)
		sa(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	ft_sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int		min_nbr;
	int		i;
	t_stack	*temp;

	min_nbr = get_next_min(*stack_a);
	i = 0;
	temp = *stack_a;
	while (temp->number != min_nbr)
	{
		i++;
		temp = temp->next;
	}
	if (i < 2)
	{
		while ((*stack_a)->number != min_nbr)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->number != min_nbr)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	ft_sort_3(stack_a, stack_b);
}

void	ft_sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int		min_nbr;
	int		i;
	t_stack	*temp;

	min_nbr = get_next_min(*stack_a);
	i = 0;
	temp = *stack_a;
	while (temp->number != min_nbr)
	{
		i++;
		temp = temp->next;
	}
	if (i < 3)
	{
		while ((*stack_a)->number != min_nbr)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->number != min_nbr)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	ft_sort_4(stack_a, stack_b);
}

void	sort_small_stacks(t_stack **stack_a, t_stack **stack_b, int length)
{
	if (length == 5)
		return (ft_sort_5(stack_a, stack_b));
	else if (length == 4)
		return (ft_sort_4(stack_a, stack_b));
	else if (length == 3)
		ft_sort_3(stack_a, stack_b);
	else if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
}

void	sort_by_bits(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_stacksize(head_a);
	max_bits = get_max_in_stack(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
