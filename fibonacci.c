#include<stdio.h>
int main()
{
    int n,i,sum;
    int x1=0,x2=1;
    printf("Enter a number : ");
    scanf("%d",&n);
    printf("%d %d ",x1,x2);
    for(i=0; i<(n-2); i++) // for(i=1; i<=(n-2); i++)
    {
        sum=(x1+x2);
        printf("%d ",sum);
        x1=x2;
        x2=sum;
    }
    return 0;
}