#include<stdio.h>
#define N 100
int main()
{
    int a[N],size,i,search,temp=0,found=0;
    printf("Enter the size of the array max is 100 : ");
    scanf("%d",&size);
    if(size>N)
        printf("Please enter size 100 or less than 100!!");
    else
    {
        printf("Enter array elements ; \n");
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
        printf("Enter the element you want to search in the array : ");
        scanf("%d",&search);
        for(i=0; i<size; i++)
        {
            if(search==a[i])
            {
                found=1;
                temp=(i+1);
                break;
            }
        }
        if(found==1)
            printf("Element %d is at position %d in the array\n",search,temp);
        else
            printf("Element %d is not present in the array!\n",search);
        return 0;
    }
}