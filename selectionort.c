#include <stdio.h>
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        int minindex = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[minindex] > arr[j]) minindex = j;

            if (minindex != i)
            {
                int tm = arr[i];
                arr[i] = arr[minindex];
                arr[minindex] = tm;
            }
        }
    }
}

    int main()
    {
        int n;
        int a;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        selectionsort(arr, n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        return 0;
    }