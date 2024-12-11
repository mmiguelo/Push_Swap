/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:46:40 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/11 12:16:37 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_repeat(char **matriz)
{
	int	i;
	int	j;

	i = 0;
	while (matriz[i])
	{
		j = i + 1;
		while (matriz[j])
		{
			if (ft_strcmp(matriz[i], matriz[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_errors(char **matriz, long nbr)
{
	int		i;

	i = 0;
	while (matriz[i])
	{
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		if (check_repeat(matriz) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	handle_error(char **matriz, t_stack **stack_a)
{
	if (matriz)
		clean_matriz(matriz);
	if (stack_a)
		clean_stack(stack_a);
	exit (1);
}

int	check_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (ft_stacksize(stack) > 1)
	{
		while (temp->next)
		{
			if (temp->number > temp->next->number)
				return (0);
			temp = temp->next;
		}
	}
	return (1);
}
