/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:17:18 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/02 12:22:26 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_list(char **matriz, t_stack **stack_a)
{
	int		i;
	long	nbr;

	i = 0;
	while (matriz[i])
	{
		nbr = ft_atol(matriz[i]);
		if (check_errors(matriz, nbr, stack_a) == 0)
		{
			write(1, "Error\n", 6);
			handle_error(matriz, stack_a);
			exit (1);
		}
		
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
}
