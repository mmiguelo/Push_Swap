/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:23:20 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/16 17:45:42 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_element(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (*stack == NULL || ft_stacksize(*stack) == 1)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = (*stack)->next;
	if (temp->next)
		temp->next->prev = temp;
	temp->prev = *stack;
	(*stack)->next = temp;
}

void	sa(t_stack **stack_a)
{
	swap_element(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap_element(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_element(stack_a);
	swap_element(stack_b);
	ft_printf("ss\n");
}
