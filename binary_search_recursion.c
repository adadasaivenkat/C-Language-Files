#include<stdio.h>
#define N 100
int binary(int a[],int search,int low,int high)
{
    while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(search==a[mid])
                return mid;
            else if(search<a[mid])
                return binary(a,search,low,mid-1);
            else
                return binary(a,search,mid+1,high);
        }
    return -1;
}
int main()
{
    int a[N],size,i,low=0,high,mid,search;
    printf("Enter the size of the array max. 100 : ");
    scanf("%d",&size);
    if(size>N)
        printf("Please enter size 100 or less than 100!!");
    else
    {
        printf("Enter array elements in ascending order(sorted order): \n");
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
        mid=binary(a,search,low,high);
        if(mid!=-1)
            printf("ELement %d is at position %d in the array\n",search,mid+1);
        else
            printf("Element %d is not present in the array!!!\n",search);
    }
    return 0;
}
