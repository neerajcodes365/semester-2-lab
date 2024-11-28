#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int par(int arr[],int l,int r){
     int pivot=arr[l];
        int i= l+1;
        int j= r;
     while(1){ 
        while(l<=r && arr[i]<= pivot) i++;
        while(l<=r && arr[j]>= pivot) j--;
        if(l<=r) swap(&arr[i],&arr[j]);
        else break;
     }
    swap(&arr[l],&arr[j]);
    return j;
}

void quicksort(int arr[], int l, int r)
{
    if (l <= r)
    {
        int j = par(arr, l, r);
        quicksort(arr, l, j - 1);
        quicksort(arr, j + 1, r);
    }
} 

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}