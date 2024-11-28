#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    if(n<1 || n> 100000) return 0;
    int arr[n];
    for(int i=0;i<n;i++)
    {
         scanf("%d",&arr[i]);
         if (arr[i]<-100000 || arr[i]>100000) return 0;
    }

    for(int i=1;i<n;i++)
    {
        int num = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>num)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = num;
    }

    for(int i =0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}