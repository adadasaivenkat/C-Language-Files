#include<stdio.h>
#define N 100
int main()
{
    int a[N],size,i,low=0,high,mid,search,found=0,temp=0;
    printf("Enter the size of the array max. 100 : ");
    scanf("%d",&size);
    if(size>N)
        printf("Please enter size 100 or less than 100!!");
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
        printf("Enter the element you want to search in the array : ");
        scanf("%d",&search);
        high=size-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(search==a[mid])
            {
                found=1;
                temp=mid;
                break;
            }
            else if(search<a[mid])
                high=mid-1;
            else
                low=mid+1;  
        }
        if(found==1)
            printf("ELement %d is at position %d in the array\n",search,temp+1);
        else
            printf("Element %d is not present in the array!!!",search);
    }
    return 0;
}