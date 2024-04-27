#include <stdio.h>

void print(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
}

void fill_from_template(int template[], int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        arr[i] = template[i];
    }
}

/**
 * Bubble Sort Algorithm 
 * After each iteration (step), the largest element among the unsorted elements is placed at the end.
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

void insertion_sort(int arr[], int n)
{
    
}


int main()
{
    int arr_template[] = {-10, 77, 2, -11, 100};
    int n = sizeof(arr_template) / sizeof(int);

    // int *result_bubble = malloc(sizeof(int) * n);
    // fill_from_template(arr_template, result_bubble, n);
    // bubble_sort(result_bubble, n);
    // print(result_bubble, n);
    // free(result_bubble);

    // int *result_selection = malloc(sizeof(int) * n);
    // fill_from_template(arr_template, result_selection, n);
    // selection_sort(result_selection, n);
    // print(result_selection, n);
    // free(result_selection);
    
    return 0;
}
