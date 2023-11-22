#include "sort.h"

/**
 * counting_sort - sorts an array of ints using counting sort
 *                  in ascending order
 * @array: array of integers
 * @size: size of the given array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int k = 0;
	int *count_arr, *temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
		k = array[i] > k ? array[i] : k;

	count_arr = malloc(sizeof(int) * (k + 1));
	temp = malloc(sizeof(int) * (size + 1));

	for (i = 0; i < (size_t) k + 1; i++)
		count_arr[i] = 0;
	for (i = 0; i < size; i++)
		count_arr[array[i]]++;
	for (i = 1; i < (size_t) k + 1; i++)
		count_arr[i] += count_arr[i - 1];

	print_array(count_arr, k + 1);

	for (i = 0; i < size; i++)
		temp[--count_arr[array[i]]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = temp[i];
	free(temp);
	free(count_arr);
}
