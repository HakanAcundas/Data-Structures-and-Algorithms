#include <stdio.h>
#include <time.h>

void fill_array(int template[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        template[i] = rand();
    }
} 

void print(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
}


/**
 * Bubble Sort Algorithm 
 * After each iteration (step), the largest element among the unsorted elements is placed at the end.
 * BigO: O(n^2)
 * Average: O(n^2)
 * Space Complexity: O(1)
*/
void bubble_sort(int arr[], int n)
{
    for (int step = 0; step < n - 1; ++step)
    {
        for (int i = 0; i < n - step - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }
}


/**
 * Selection Sort Algoritm
 * Selection sort is a sorting algorithm that selects the smallest element from an unsorted list in 
 * each iteration and places that element at the beginning of the unsorted list.
 * BigO: O(n^2)
 * Average: O(n^2)
 * Space Complexity: O(1)
*/
void selection_sort(int arr[], int n)
{
    for (int step = 0; step < n - 1; ++step)
    {
        int minIndex = step;
        for (int i = step + 1; i < n; ++i)
        {
            if (arr[i] < arr[minIndex])
            {
                minIndex = i;
            }
        }
        int temp = arr[step];
        arr[step] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

/**
 * Compare key with each element on the left of it until an element smaller than it is found.
 * Note the comparization of key goes from left to right.
 * BigO: O(n^2)
 * Average: O(n^2)
 * Space Complexity: O(1)
*/
void insertion_sort(int arr[], int n)
{
    for (int step = 1; step < n; ++step)
    {
        int key = arr[step];
        int i = step - 1;
        while (key < arr[i] && i >= 0) {
            arr[i + 1] = arr[i];
            --i;
        }
        arr[i + 1] = key;
    }
}

void merge(int arr[], int p, int q, int n)
{
    // Calculating subarray lenghts.
    int n1 = q - p + 1;
    int n2 = n - q;

    // Creating subarrays
    int *sub_arr1 = (int*)malloc(n1 * sizeof(int));
    int *sub_arr2 = (int*)malloc(n2 * sizeof(int));

    // Copying values to subarrays.
    for (int i = 0; i < n1; ++i)
    {
        sub_arr1[i] = arr[p + i];
    }

    for (int j = 0; j < n2; ++j)
    {
        sub_arr2[j] = arr[q + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (sub_arr1[i] <= sub_arr2[j])
        {
            arr[k] = sub_arr1[i];
            i++;
        }
        else
        {
            arr[k] = sub_arr2[j];
            j++;
        }
        k++;
    }

    // If one of the sub_array is empty, copy the rest of the values.
    while (i < n1)
    {
        arr[k] = sub_arr1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = sub_arr2[j];
        j++;
        k++;
    }
    free(sub_arr1);
    free(sub_arr2);
}

/**
 * The MergeSort Algorithm repeatedly divides the array into two halves until we reach a stage 
 * where we try to perform MergeSort on a subarray of size 1.
 * BigO: O(n*log n)
 * Average: O(n*log n)
 * Space Complexity: O(n)
*/
void merge_sort(int arr[], int left, int right)
{
    // Divide the unsorted array until subarrays of lenght 1.
    if (left < right)
    {
        // Middle index
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted subarrays
        merge(arr, left, mid, right);
    }
}

int main()
{
    int test_arr[100000];
    int size = sizeof(test_arr) / sizeof(int);
    fill_array(test_arr, size);

    clock_t begin = clock();
    merge_sort(test_arr, 0, size - 1);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Sorting Time: %lf \n", time_spent);
    // print(test_arr, size);
    
    return 0;
}
