#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* int main(void)
{
	int x = 8;
	int x1 = 5;
	int x2 = 2;
	int x3 = 87;
	int x4 = 5;
	int x5 = 10;
	int x6 = 12;
	int x7 = 23;

	printf("BITWISE OPERATION\n-----------------\n%d>>1 == %d\n%d>>2 == %d\n%d>>4 == %d\n%d>>3 == %d\n", x, x>>1, x1, x1>>2, x2, x2>>4, x3, x3>>3);
	printf("BITWISE AND OPERATOR\n--------------------\n%d&%d == %d\n%d&%d == %d\n", x4, x5, x4&x5, x6, x7, x6&x7);
	return(0);
} */

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

/* int get_binary_digits(int n)
{
	int digits = 0;
	if (n == 0)
		return 1;
	while (n > 0) 
	{
		n = n / 2;
		digits++;
	}
	return digits;
} */

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

	/* int max_digits = 0;
	for (int i = 1; i < ac; i++) 
	{
		int num = atoi(av[i]);
		int digits = get_binary_digits(num);
		if (digits > max_digits) {
			max_digits = digits;
		}
	}
	for (int i = 1; i < ac; i++)
	{
		int num = atoi(av[i]);
		decimal_to_binary(num, max_digits);
		printf("\n");
	} */

	/*int num = 4;
	int num1 = 0;
	int num2 = 6;
	int num3 = 1;
	int num4 = 5;
	int num5 = 2;
	int num6 = 3;

	
	printf("Convert all negative numbers into positive:\n\n");
	printf("Sorting this:\n87 -487 781 -100 101 0 1\n\n");
	printf("Is the same as sorting this:\n%d   %d   %d   %d   %d   %d   %d\n\n", num, num1, num2, num3, num4, num5, num6);
	printf("Then this numbers in Binary is:\n");
	decimal_to_binary(num);
	printf("  ");
	decimal_to_binary(num1);
	printf("  ");
	decimal_to_binary(num2);
	printf("  ");
	decimal_to_binary(num3);
	printf("  ");
	decimal_to_binary(num4);
	printf("  ");
	decimal_to_binary(num5);
	printf("  ");
	decimal_to_binary(num6);
	printf("\n\nNow in stack it looks like this:\n");
	decimal_to_binary(num);
	printf("\n");
	decimal_to_binary(num1);
	printf("\n");
	decimal_to_binary(num2);
	printf("\n");
	decimal_to_binary(num3);
	printf("\n");
	decimal_to_binary(num4);
	printf("\n");
	decimal_to_binary(num5);
	printf("\n");
	decimal_to_binary(num6); */

	return 0;
}
