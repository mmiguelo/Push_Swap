/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:54:51 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/09 12:09:02 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stacknew(long number, int i)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = number;
	new->index = i;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	ft_stacksize(t_stack *stack_a)
{
	int		i;
	t_stack	*temp;

	if (!stack_a)
		return (0);
	i = 0;
	temp = stack_a;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

t_stack	*ft_stacklast(t_stack *stack_a)
{
	t_stack	*last;
	t_stack	*temp;

	if (!stack_a)
		return (NULL);
	temp = stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	last = temp;
	return (last);
}

void	stack_add_back(t_stack **stack_a, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!*stack_a)
	{
		*stack_a = new;
		return ;
	}
	temp = ft_stacklast(*stack_a);
	new->prev = temp;
	temp->next = new;
}
