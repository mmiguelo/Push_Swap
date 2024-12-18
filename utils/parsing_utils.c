/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:07:31 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/18 12:02:43 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strisnum(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	clean_matriz(char **matriz)
{
	int	i;

	if (*matriz)
	{
		i = 0;
		while (matriz[i])
		{
			free(matriz[i]);
			i++;
		}
	}
	free(matriz);
}

void	clean_stack(t_stack **stack_a)
{
	t_stack	*temp;

	if (*stack_a)
	{
		while (*stack_a)
		{
			temp = *stack_a;
			*stack_a = (*stack_a)->next;
			free(temp);
		}
	}
	free(stack_a);
}
