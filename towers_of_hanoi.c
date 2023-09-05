#include<stdio.h>
void hanoi(int n,char s,char a,char d)
{
    if(n==1)
        printf("Move disk %d from %c to %c\n",n,s,d);
    else
    {
        hanoi(n-1,s,d,a);
        printf("Move disk %d from %c to %c\n",n,s,d);
        hanoi(n-1,a,s,d);
    }
}
int main()
{
    int n;
    printf("Enter no of disks : ");
    scanf("%d",&n);
    hanoi(n,'s','a','d');
}