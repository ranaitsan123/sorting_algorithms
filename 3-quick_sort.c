#include "sort.h"
/* Function declarations */
void quick_sort_helper(int *array, int low, int high, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - quick sort algorithm in ascending order
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - recursively sort the array
 * @array: array to sort
 * @low: lower index of the partition
 * @high: higher index of the partition
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = hoare_partition(array, low, high, size);

        quick_sort_helper(array, low, pivot, size);
        quick_sort_helper(array, pivot + 1, high, size);
    }
}

/**
 * hoare_partition - Hoare partition scheme
 * @array: array to partition
 * @low: lower index of the partition
 * @high: higher index of the partition
 * @size: size of the array
 *
 * Return: index of the pivot
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        print_array(array, size);
    }
}
