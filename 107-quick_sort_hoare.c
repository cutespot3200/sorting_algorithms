#include "sort.h"

void change_ints(int *c, int *d);
int semi_partition(int *array, size_t size, int left, int right);
void semi_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * semi_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: Array of ints.
 * @size: Size of the array.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int semi_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			change_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 *semi_sort - Implement the quicksort algorithm through recursion.
 * @array: Array of ints to sort.
 * @size: Size of the array.
 * @left: Starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void semi_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = semi_partition(array, size, left, right);
		semi_sort(array, size, left, part - 1);
		semi_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	semi_sort(array, size, 0, size - 1);
}
