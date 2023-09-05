#include<stdio.h>
#define N 10
int main()
{
    int a[N],size,i,ele,pos;
    printf("size");
    scanf("%d",&size);
    printf("enter");
    for(i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("array elements are : ");
    for(i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("Enter the element you want to add : ");
    scanf("%d",&ele);
    printf("enter at which pos : ");
    scanf("%d",&pos);
    if(pos<=0||pos>(size+1))
        printf("INValid");
    else
    {
        for(i=size-1; i>=pos-1; i--)
            a[i+1]=a[i];
        a[pos-1]=ele;
        size++;         
        for(i=0; i<size; i++)
            printf("%d ",a[i]);
        return 0;
    }

}