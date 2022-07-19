#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quick sort sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	recursive_quick_sort(array, size, 0, size - 1);
}

/**
 * recursive_quick_sort - recursive function to sort an array
 * @array: pointer to the array
 * @size: size of the array
 * @start: start index
 * @end: end index
 */

void recursive_quick_sort(int *array, size_t size, int start, int end)
{
	int pivot;
	int i, j;

	if (start < end)
	{
		pivot = partition(array, size, start, end);
		recursive_quick_sort(array, size, start, pivot - 1);
		recursive_quick_sort(array, size, pivot + 1, end);
	}
}

/**
 * partition - function to partition the array
 * @array: pointer to the array
 * @size: size of the array
 * @start: start index
 * @end: end index
 * Return: pivot index
 */
size_t partition(int *array, size_t size, int start, int end)
{
	int pivot = array[end];
	int i = start - 1;
	int j;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_int(array, i, j);
		}
	}
	i++;
	swap_int(array, i, end);
	return (i);
}

/**
 * swap_int - function to swap two integers
 * @array: pointer to the array
 * @a: index of the first integer
 * @b: index of the second integer
 */
void swap_int(int *array, size_t a, size_t b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
}
