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
struct node *delete_at_pos(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty!!Cannot delete!!\n");
        return head;
    }
    struct node *temp=head;
    int pos,count=0,i=1;
    printf("Enter the position where you want to delete : ");
    scanf("%d",&pos);
    while(temp!=NULL)       //Count the number of elements in the linked list
    {
        count++;
        temp=temp->next;
    }
    if(pos<1 || pos>count)
    {
        printf("Invalid position!\n");
    }
    else
    {
        if(pos==1)
        {
            temp=head;
            if(temp->next!=NULL)
            {
                temp->next->prev=NULL;
            }
            head=temp->next;
            free(temp);
            temp=NULL;
        }
        else
        {
            temp=head;
            while(i<pos)
            {
                i++;
                temp=temp->next;
            }
            if(temp->next!=NULL)
            {
                temp->next->prev=temp->prev;
            }
            temp->prev->next=temp->next;
            free(temp);
            temp=NULL;
        }
    }
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
    head=delete_at_pos(head);
    printf("Doubly Linked list after deleting at a position is : ");
    print(head);
    return 0;
}