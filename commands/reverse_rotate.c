/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:23:30 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/18 12:01:54 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_element(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || ft_stacksize(*stack) == 1)
		return ;
	temp = ft_stacklast(*stack);
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	temp->next = (*stack);
	*stack = temp;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate_element(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate_element(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_element(stack_a);
	reverse_rotate_element(stack_b);
	ft_printf("rrr\n");
}
