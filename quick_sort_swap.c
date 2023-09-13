#include<stdio.h>
#define N 100
void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void quicksort(int a[],int low,int high)
{
    int pivot,start,end;
    if(low<high)
    {
        pivot=low;
        start=low;
        end=high;
        while(start<end)
        {
            while(a[start]<=a[pivot])
                start++;
            while(a[end]>a[pivot])
                end--;
            if(start<end)
                swap(&a[start],&a[end]);
        }
        swap(&a[end],&a[pivot]);
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
        printf("Array size should be between 1 and 100!");
    else
    {
        printf("Enter array elements : \n");
        for(i=0; i<size; i++)
        {
            scanf("%d",&a[i]);
        }
        printf("Array elements before sorting are : \n");
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