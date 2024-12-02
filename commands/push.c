/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:22:12 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/02 15:40:52 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **stack_a)
{
	push_element(stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_b)
{
	push_element(stack_b);
	ft_printf("pb\n");
}
