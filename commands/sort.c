/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:34:53 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/18 12:02:02 by mmiguelo         ###   ########.fr       */
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

/* void	sort_n3(t_stack **stack, int length)
{
	if (length != 3)
	{
		if (*stack && (*stack)->next \
		&& (*stack)->number > (*stack)->next->number)
			sa(stack);
	}
	if (check_sorted(*stack))
		return ;
	if ((*stack)->number > (*stack)->next->number && (*stack)->number
		> (*stack)->next->next->number)
	{
		ra(stack);
		return (sort_n3(stack, length));
	}
	if ((*stack)->next->number > (*stack)->next->next->number)
	{
		rra(stack);
		return (sort_n3(stack, length));
	}
	sa(stack);
	return (sort_n3(stack, length));
} */

void	ft_sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int		min_nbr;
	int		i;
	t_stack	*temp;

	min_nbr = get_min_in_stack(*stack_a)->number;
	i = 0;
	temp = *stack_a;
	while (temp->number != min_nbr)
	{
		i++;
		temp = temp->next;
	}
	if (i <= 2)
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

	min_nbr = (get_min_in_stack(*stack_a))->number;
	i = 0;
	temp = *stack_a;
	while (temp->number != min_nbr)
	{
		i++;
		temp = temp->next;
	}
	if (i <= 3)
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

/* void	sort_n5(t_stack **stack_a, t_stack **stack_b, int length, int index)
{
	t_stack	*min;
	int		i;

	if (length <= 3)
	{
		sort_n3(stack_a, length);
		if (ft_stacksize(*stack_b) == 2)
			pa(stack_b, stack_a);
		pa(stack_b, stack_a);
		return ;
	}
	i = get_min_in_stack(*stack_a);
	if (i < (ft_stacksize(*stack_a) / 2))
	{
		while (i--)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (ft_stacksize(*stack_a) - (i++))
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	return (sort_n5(stack_a, stack_b, --length, ++index));
} */

/* void	sort_n5(t_stack **stack_a, t_stack **stack_b,	int	list_size)
{
	int	i;
	if (3 == list_size)
		sort_n3(stack_a, list_size);
	add_index_list(*stack_a); // adiconar indexes ao stack_a
	i = get_min_in_stack(*stack_a)->index; // econtrar o index do min de a
	if (i < (ft_stacksize(*stack_a) / 2))
	{
		while (i--)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (ft_stacksize(*stack_a) - (i++))
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	return (sort_n5(stack_a, stack_b, --list_size));
	
} */

void	sort_small_stacks(t_stack **stack_a, t_stack **stack_b, int length)
{
	if (length == 5)
		return (ft_sort_5(stack_a, stack_b));
	else if (length == 4)
		return (ft_sort_4(stack_a, stack_b));
	ft_sort_3(stack_a, stack_b);
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
