#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot;

	if (!array || size < 2)
		return;

	print_sort(array, size, 1);

	pivot = partition(array, size);

	quick_sort(array, pivot);
	quick_sort(array + pivot, size - pivot);
}

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/**
 * partition - partitions the array for quicksort
 * @array: array to be partitioned
 * @size: size of the array
 * Return: index of the pivot element
 */
size_t partition(int array[], size_t size)
{
	int pivot;
	size_t i = 0, j;

	if (!array || size < 2)
		return (0);

	pivot = array[size - 1];

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_sort(array, size, 0);
			}
			i++;
		}
	}
	if (i != size - 1)
	{
		swap(&array[i], &array[size - 1]);
		print_sort(array, size, 0);
	}
	return (i);
}

/**
 * print_sort - prints the array
 * @array: array to be printed
 * @size: size of the array
 * @init: flag to initialize static variables
 */
void print_sort(int array[], size_t size, int init)
{
	static int *p = NULL;
	static size_t s;

	if (!p && init)
	{
		p = array;
		s = size;
	}
	if (!init)
		print_array(p, s);
}
