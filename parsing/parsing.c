- verificar se o numero de argumentos e inferior a dois -> ./push_swap
		se sim, retornar 0
-   verificar se o numero de argumentos e dois ./push_swap "435 345 67"
		se sim, se fazer um split
		verificar se sao numeros e se o sinal de menos se encontra apenas no inicio
		verificar se sao maiores que int (usando ft_strlen: maiores que 11 ja passa o INT_MAX)
		fazer um atoi
			no atoi, verificar se sao maiores que INT_MAX
				se for maior, retornar ERROR and \n
		verificar se tem numeros repetidos
			se sim, retornar ERROR e \n
		verificar se estao ordenados
			se sim retornar 0
-   verificar se o numero de argumentos e maior que dois -> ./push_swap 435 345 67 78 9
		verificar se sao numeros e se o menos se encontra apenas no inicio
		verificar se sao maiores que int (usando ft_strlen: maiores que 11 ja passa o INT)
		fazer um atoi
			no atoi, verificar se sao maiores que INT_MAX
				se for maior, retornar ERROR and \n
		verificar se tem numeros repetidos
			se sim, retornar ERROR e \n
		verificar se estao ordenados
			se sim retornar 0


int	check_numbers_and_size(char **matriz)
{
	int i;

	i = 0;
	while (matriz[i])
	{
		if (ft_strisnum(matriz[i]) == 0)
			return (0);
		if (ft_strlen(matriz[i]) > 11)
			return (0);
		i++;
	}
	if(check_repeat(matriz) == 0)
		return (0);
	return (1);
}
