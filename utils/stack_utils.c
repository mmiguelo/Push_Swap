/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:26:29 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/17 17:22:58 by mmiguelo         ###   ########.fr       */
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
	min = NULL;
	while (temp)
	{
		if ((temp->index == -1) && (!min || temp->number < min->number))
			min = temp;
		temp = temp->next;
	}
	return (min);
}

t_stack	*get_max_in_stack(t_stack *stack)
{
	t_stack *temp;
	int max;
	int max_bits;
	
	if (!stack)
		return (NULL);
	temp = stack;
	max = temp->index;
	max_bits = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> max_bits) != 0)
	{
		max_bits++;
	}
	return (max_bits);
}

void	add_index_list(t_stack *stack)
{
	t_stack *temp;
	int		i;
	int total_nodes;

	total_nodes = ft_stacksize(stack);
	i = 0;
	while (i < total_nodes)
	{
		temp = get_min_in_stack(stack);
		if (!temp)
			break;
		temp->index = i;
		i++;
	}
}