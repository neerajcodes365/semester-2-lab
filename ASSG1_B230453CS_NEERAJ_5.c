#include <stdio.h>

int main()
{
    int n,count;
    scanf("%d",&n);
    if(n<1 || n> 100000) return 0;
    int arr[n];
    for(int i = 0;i<n;i++) 
    {
        scanf("%d",&arr[i]);
        if (arr[i]<1 || arr[i]>100000) return 0;
    }
    for(int i = 0;i<n-1;i++)
    {
        for(int j = 0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
    }

    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n%d",count);
}