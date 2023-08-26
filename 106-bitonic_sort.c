#include "sort.h"

void change_ints(int *c, int *d);
void bit_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bit_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bit_sort(int *array, size_t size);

/**
 * change_ints - Swap two ints in an array.
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
 * bit_merge - Sort a bit sequence inside an array of integers.
 * @array: Array of ints.
 * @size: Size of the array.
 * @start: Starting index of the sequence in array to sort.
 * @seq: Size of the sequence to sort.
 * @flow: Direction to sort in.
 */
void bit_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t f, jump = seq / 2;

	if (seq > 1)
	{
		for (f = start; f < start + jump; f++)
		{
			if ((flow == UP && array[f] > array[f + jump]) ||
			    (flow == DOWN && array[f] < array[f + jump]))
				change_ints(array + f, array + f + jump);
		}
		bit_merge(array, size, start, jump, flow);
		bit_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bit_seq - Convert an array of integers into a bitonic sequence.
 * @array: Array of ints.
 * @size: Size of the array.
 * @start: Starting index of a block of the building bitonic sequence.
 * @seq: Size of a block of the building bitonic sequence.
 * @flow: Direction to sort the bitonic sequence block in.
 */
void bit_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bit_seq(array, size, start, cut, UP);
		bit_seq(array, size, start + cut, cut, DOWN);
		bit_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bit_seq(array, size, 0, size, UP);
}
