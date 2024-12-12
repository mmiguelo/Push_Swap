/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:34:53 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/12 11:35:51 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_min_in_stack(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*min;

	if (!stack)
		return (NULL);
	temp = stack;
	min = stack;
	while (temp)
	{
		if (temp->number < min->number)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

void	sort_n2(t_stack *stack)
{
	if (stack && stack->next && stack->number > stack->next->number)
		sa(&stack);
}

void	sort_n3(t_stack **stack, int length)
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
}

void	sort_n5(t_stack **stack_a, t_stack **stack_b, int length, int index)
{
	t_stack	*min;
	int		i;

	if (length <= 3)
	{
		sort_n3(stack_a, length);
		if (ft_lstsize(*stack_b) == 2)
			pa(stack_b, stack_a);
		pa(stack_b, stack_a);
		return ;
	}
	i = get_min_in_stack(*stack_a);
	if (i < (ft_lstsize(*stack_a) / 2))
	{
		while (i--)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (ft_lstsize(*stack_a) - (i++))
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	return (sort_n5(stack_a, stack_b, --length, ++index));
}

void	sort_small_stacks(t_stack **stack_a, t_stack **stack_b, int length)
{
	if (length > 3)
		return (sort_n5(stack_a, stack_b, length, 0));
	sort_n3(stack_a, length);
}
