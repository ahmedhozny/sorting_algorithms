#include "sort.h"

/**
 * shell_sort - sorts an array of ints using shell sort
 *                  in ascending order
 * @array: array of integers
 * @size: size of the given array
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 0, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (n < size / 3)
		n = 3 * n + 1;

	n = n == 0 ? 1 : n;
	for (; n >= 1; n /= 3)
	{
		for (i = n; i < size; i++)
		{
			for (j = i; j >= n && (array[j] < array[j - n]); j -= n)
			{
				temp = array[j - n];
				array[j - n] = array[j];
				array[j] = temp;
			}
		}
		print_array(array, size);
	}
}
