#include "sort.h"

/**
 * change_ints - interchanges two ints in an array.
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
 * bubble_sort - Group array of int in ascending order.
 * @array: Array of int to sort.
 * @size: Size of the array.
 *
 * Description: Prints the array after each change.
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, len = size;
	bool ballons = false;

	if (array == NULL || size < 2)
		return;

	while (ballons == false)
	{
		ballons = true;
		for (a = 0; a < len - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				change_ints(array + a, array + a + 1);
				print_array(array, size);
				ballons = false;
			}
		}
		len--;
	}
}
