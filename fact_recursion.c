#include<stdio.h>
// int fun(int n,int i)
int fun(int n)
{
    if(n<=1)
        return n;
    else
        return n*fun(n-1);
    /*
    int fact=1;
    for(int i=n; i>=1; i--)
    fact=fact*i;
    printf("%d",fact);
    */  
}
int main()
{
    int n,i;
    printf("Enter a number : ");
    scanf("%d",&n);
    //fun(n,i);
    printf("%d",fun(n));
    return 0;
}