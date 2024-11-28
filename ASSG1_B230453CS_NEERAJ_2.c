#include<stdio.h>
#include<string.h>


struct book
{
    char name[30];
};

int main() 
{
    int n;
    scanf("%d",&n);
    
    char sn;
    scanf("%c",&sn);
    

    struct book books[n];

    for(int i=0;i<n;i++) gets(books[i].name);
    

    for(int i=1;i<n;i++)
    {
        char temp[30];
        strcpy(temp,books[i].name);
        int j = i-1;
        
        while(j>=0 && strcmp(books[j].name,temp)>0 )
        {
            strcpy(books[j+1].name,books[j].name);
            j--;
        }
        strcpy(books[j+1].name,temp);
    }

    

    for (int i = 0; i < n; i++) 
    {
        printf("%s\n", books[i].name);
    }
    return 0;
}