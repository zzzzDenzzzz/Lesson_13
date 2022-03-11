#include<iostream>

void inputLengthArray(int &length_array)
{
	std::cout << "Enter length array: ";
	std::cin >> length_array;
}

void initArray(int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << "Enter array[" << i << "]: ";
		std::cin >> array[i];
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

void swap(int &a, int &b)
{
	int variable = a;
	a = b;
	b = variable;
}

void copy(int &a, int &b)
{
	a = b;
}

void copyArray(int *array_1, int *array_2, int length_2)
{
	for (int i = 0; i < length_2; i++)
	{
		copy(array_1[i], array_2[i]);
	}
}

int deletingEvenArrayElements(int *array, int length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (array[i] % 2 == 0)
		{
			count++;
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (array[i] % 2 == 0)
		{
			bool flag = true;
			for (int j = i + 1; j < length && flag == true; j++)
			{
				if (array[j] % 2 != 0)
				{
					swap(array[j], array[i]);
					flag = false;
				}
			}
		}
	}
	return length - count;
}

int deleteNonEvenArrayElements(int *array, int length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (array[i] % 2 != 0)
		{
			count++;
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (array[i] % 2 != 0)
		{
			bool flag = true;
			for (int j = i + 1; j < length && flag == true; j++)
			{
				if (array[j] % 2 == 0)
				{
					swap(array[j], array[i]);
					flag = false;
				}
			}
		}
	}
	return length - count;
}

int main()
{
	int length_array_M;
	inputLengthArray(length_array_M);
	int *array_A = new int[length_array_M];
	initArray(array_A, length_array_M);

	std::cout << "Enter button(1, 2):\n";
	std::cout << "1 - delete even elements array\n";
	std::cout << "2 - delete non even elements array\n";

	int button;
	std::cin >> button;
	int new_length_array_M;
	switch (button)
	{
	case 1:
		new_length_array_M = deletingEvenArrayElements(array_A, length_array_M);
		if (new_length_array_M == 0)
		{
			std::cout << "Nothing found\n";
		}
		else
		{
			int *new_array_A = new int[new_length_array_M];
			copyArray(new_array_A, array_A, new_length_array_M);
			printArray(new_array_A, new_length_array_M);
			delete[]new_array_A;
		}
		break;
	case 2:
		new_length_array_M = deleteNonEvenArrayElements(array_A, length_array_M);
		if (new_length_array_M == 0)
		{
			std::cout << "Nothing found\n";
		}
		else
		{
			int *new_array_A = new int[new_length_array_M];
			copyArray(new_array_A, array_A, new_length_array_M);
			printArray(new_array_A, new_length_array_M);
			delete[]new_array_A;
		}
	    break;
	}

	delete[]array_A;
	
	return 0;
}