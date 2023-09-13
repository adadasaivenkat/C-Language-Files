#include<stdio.h>
#define N 100
void quicksort(int a[],int low,int high)
{
    int pivot,start,end,temp;
    if(low<high)
    {
        pivot=high;         // Choose the pivot as the high index for descending order
        start=low;
        end=high;
        while(start<end)
        {
            while(a[start]>=a[pivot])
                start++;
            while(a[end]<a[pivot])
                end--;
            if(start<end)
            {
                temp=a[start];
                a[start]=a[end];
                a[end]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[end];
        a[end]=temp;
        quicksort(a,low,end-1);          //Recursively sort the left and right subarrays
        quicksort(a,end+1,high);
    }
}
int main()
{
    int a[N],size,i;
    printf("Enter the size of the array max. 100 : ");
    scanf("%d",&size);
    if(size<1 || size>N)
    {
        printf("Array size should be between 1 and 100!");
        return 1;
    }
    else
    {
        printf("Enter array elements : \n");
        for(i=0; i<size; i++)
        {
            scanf("%d",&a[i]);
        }
        printf("Array elements after sorting in descending order:\n");
        for(i=0; i<size; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        quicksort(a,0,size-1); //low=0, high=size-1
        printf("Array elements after sorting are : \n");
        for(i=0; i<size; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}