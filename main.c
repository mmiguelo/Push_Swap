/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:17:18 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/17 15:32:37 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_nodes(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		printf("value: %i, index = %i\n", temp->number, temp->index);
		temp = temp->next;
	}
}

void	fill_list(char **matriz, t_stack **stack)
{
	int		i;
	long	nbr;

	i = 0;
	while (matriz[i])
	{
		if ((ft_strisnum(matriz[i]) == 0) || (ft_strlen(matriz[i]) > 11))
		{
			ft_printf("Error\n");
			exit (1);
		}
		nbr = ft_atol(matriz[i]);
		if (check_errors(matriz, nbr) == 0)
		{
			ft_printf("Error\n");
			handle_error(matriz, stack);
		}
		stack_add_back(stack, ft_stacknew(nbr));
		i++;
	}
}

int	main(int ac, char **av)
{
	char	**mtr;
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		mtr = ft_split(av[1], ' ');
	else
		mtr = av + 1;
	fill_list(mtr, &stack_a);
	show_nodes(&stack_a);
	if (check_sorted(stack_a) == 0)
		sort_small_stacks(&stack_a, &stack_b, ft_stacksize(stack_a));
	printf("\n\nAfter index sort\n\n");
	add_index_list(stack_a);
	show_nodes(&stack_a);
}
