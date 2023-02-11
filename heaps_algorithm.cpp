#include <iostream>
#include <cstring>

using namespace std;

void fillEmpty(char *input, int len)
{
	memset(input, '\0', len);
	input[len] = '\0';
}

void initializeArray(char **&input, int lengthArray, int lengthRow)
{

	input = new char *[lengthArray];

	for (int i = 0; i < lengthArray; i++)
	{
		input[i] = new char[lengthRow];
		fillEmpty(input[i], lengthRow);
	}
}

int fact(int number)
{

	int result = 1;

	while (number > 1)
	{
		result *= number;
		number--;
	}

	return result;
}

void swapElements(char *&elements, int i, int j)
{

	char temp = elements[i];
	elements[i] = elements[j];
	elements[j] = temp;
}

int main(int argc, char **argv)
{

	char *input = argv[1];

	int length = strlen(input);
	int lenP = fact(length);

	char **generatedPermutation;
	initializeArray(generatedPermutation, lenP, length);

	int c[length] = {0};

	int i = 0, a = 0;
	int index = 1;

	for (int k = 0; k < length; k++)
		generatedPermutation[0][k] = input[k];

	while (i < length)
	{

		if (c[i] < i)
		{

			if (i % 2 == 0)
			{
				swapElements(input, 0, i);
			}
			else
			{
				swapElements(input, c[i], i);
			}

			for (int j = 0; j < length; j++)
			{
				generatedPermutation[index][j] = input[j];
				a++;
			}

			c[i] = c[i] + 1;
			i = 0;
			index++;
		}
		else
		{
			c[i] = 0;
			i++;
			a++;
		}
	}

	for (int k = 0; k < lenP; k++)
	{
		cout << generatedPermutation[k] << endl;
	}

	cout << "Number of loop for " << length << " permutation : " << a << endl;
}