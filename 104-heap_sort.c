#include "sort.h"

void change_ints(int *c, int *d);
void big_heapy(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * change_ints - Change two ints in an array.
 * @c: First int to swap.
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
 * big_heapy - Change a binary tree into a complete binary heap.
 * @array: Array of ints representing a binary tree.
 * @size: Size of the array/tree.
 * @base: Index of the base row of the tree.
 * @root: Root node of the binary tree.
 */
void big_heapy(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		change_ints(array + root, array + large);
		print_array(array, size);
		big_heapy(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of ints in ascending
 *             order using the heap sort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		big_heapy(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		change_ints(array, array + x);
		print_array(array, size);
		big_heapy(array, size, x, 0);
	}
}
