#include <stdio.h>

int main()
{
    int n,k;
    scanf("%d",&n);
    if(n<1 || n> 100000) return 0;
    int arr[n];
    for(int i = 0;i<n;i++) 
    {
        scanf("%d",&arr[i]);
        if (arr[i]<1 || arr[i]>100000) return 0;
    }
    scanf("%d",&k);
    if(k>n||k<1) return 0;

    for(int i = 0;i<n-1;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if (arr[j]<arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("%d",arr[k-1]);

}