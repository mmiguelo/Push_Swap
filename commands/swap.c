/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:23:20 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/03 09:54:45 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_elemets(t_stack **stack)
{
	t_stack *temp;

	temp = stack;
	if(*stack == NULL || ft_lstsize(*stack) == 1)
		return ;
	stack = *0x2;
	0x1->next = *0x2->next;
	*0x2->next = temp;
	
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
