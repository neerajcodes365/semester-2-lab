#include <stdio.h>
#include <string.h>

struct name
{
    char name[50];
    int number;
};


int main()
{
    int n;
    scanf("%d",&n);
    if(n<1 || n> 100000) return 0;
    struct name arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s",arr[i].name);
        scanf("%d",&arr[i].number);
    }

    for(int i =0;i<n-1;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if (arr[i].number>arr[j].number) 
            {
                char nametemp[50];
                strcpy(nametemp,arr[i].name);
                strcpy(arr[i].name,arr[j].name);
                strcpy(arr[j].name,nametemp);
                int temp = arr[i].number;
                arr[i].number = arr[j].number;
                arr[j].number = temp;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%s %d\n",arr[i].name,arr[i].number);
    }

    return 0;
}