/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:07:31 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/18 17:25:45 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strisnum(char *str)
{
	int	i;

	i = 0;
	if ((str[0] == '-' || str[0] == '+') && str[1])
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	clean_matriz(char **matriz, int ac)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (matriz[i])
			i++;
		while (i >= 0)
		{
			free(matriz[i]);
			i--;
		}
		free(matriz);
	}
	else
		return ;
}

void	clean_stack(t_stack **stack_a)
{
	t_stack	*temp;

	if (*stack_a)
	{
		while (*stack_a)
		{
			temp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = temp;
		}
	}
}

void	handle_errors(t_stack **stack_a, char **matriz, int ac)
{
	if (matriz)
		clean_matriz(matriz, ac);
	if (stack_a)
		clean_stack(stack_a);
}
