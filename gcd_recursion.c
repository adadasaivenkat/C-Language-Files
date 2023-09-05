#include<stdio.h>
int gcd(int n1,int n2)
{
    if(n2==0)
        return n1;
    else
        return gcd(n2,n1%n2);
}
int main()
{
    int n1,n2;
    printf("Enter any two numbers : \n");
    scanf("%d %d",&n1,&n2);
    printf("G.C.D of %d and %d is %d\n",n1,n2,gcd(n1,n2));
    return 0;
}