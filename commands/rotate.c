/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:23:23 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/18 12:01:57 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_element(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || ft_stacksize(*stack) == 1)
		return ;
	temp = ft_stacklast(*stack);
	*stack = (*stack)->next;
	temp->next = (*stack)->prev;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	temp->next->prev = temp;
}

void	ra(t_stack **stack_a)
{
	rotate_element(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate_element(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}
