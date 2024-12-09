/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:22:50 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/12/03 16:39:18 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "my_libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*=============================================================================#
#                                LISTS                                         #
#=============================================================================*/

void		fill_list(char **matriz, t_stack **stack_a);
void		stack_add_back(t_stack **stack_a, t_stack *new);
t_stack		*ft_stacknew(long number, int i);
t_stack		*ft_stacklast(t_stack *stack_a);
int			ft_stacksize(t_stack *stack_a);

/*=============================================================================#
#                               CHECKERS                                       #
#=============================================================================*/

int			ft_strisnum(char *str);
int			check_repeat(char **matriz);
int			check_errors(char **matriz, long nbr);
int			check_limits(char *matriz, long nbr, t_stack **stack_a);

/*=============================================================================#
#                               CLEANING                                       #
#=============================================================================*/

void		handle_error(char **matriz, t_stack **stack_a);
void		clean_stack(t_stack **stack_a);
void		clean_matriz(char **matriz);

/*=============================================================================#
#                               COMMANDS                                       #
#=============================================================================*/

void		swap_element(t_stack **stack);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		push_element_a(t_stack **stack_a, t_stack **stack_b);
void		push_element_b(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

#endif
