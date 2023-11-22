#include "sort.h"

/**
 * quick_sort - sorts an array of ints using quick sort in ascending order
 * @array: array of integers
 * @size: size of the given array
 */
void quick_sort(int *array, size_t size)
{
	sorter(array, size, 0, (int) size - 1);
}

/**
 * sorter - recursive function used to split array about the pivot
 * @array: array of integers
 * @size: size of the given array
 * @l: left-hand side to the partition
 * @r: right-hand side to the partition
 */
void sorter(int *array, size_t size, int l, int r)
{
	int pivot;

	if (l < r)
	{
		pivot = partition(array, size, l, r);

		sorter(array, size, l, pivot - 1);
		sorter(array, size, pivot + 1, r);
	}
}

/**
 * partition -sorts a partition around a pivot
 * @array: array of integers
 * @size: size of the given array
 * @l: left-hand side to the partition
 * @r: right-hand side to the partition
 *
 * Return: current index of the pivot
 */
int partition(int *array, size_t size, int l, int r)
{
	int pivot, i;
	int idx = (int) l;

	pivot = array[r];
	for (i = idx; i <= r - 1; i++)
	{
		if (array[i] < pivot)
		{
			swap(array, idx, i);
			if (idx != i)
				print_array(array, size);
			idx++;
		}
	}

	swap(array, idx, r);
	if (idx != i)
		print_array(array, size);
	return (idx);
}

/**
 * swap - swaps array elements
 * @array: array of integers
 * @i: first element index
 * @j: second element index
 */
void swap(int *array, int i, int j)
{
	int temp;

	if (array != NULL)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
