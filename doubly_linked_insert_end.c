#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void print(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n"); // Print "NULL" to indicate the end of the list
}
struct node *insert_at_end(struct node *head)
{
    struct node *new_node, *temp;
    temp=head;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element you want to insert at the end : ");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    new_node->prev=NULL;
    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->prev=temp;
    }
    return head;        // Return the modified head
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
    printf("Doubly Linked list is : ");
    print(head);
    head=insert_at_end(head);
    printf("Doubly Linked list after instering a element at the end is : ");
    print(head);
    return 0;
}