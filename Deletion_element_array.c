#include<stdio.h>
#define N 10
int main(void)
{
    int a[N],size,i,pos;
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
        printf("Enter the position of the element that you want to delete : ");
        scanf("%d",&pos);
        if(pos<=0 || pos>size)
            printf("INVALID POSITION!!!\n");
        else
        {
            //a[pos-1]=0;
            for(i=(pos-1); i<size; i++)     //for(i=(pos-1); i<(size-1); i++)
            {
                a[i]=a[i+1];
            } 
            size--;
            printf("Array elements after deleting the element in the position %d : \n",pos);
            for(i=0; i<size; i++)
            {
                printf("%d ",a[i]);
            }
        }
    }
    return 0;
}