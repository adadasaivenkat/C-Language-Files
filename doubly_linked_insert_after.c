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
struct node *insert_after(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty, can't insert after an element!!\n");
        return head;
    }
    struct node *new_node, *temp;
    temp=head;
    int ele;
    printf("Enter the element after which you want to insert : ");
    scanf("%d",&ele);
    while(temp!=NULL)
    {
        if(temp->data==ele)
        {
            new_node=(struct node *)malloc(sizeof(struct node));
            printf("Enter the element you want to insert after %d : ",ele);
            scanf("%d",&new_node->data);
            new_node->prev=temp;
            new_node->next=temp->next;
            if(temp->next!=NULL)
            {
                temp->next->prev=new_node;
            }
            temp->next=new_node;
            return head;    // Return the modified head
        }
        temp=temp->next;
    }
    printf("Element %d is not found in the list!\n", ele);
    return head;
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
    head=insert_after(head);
    printf("Doubly Linked list after instering a element after an element is : ");
    print(head);
    return 0;
}