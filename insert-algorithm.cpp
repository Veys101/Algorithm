#include <iostream>
#include <cstring>

using namespace std;

int getSize(char *str)
{

	int i = 0;
	while (str[i] != 0)
	{
		i++;
	}

	return i;
}

void fillEmpty(char *array, int len)
{
	memset(array, '\0', len);
	array[len] = '\0';
}

void initializeArray(char **initialPermutation, char **lastPermutation, int lenP, long long unsigned int lenArray)
{
	for (int i = 0; i < lenP; i++)
	{
		initialPermutation[i] = new char[lenArray];
		lastPermutation[i] = new char[lenArray];

		fillEmpty(initialPermutation[i], lenArray);
		fillEmpty(lastPermutation[i], lenArray);
	}
}

// do factorial for given value
int fact(int n)
{

	int result = 1;
	while (n > 1)
	{
		result *= n;
		n--;
	}

	return result;
}

int main(int argc, char **argv)
{

	char *input = argv[1];
	int lenP = fact(strlen(input));
	char **initialPermutation = new char *[lenP];
	char **lastPermutation = new char *[lenP];
	char *stack = new char[strlen(input)];

	fillEmpty(stack, strlen(input));

	initializeArray(initialPermutation, lastPermutation, lenP, strlen(input));

	initialPermutation[0][0] = input[0];

	int a = 0;

	for (int i = 1; i < strlen(input); i++)
	{

		int index = 0;
		for (int j = 0; j < lenP; j++)
		{

			if (strlen(initialPermutation[j]) == 0)
				break;

			for (int k = 0; k < strlen(initialPermutation[j]) + 1; k++)
			{

				for (int l = 0; l < k; l++)
				{
					stack[l] = initialPermutation[j][l];
					a++;
				}

				stack[k] = input[i];

				for (int m = k + 1; m < strlen(initialPermutation[j]) + 1; m++)
				{
					stack[m] = initialPermutation[j][m - 1];
					a++;
				}

				for (int n = 0; n < strlen(stack); n++)
				{
					lastPermutation[index][n] = stack[n];
					a++;
				}

				index++;
				fillEmpty(stack, strlen(input));
			}
		}

		for (int j = 0; j < lenP; j++)
		{

			if (strlen(lastPermutation[j]) == 0)
				break;

			for (int k = 0; k < strlen(lastPermutation[j]); k++)
			{
				initialPermutation[j][k] = lastPermutation[j][k];
			}
		}

		for (int j = 0; j < lenP; j++)
		{
			fillEmpty(lastPermutation[j], strlen(input));
		}
	}

	for (int i = 0; i < lenP; i++)
	{
		cout << initialPermutation[i] << endl;
	}

	cout << "Number of loop for " << strlen(input) << " permutation : " << a << endl;
}