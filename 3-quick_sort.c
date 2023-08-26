#include "sort.h"

void change_ints(int *c, int *d);
int most_partition(int *array, size_t size, int left, int right);
void most_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * most_partition - Order a subset of an array of integers according to
 *                    the most partition scheme (last element as pivot).
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int most_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				change_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		change_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * most_sort - Implement the quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @left: Starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 *
 * Description: Uses the most partition scheme.
 */
void most_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = most_partition(array, size, left, right);
		most_sort(array, size, left, part - 1);
		most_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort array of ints in ascending
 *              order using the quicksort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 *
 * Description: Uses the most partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	most_sort(array, size, 0, size - 1);
}
