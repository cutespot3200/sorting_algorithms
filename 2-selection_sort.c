#include "sort.h"

/**
 * change_ints - Changes two integers in an array.
 * @c: First integer to swap.
 * @d: Second integer to swap.
 */
void change_ints(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * selection_sort - Sort array of ints in ascending order
 *                  using the selection sort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		min = array + a;
		for (b = a + 1; b < size; b++)
			min = (array[b] < *min) ? (array + b) : min;

		if ((array + a) != min)
		{
			change_ints(array + a, min);
			print_array(array, size);
		}
	}
}
