#include <stdlib.h>
#include <string.h>

void selection_sort(void *arr, int n, int size, int (*compare)(const void *, const void *))
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (compare(arr + j * size, arr + min_index * size) < 0)
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            void *temp = malloc(size);

            memcpy(temp, arr + i * size, size);
            memcpy(arr + i * size, arr + min_index * size, size);
            memcpy(arr + min_index * size, temp, size);

            free(temp);
        }
    }
}

void insertion_sort(void *arr, int n, int size, int (*compare)(const void *, const void *))
{
    for (int i = 1; i < n; i++)
    {
        void *key = malloc(size);
        memcpy(key, arr + i * size, size);

        int j = i - 1;

        while (j >= 0 && compare(arr + j * size, key) > 0)
        {
            memcpy(arr + (j + 1) * size, arr + j * size, size);
            j--;
        }

        memcpy(arr + (j + 1) * size, key, size);
        free(key);
    }
}

void shell_sort(void *arr, int n, int size, int (*compare)(const void *, const void *))
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            void *temp = malloc(size);
            memcpy(temp, arr + i * size, size);

            int j;
            for (j = i; j >= gap && compare(arr + (j - gap) * size, temp) > 0; j -= gap)
            {
                memcpy(arr + j * size, arr + (j - gap) * size, size);
            }

            memcpy(arr + j * size, temp, size);
            free(temp);
        }
    }
}

void bubble_sort(void *arr, int n, int size, int (*compare)(const void *, const void *))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare(arr + j * size, arr + (j + 1) * size) > 0)
            {
                void *temp = malloc(size);

                memcpy(temp, arr + j * size, size);
                memcpy(arr + j * size, arr + (j + 1) * size, size);
                memcpy(arr + (j + 1) * size, temp, size);

                free(temp);
            }
        }
    }
}

void quick_sort(void *arr, int low, int high, int size, int (*compare)(const void *, const void *))
{
    if (low < high)
    {
        void *pivot = malloc(size);
        memcpy(pivot, arr + high * size, size);

        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (compare(arr + j * size, pivot) < 0)
            {
                i++;
                void *temp = malloc(size);

                memcpy(temp, arr + i * size, size);
                memcpy(arr + i * size, arr + j * size, size);
                memcpy(arr + j * size, temp, size);

                free(temp);
            }
        }

        void *temp = malloc(size);
        memcpy(temp, arr + (i + 1) * size, size);
        memcpy(arr + (i + 1) * size, arr + high * size, size);
        memcpy(arr + high * size, temp, size);

        free(temp);

        quick_sort(arr, low, i, size, compare);
        quick_sort(arr, i + 2, high, size, compare);

        free(pivot);
    }
}

void merge_sort(void *arr, int left, int right, int size, int (*compare)(const void *, const void *))
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid, size, compare);
        merge_sort(arr, mid + 1, right, size, compare);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        void *L = malloc(n1 * size);
        void *R = malloc(n2 * size);

        memcpy(L, arr + left * size, n1 * size);
        memcpy(R, arr + (mid + 1) * size, n2 * size);

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2)
        {
            if (compare(L + i * size, R + j * size) <= 0)
            {
                memcpy(arr + k * size, L + i * size, size);
                i++;
            }
            else
            {
                memcpy(arr + k * size, R + j * size, size);
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            memcpy(arr + k * size, L + i * size, size);
            i++;
            k++;
        }

        while (j < n2)
        {
            memcpy(arr + k * size, R + j * size, size);
            j++;
            k++;
        }

        free(L);
        free(R);
    }
}
