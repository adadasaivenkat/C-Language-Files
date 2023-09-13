#include<stdio.h>
void merge(int a[],int low,int mid,int high,int size)
{
    int i=low,j=mid+1,k=low,b[size];
    while(i<=mid && j<=high)
    {
        if(a[i]>=a[j])      // Change the comparison operator to >= for descending order
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        while(j<=high)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(k=low; k<=high; k++)
    {
        a[k]=b[k];
    }
}
void merge_sort(int a[],int low,int high,int size)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(a,low,mid,size);
        merge_sort(a,mid+1,high,size);
        merge(a,low,mid,high,size);
    }
}
#define N 100
int main()
{
    int a[N],size,i;
    printf("Enter the size of the array max.100 : ");
    scanf("%d",&size);
    if(size<1 || size>N)
        printf("Array size must be in between 1 and 100!");
    else
    {
        printf("Enter array elements : \n");
        for(i=0; i<size; i++)
        {
            scanf("%d",&a[i]);
        }
        printf("Array elements before sorting are : ");
        for(i=0; i<size; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        merge_sort(a,0,size-1,size);
        printf("Array elements after sorting are : ");
        for(i=0; i<size; i++)
        {
            printf("%d ",a[i]);
        }
    }
    return 0;
}