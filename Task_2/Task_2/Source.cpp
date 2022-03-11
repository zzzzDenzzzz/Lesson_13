#include<iostream>
#include<stdlib.h>
#include<time.h>

void inputLengthArray(int &length_array)
{
	std::cout << "Enter length array: ";
	std::cin >> length_array;
}

void initArray(int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		array[i] = 10 + rand() % 40;
	}
}

void printArray(int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void copy(T *a, T *b)
{
	*a = *b;
}

template<typename T>
void swap(T *a, T *b)
{
	T variable = *a;
	*a = *b;
	*b = variable;
}

template<typename T>
int sortArray(T *array, int length)
{
	int k = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length - k; j++)
		{
			if (array[i] == array[j])
			{
				swap(&array[j], &array[length - 1 - k]);
				j--;
				k++;
			}
		}
	}
	return length - k;
}

template<typename T>
int returnLengthArray(T *array_1, T *array_2, int length_1, int length_2)
{
	int length_array = 0;
	for (int i = 0; i < length_1; i++)
	{
		int match_count = 0;
		for (int j = 0; j < length_2; j++)
		{
			if (array_1[i] == array_2[j])
			{
				match_count++;
			}
		}
		if (match_count == 0)
		{
			length_array++;
		}
	}

	for (int i = 0; i < length_2; i++)
	{
		int match_count = 0;
		for (int j = 0; j < length_1; j++)
		{
			if (array_2[i] == array_1[j])
			{
				match_count++;
			}
		}
		if (match_count == 0)
		{
			length_array++;
		}
	}

	return length_array;
}

template<typename T>
void copyArray(T *array_1, T *array_2, T *array_3, int length_2, int length_3)
{
	int k = 0;
	for (int i = 0; i < length_2; i++)
	{
		int match_count = 0;
		for (int j = 0; j < length_3; j++)
		{
			if (array_2[i] == array_3[j])
			{
				match_count++;
			}
		}
		if (match_count == 0)
		{
			copy(&array_1[k], &array_2[i]);
			k++;
		}
	}
	for (int i = 0; i < length_3; i++)
	{
		int match_count = 0;
		for (int j = 0; j < length_2; j++)
		{
			if (array_3[i] == array_2[j])
			{
				match_count++;
			}
		}
		if (match_count == 0)
		{
			copy(&array_1[k], &array_3[i]);
			k++;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	int length_array_M;
	inputLengthArray(length_array_M);
	int *array_A = new int[length_array_M];
	initArray(array_A, length_array_M);
	int new_length_array_M = sortArray(array_A, length_array_M);

	int length_array_N;
	inputLengthArray(length_array_N);
	int *array_B = new int[length_array_N];
	initArray(array_B, length_array_N);
	int new_length_array_N = sortArray(array_B, length_array_N);

	std::cout << "Array A: ";
	printArray(array_A, length_array_M);
	std::cout << "Array B: ";
	printArray(array_B, length_array_N);

	int length_array_MN = returnLengthArray(array_A, array_B, new_length_array_M, new_length_array_N);
	int *array_C = new int[length_array_MN];
	copyArray(array_C, array_A, array_B, new_length_array_M, new_length_array_N);
	std::cout << "Array C: ";
	printArray(array_C, length_array_MN);

	delete[]array_A;
	delete[]array_B;
	delete[]array_C;

	return 0;
}