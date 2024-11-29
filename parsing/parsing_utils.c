/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:07:31 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/29 17:00:46 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strisnum(char *str)
{
	int i;

	i = 0;
	if(str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_repeat(char **matriz)
{
	int i;
	int j;

	i = 0;
	j = i + 1;
	while(matriz[i])
	{
		ft_strncmp()
	}
}