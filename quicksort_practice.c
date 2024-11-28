#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partion(int arr[], int l, int r)
{
    int pivot = arr[l];
    int i = l + 1;
    int j = r;
    while (1)
    {
        while (i <= j && arr[i] <= pivot)
            i++;
        while (i <= j && arr[j] >= pivot)
            j--;
        if (i <= j)
            swap(&arr[i], &arr[j]);

        else
            break;
    }

    swap(&arr[j], &arr[l]);
    return j;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int par = partion(arr, l, r);
        quickSort(arr, l, par - 1);
        quickSort(arr, par + 1, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}
