#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
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
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element you want to insert at the end : ");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }
    return head;        // Return the modified head
}
int main(void)
{
    int i,n;
    struct node *head, *new_node, *temp;
    head=NULL;
    printf("Enter number of elements in the linked list : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("Enter element %d : ",i+1);
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        if(head==NULL)
            head=temp=new_node;
        else
        {
            temp->next=new_node;
            temp=new_node;  //temp=temp->next;
        }
    }
    printf("Linked list before instering is : ");
    print(head);
    head=insert_at_end(head);
    printf("Linked list after instering a element at the end is : ");
    print(head);
    return 0;
}