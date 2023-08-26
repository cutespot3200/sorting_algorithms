#include "sort.h"

/**
 * find_max - Find maximum val in  array of ints.
 * @array: Array of ints.
 * @size: Size of the array.
 *
 * Return: Maximum integer in the array.
 */
int find_max(int *array, int size)
{
	int max, z;

	for (max = array[0], z = 1; z < size; z++)
	{
		if (array[z] > max)
			max = array[z];
	}

	return (max);
}

/**
 * counting_sort - Sort array of ints in ascending order
 *                 using the counting sort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, z;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = find_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (z = 0; z < (max + 1); z++)
		count[z] = 0;
	for (z = 0; z < (int)size; z++)
		count[array[z]] += 1;
	for (z = 0; z < (max + 1); z++)
		count[z] += count[z - 1];
	print_array(count, max + 1);

	for (z = 0; z < (int)size; z++)
	{
		sorted[count[array[z]] - 1] = array[z];
		count[array[z]] -= 1;
	}

	for (z = 0; z < (int)size; z++)
		array[z] = sorted[z];

	free(sorted);
	free(count);
}
