#include "sort.h"

/**
 * change_ints - Change two ints in an array.
 * @c: First int to swap.
 * @d: Second int to swap.
 */
void change_ints(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * shello_sort - Sort  array of ints in ascending
 *              order using the shell sort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shello_sort(int *array, size_t size)
{
	size_t gap, a, b;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			b = a;
			while (b >= gap && array[b - gap] > array[b])
			{
				change_ints(array + b, array + (b - gap));
				b -= gap;
			}
		}
		print_array(array, size);
	}
}
