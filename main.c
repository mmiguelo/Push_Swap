/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:17:18 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/09 12:20:24 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	show_nodes(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		printf("value: %i, index = %i\n", temp->number, temp->index);
		temp = temp->next;
	}
}

void	fill_list(char **matriz, t_stack **stack_a)
{
	int		i;
	long	nbr;

	i = 0;
	while (matriz[i])
	{
		if ((ft_strisnum(matriz[i]) == 0) || (ft_strlen(matriz[i]) > 11))
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		nbr = ft_atol(matriz[i]);
		if (check_errors(matriz, nbr) == 0)
		{
			write(1, "Error\n", 6);
			handle_error(matriz, stack_a);
		}
		stack_add_back(stack_a, ft_stacknew(nbr, i));
		i++;
	}
}

int	main(int ac, char **av)
{
	char	**mtr;
	t_stack	*stack_a;
	//t_stack	*stack_b;
	
	stack_a = NULL;
	//stack_b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		mtr = ft_split(av[1], ' ');
	else
		mtr = av + 1;
	fill_list(mtr, &stack_a);
	printf("------stack_a-----\n");
	show_nodes(&stack_a);
/* 	pb(&stack_a, &stack_b);
	show_nodes(&stack_a);
	printf("------stack_b-----\n");
	show_nodes(&stack_b); */
	sa(&stack_a);
	printf("------stack_a-----\n");
	show_nodes(&stack_a);
/* 	printf("------stack_b-----\n");
	show_nodes(&stack_b); */
}
