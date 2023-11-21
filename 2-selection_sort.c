#include "sort.h"

/**
 * selection_sort - sorts an array of ints using selection sort
 *                  in ascending order
 * @array: array of integers
 * @size: size of the given array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, selected;
	int temp;

	for (i = 0; i < size; i++)
	{
		selected = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[selected] > array[j])
				selected = j;
		}

		if (selected != i)
		{
			temp = array[i];
			array[i] = array[selected];
			array[selected] = temp;
			print_array(array, size);
		}
	}
}
