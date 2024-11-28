#include<stdio.h>
#include<string.h>
struct operation{
    char stg[100];
};

typedef struct operation exe;

int correct(char arr[]){
    int count1=0;
    int count2=0;
    for (int i = 0; i < strlen(arr); i++)
    {
        if(arr[i]=='(') count1++;
        if(arr[i]==')') count2++;
        if(count2>count1) return 0;
    }
    if (count1==count2)
    {
        return 1;
    }
    else return 0;
    
}

int main(){
    int n;
    int count=0;
    scanf("%d",&n);
    exe arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s",arr[i].stg);
    }
    for (int i = 0; i < n; i++)
    {
        if (correct(arr[i].stg)==1)
        {
            count++;
        }
        
    }
    
    printf("%d",count);

return 0;
}