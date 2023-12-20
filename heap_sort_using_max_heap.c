//HEAP SORT USING MAXIMUM HEAP
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#define N 100
void max_heapify(int a[],int size, int i)
{
    int largest=i,left=(2*i)+1,right=(2*i)+2,temp;
    while(left<size && a[left]>a[largest])
        largest=left;
    while(right<size && a[right]>a[largest])
        largest=right;
    if(largest!=i)
    {
        temp=a[largest];        //Swap(a[largest],a[i])
        a[largest]=a[i];
        a[i]=temp;
        max_heapify(a,size,largest);
    }
}
void heapsort(int a[],int size)
{
    int i,temp;
    //Build the initial max-heap
    for(i=size/2-1; i>=0; i--)
    {
        max_heapify(a,size,i);
    }
    //Delete operation and swapping
    for(i=size-1; i>=0; i--)
    {
        temp=a[i];  //Swap(a[i],a[0]) i.e., last element and first element
        a[i]=a[0];
        a[0]=temp;
        max_heapify(a,i,0);
    }
}
int main()
{
    int a[N],size,i;
    printf("Enter the size of the binary heap max.100 : ");
    scanf("%d",&size);
    if(size<1 || size>N)
    {
        printf("Heap size should be between 1 and 100!");
        exit(1);
    }
    for(i=0; i<size; i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Initial heap is (before sorting) : ");
    for(i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
    heapsort(a,size);
    printf("\n");
    printf("Heap after sorting is : ");
    for(i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}