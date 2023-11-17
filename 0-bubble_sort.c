#include "sort.h"

/**
 * bubble_sort - sorts an array of ints using bubble sort in ascending order
 * @array: array of integers
 * @size: size of the given array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, flag;

	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (j = 0; j < size - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				flag = 1;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}

		}

		if (flag == 0)
			break;
	}
}
