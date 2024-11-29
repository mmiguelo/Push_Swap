/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:17:18 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/29 18:14:34 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_list(char **matriz, t_stack **stack_a)
{
	int	i;
	long nbr;

	i = 0;
	while (matriz[i])
	{
		nbr = ft_atol(matriz[i]);
		if (check_limits(matriz[i], nbr, stack_a) == 0)
	}
}

int main(int ac, char **av)
{
	char	**mtr;
	t_stack	*stack_a;
	t_stack *stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return 0;
	else if (ac == 2)
		mtr = ft_split(av[1], ' ');
	else
		mtr = av + 1;
	if (check_numbers_and_size(mtr))
		fill_list(mtr, &stack_a);
	
}

av[1];
av[2];
av[3];
av[4];
av[5];