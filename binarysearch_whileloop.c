#include <stdio.h>
int binarysearch(int arr[],int size,int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return -1;
}


int main()
{

    int index;
    int key;
    int size;

    printf(" size of array\n");
    scanf("%d", &size);
    int arr[size]; 


    printf(" key value\n");
    scanf("%d", &key);

    for (int i = 0; i <size; i++)
    {
        scanf("%d", &arr[i]);
    }

    index = binarysearch(arr,size,key);

    if (index != -1)
        printf("index %d ", index);
    else
        printf(" index not found");

    return 0;
}