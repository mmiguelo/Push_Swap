#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void convert_to_indices(int num, int *sorted_numbers, int n, int *indices)
{
	int i = 0;

    while (i < n) 
	{
        if (sorted_numbers[i] == num) 
		{
            indices[i] = i;
            break;
        }
		i++;
    }
}

void decimal_to_binary(int *indices, int n, int is_stacked)
{
	int i = 0;
	while (i < n)
	{
		int num = indices[i];
		char binary[32];
		int index = 0;
		int j;

		if (num == 0)
		{
			printf("0000");
        }
		else
		{
			while (num > 0)
			{
				binary[index++] = (num % 2) + '0';
				num = num / 2;
			}
			int filling = 4 - index % 4;
			if (filling != 4)
			{
				j = 0;
				while (j < filling)
				{
					printf("0");
					j++;
				}
			}
			j = index - 1;
			while (j >= 0)
			{
				printf("%c", binary[j]);
				j--;
			}
		}
		if (is_stacked)
			printf("\n");
		else
			printf("   ");
		i++;
	}
}

void handle_numbers(int ac, char **av, int *indices)
{
	int n = ac - 1;
	int *numbers = malloc(n * sizeof(int));
	int *sorted_numbers = malloc(n * sizeof(int));
	int *temp_indices = malloc(n * sizeof(int));
	int i = 0;

	while (i < n) 
	{
		numbers[i] = atoi(av[i + 1]);
		i++;
	}

	memcpy(sorted_numbers, numbers, n * sizeof(int));
	qsort(sorted_numbers, n, sizeof(int), compare);

	i = 0;
	while (i < n)
	{
		int sorted_index = 0;
		while (sorted_numbers[sorted_index] != numbers[i])
            sorted_index++;
		temp_indices[i] = sorted_index;
		i++;
	}
	i = 0;
	while (i < n) 
    {
        indices[i] = temp_indices[i];
		i++;
    }
	i = 0;
	while (i < n)
    {
        printf("%d ", indices[i]);
        i++;
    }
	printf("\n");
	free(numbers);
	free(sorted_numbers);
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Please provide at least one integer.\n");
		return 1;
	}

	printf("\n\n****************************\n* EXPLAINING RADIX SORTING *\n****************************\n\n");
	printf("The numbers to sort are:\n");
	int i = 1;
	while (i < ac)
	{
		printf("%s   ", av[i]);
		i++;
	}
	printf("\n\nSince Radix only sorts positive integers,\nwe need to convert the above to its size index:\n");
	int n = ac - 1;
	int *indices = malloc(n * sizeof(int));
	handle_numbers(ac, av, indices);

	printf("\n\nNow that we have all positive numbers to their corresponding size index\nwe will have to convert them to base 10, because we only have two columns A and B:\n");
	printf("so we get the numbers above as binary numbers:\n\n");

	decimal_to_binary(indices, n, 0);
	printf("\n\nNow we are able to stack them in A stack:\n\n");
	decimal_to_binary(indices, n, 1);

	printf("-------     -------\n A(1)         B(0)\n");
    free(indices);

	return 0;
}
