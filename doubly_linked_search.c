#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void search_ele(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty!!Cannot search for elements!!\n");
        return; // Exiting the function without returning a value...
    }
    int search,found=0,pos=0;
    printf("Enter the element you want to search in the list : ");
    scanf("%d",&search);
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==search)
        {
            printf("Element %d is found at position %d in the list!!\n",search,pos+1);
            found=1;
            break;
        }
        pos++;
        temp=temp->next;
    }
    if(found!=1)
        printf("Element %d is not found in the list!!\n",search);
}
int main(void)
{
    int i,n;
    struct node *head, *new_node, *temp;
    head=NULL;
    temp=NULL;
    printf("Enter number of elements in the doubly linked list : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("Enter element %d : ",i+1);
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        new_node->prev=NULL;
        if(head==NULL)
            head=temp=new_node;
        else
        {
            temp->next=new_node;
            new_node->prev=temp;
            temp=new_node;  //temp=temp->next;
        }
    }
    temp=head;
    printf("Doubly Linked list is : ");
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n"); // Print "NULL" to indicate the end of the list
    // Call the search_ele function to search for an element
    search_ele(head);
    return 0;
}