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

int partition(int *array, size_t size, int start, int end)
{
	int pivot, i, j;

	pivot = array[end];
	i = start - 1;
	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[end]);
	return (i + 1);
}

/**
 * swap - function to swap two elements
 * @a: pointer to the first element
 * @b: pointer to the second element
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
