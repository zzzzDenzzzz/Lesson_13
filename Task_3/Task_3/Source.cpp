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
void copyArray(T *array_3, T *array_1, T *array_2, int length_1, int length_2)
{
	int index = 0;
	for (int i = 0; i < length_1; i++, index++)
	{
		copy(&array_3[index], &array_1[i]);
	}
	for (int i = 0; i < length_2; i++, index++)
	{
		copy(&array_3[index], &array_2[i]);
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	int length_array_M;
	inputLengthArray(length_array_M);
	int *array_A = new int[length_array_M];
	initArray(array_A, length_array_M);

	int length_array_N;
	inputLengthArray(length_array_N);
	int *array_B = new int[length_array_N];
	initArray(array_B, length_array_N);

	std::cout << "Array A: ";
	printArray(array_A, length_array_M);
	std::cout << "Array B: ";
	printArray(array_B, length_array_N);

	int length_array_O = length_array_M + length_array_N;
	int *array_C = new int[length_array_O];
	copyArray(array_C, array_A, array_B, length_array_M, length_array_N);
	std::cout << "Array C: ";
	printArray(array_C, length_array_O);

	delete[]array_A;
	delete[]array_B;
	delete[]array_C;

	return 0;
}