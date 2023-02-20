#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
int main()
{

    FILE *fptr, *sPtr;
    int index = 99;
    int arr[100000];
    clock_t t;
    fptr = fopen("DAA_1b.txt", "r");
    sPtr = fopen("Quick.txt", "w");
    for (int i = 0; i <= 999; i++)
    {
        for (int j = 0; j <= index; j++)
        {
            fscanf(fptr, "%d", &arr[j]);
        }
        t = clock();
        quickSort(arr, 0, index);
        // mergeSort(int arr[], 0, arr_size - 1);
        t = clock() - t;
        double time_taken = ((double)t) / CLOCKS_PER_SEC;
        fprintf(sPtr, "%lf\n", time_taken);
        printf("%d\t%lf\n", (i + 1), time_taken);
        index = index + 100;
        fseek(fptr, 0, SEEK_SET);
    }
    fclose(sPtr);
    fclose(fptr);

    return 0;
}