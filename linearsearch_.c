#include <stdio.h>
int linearsearch(int arr[], int x,int keey)
{
    for (int j = 0; j < x; j++)
    {
        if (arr[j] == keey)
            return j;
    }
    return -1;
}

int main()
{
    int index;
    int key;
    int n;
    printf(" size of array\n");
    scanf("%d", &n);
    printf(" key value\n");
    scanf("%d", &key);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    index = linearsearch(arr, n, key);
    if (index != -1)
        printf("index %d ", index);
    else
        printf(" index not found");
    return 0;
}