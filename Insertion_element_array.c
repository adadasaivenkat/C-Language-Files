#include<stdio.h>
#define N 10
int main(void)
{
    int a[N],size,i,num,pos;
    printf("Enter the size of the array max.size is 10 : ");
    scanf("%d",&size);
    if(size>N)
        printf("Please give size 10 or less than 10!!!");
    else
    {
        printf("Enter array elements : \n");
        for(i=0; i<size; i++)
        {
            scanf("%d",&a[i]);
        }
        printf("Array elements are : \n");
        for(i=0; i<size; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        printf("Enter the number you want to insert : ");
        scanf("%d",&num);
        printf("Enter the position you want to insert the number : ");
        scanf("%d",&pos);
        if(pos<=0 || pos>(size+1))
            printf("INVALID POSITION!!!\n");
        else
        {
            for(i=(size-1); i>=(pos-1); i--)
            {
                a[i+1]=a[i];
            } 
            a[pos-1]=num;
            size++;
            printf("Array elements after inserting a number %d in position %d : \n",num,pos);
            for(i=0; i<size; i++)
            {
                printf("%d ",a[i]);
            }
        }
    }
    return 0;
}
    /*
    int a[5],i;
    printf("Enter array elements : \n");
    for(i=0; i<5; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array elements are : \n");
    for(i=0; i<5; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
    */
    /*
    int a[5]={1,2,3,4,5},i;
    printf("Array elements are : \n");
    for(i=0; i<5; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("Array elements in reverse order are : \n");
    for(i=(5-1); i>=0; i--)
    {
        printf("%d ",a[i]);
    }
    return 0;
    */