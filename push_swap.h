/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:22:50 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/29 16:50:28 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "my_libft/libft.h"

typedef struct s_stack
{
	int	number;
	int	index;
	struct s_stack *next;
}	t_stack;


static void	fill_list(char **matriz, t_stack **stack);


/*=============================================================================#
#                               CHECKERS                                       #
#=============================================================================*/


int			check_numbers_and_size(char **matriz);
int			ft_strisnum(char *str);
int			check_repeat(char **matriz);


#endif
