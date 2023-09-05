#include<stdio.h>
#define N 100
int linear(int a[],int search,int index,int size)
{
    if(index>=size)
        return -1;
    if(search==a[index])
        return index;
    else
        return linear(a,search,index+1,size);
}
int main()
{
    int a[N],size,i,search,index=0;
    printf("Enter the size of the array max is 100 : \n");
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
        printf("Enter the element that you want to search from the array : ");
        scanf("%d",&search);
        index=linear(a,search,index,size);
        if(index!=-1)
            printf("Element %d is at position %d in the array\n",search,index+1);
        else
            printf("Element %d is not present in the array!\n",search);
    }
    return 0;
}
