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
struct node *insert_before(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty, can't insert before an element!!\n");
        return head;
    }
    struct node *new_node, *temp;
    temp=head;
    int ele;
    printf("Enter the element before which you want to insert : ");
    scanf("%d",&ele);
    while(temp!=NULL)
    {
        if(temp->data==ele)
        {
            new_node=(struct node *)malloc(sizeof(struct node));
            printf("Enter the element you want to insert before %d : ",ele);
            scanf("%d",&new_node->data);
            new_node->prev=temp->prev;
            new_node->next=temp;
            if(temp->prev!=NULL)
            {
                temp->prev->next=new_node;
            }
            temp->prev=new_node;
            if(temp==head)
            {
                // If we're inserting before the head, update the head to be the new_node.
                head=new_node;
            }
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
    head=insert_before(head);
    printf("Doubly Linked list after instering a element before an element is : ");
    print(head);
    return 0;
}