#include "sort.h"

/**
 * swap - helper to swap elements
 * @a: left element
 * @b: right element
 * Return: Void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - Lomuto scheme
 * @array: array to partition
 * @size: size of array
 * Return: Void
 */
unsigned int partition(int *array, size_t size)
{
	unsigned int ele = 0, swap_ele = 0;
	static size_t a_size, pivot = 1;
	static int *start;

	if (pivot)
	{
		start = array;
		a_size = size;
		pivot = 0;
	}
	while (ele < size)
	{
		if (array[ele] < array[size - 1])
		{
			if (ele != swap_ele)
			{
				swap(&(array[ele]), &(array[swap_ele]));
				print_array(start, a_size);
			}
			swap_ele++;
		}
		ele++;
	}
	if (array[ele - 1] < array[swap_ele])
	{
		swap(&(array[ele - 1]), &(array[swap_ele]));
		print_array(start, a_size);
	}
	return (swap_ele);
}
/**
 * quick_sort - quick sort algorithm
 * @array: array
 * @size: size of array
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
	unsigned int piv;

	if (array == NULL || size < 2)
		return;

	piv = partition(array, size);

	quick_sort(array, piv);
	quick_sort(array + piv + 1, size - piv - 1);
}
