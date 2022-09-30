#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *reverse(int arr[], int k)
{
    int i = 0;
    int j = k - 1;

    while (i != j && i < j)
    {
        int temp1 = arr[i];
        arr[i] = arr[j];
        arr[j] = temp1;
        i++;
        j--;
    }
    return arr;
}

void print_array(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int k = 4;
    print_array(arr, 10);
    int *reversed = reverse(arr, k);
    print_array(reversed, 10);
}