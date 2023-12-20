//BINARY HEAP USING MAXIMUM HEAP
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<math.h>
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
int insert(int a[],int size)
{
    if(size==N)
    {
        printf("Heap is already at the maximum size!cannot insert!\n");
        return size;
    }
    int value,i,parent,temp;
    printf("Enter the value you want to insert in the heap : ");
    scanf("%d",&value);
    size++;
    a[size-1]=value;
    i=size-1;
    while(i>0)
    {
        parent=floor((i-1)/2);
        if(a[parent]<a[i])
        {
            temp=a[parent];         //Swap(a[parent],a[i])
            a[parent]=a[i];
            a[i]=temp;
            i=parent;
        }
        else
        {
            break;
        }
    }
    for(i=size/2-1; i>=0; i--)
    {
        max_heapify(a,size,i);
    }
    return size;
}
int delete(int a[],int size)
{
    int i,temp;
    if(size==0)
    {
        printf("Heap is empty!cannot delete!!\n");
        return size;
    }
    printf("%d is deleted from the heap\n",a[0]);
    temp=a[size-1];     //Swap(a[size-1],a[0]) i.e., last element and first element
    a[size-1]=a[0];
    a[0]=temp;
    size--;
    max_heapify(a,size,0);
    return size;
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
    //Build the initial max-heap
    for(i=size/2-1; i>=0; i--)
    {
        max_heapify(a,size,i);
    }
    printf("Initial heap is : ");
    for(i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    size=insert(a,size);
    printf("Heap after insertion operation is : ");
    for(i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    size=delete(a,size);
    printf("Heap after deletion operation is : ");
    for(i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}