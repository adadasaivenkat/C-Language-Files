#include<stdio.h>
int fun(int n)
{
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else
        return (fun(n-1)+fun(n-2));
}
int main()
{
    int n,i;
    printf("Enter a number : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        if(fun(i)<n)
        {
            printf("%d ",fun(i));
        }
    }
    return 0;
}