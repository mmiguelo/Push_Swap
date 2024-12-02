/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:46:40 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/02 12:28:49 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 		fazer um atoi
			no atoi, verificar se sao maiores que INT_MAX
				se for maior, retornar ERROR and \n
		verificar se tem numeros repetidos
			se sim, retornar ERROR e \n
		verificar se estao ordenados
			se sim retornar 0 */

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

int	check_errors(char **matriz, long nbr, t_stack **stack_a)
{
	int		i;

	i = 0;
	while (matriz[i])
	{
		if ((ft_strisnum(matriz[i]) == 0) || (ft_strlen(matriz[i]) > 11))
			return (0);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		if (check_repeat(matriz) == 0)
			return (0);
	}
	return (1);
}

void	handle_error(char **matriz, t_stack **stack_a)
{
	
}
void	clean_matriz(char **matriz)
{
	int	i;

	if (matriz && *matriz)
	{
		i = 0;
		while (matriz[i])
		{
			free(matriz[i]);
			i++;
		}
		free(matriz);
	}
}

void	clean_stack(t_stack **stack_a)
{
	if (stack_a || *stack_a)
	{
		t_stack *temp;
		while (*stack_a)
		{
			temp = *stack_a;
			*stack_a = (*stack_a)->next;
			free(temp->number);
			free(temp->index);
			free(temp);
		}
		free(stack_a);
	}
}