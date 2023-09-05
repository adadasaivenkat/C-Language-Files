#include<stdio.h>
#include<math.h>
int count=0;
int main()
{
    int n,i;
    printf("Enter a number to check whether the number is prime or not : ");
    scanf("%i",&n);
    for(i=1; i<=n; i++)
    {
        if(n%i==0)
            count++;
    }
    if(count==2)
    {
        printf("Prime");
    }
    else
        printf("Not prime");
}
