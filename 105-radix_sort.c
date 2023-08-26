#include "sort.h"

int find_max(int *array, int size);
void radix_count_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * find_max - Find the maximum value in an array of integers.
 * @array: Array of ints.
 * @size: Size of the array.
 *
 * Return: The maximum integer in the array.
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
 * radix_count_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 * @sig: Significant digit to sort on.
 * @buff: Buffer to store the sorted array.
 */
void radix_count_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t x;

	for (x = 0; x < size; x++)
		count[(array[x] / sig) % 10] += 1;

	for (x = 0; x < 10; x++)
		count[x] += count[x - 1];

	for (x = size - 1; (int)x >= 0; x--)
	{
		buff[count[(array[x] / sig) % 10] - 1] = array[x];
		count[(array[x] / sig) % 10] -= 1;
	}

	for (x = 0; x < size; x++)
		array[x] = buff[x];
}

/**
 * radix_sort - Sort  array of ints in ascending
 *              order using the radix sort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = find_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_count_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
