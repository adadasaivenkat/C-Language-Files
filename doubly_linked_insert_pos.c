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
struct node *insert_at_pos(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty, can't insert at a position!!\n");
        return head;
    }
    else
    {
        struct node *new_node, *temp;
        temp=head;
        int i=1,count=0,pos;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        printf("Enter the position where you want to insert the element : ");
        scanf("%d",&pos);
        if(pos<1||pos>count)
        {
            printf("Invalid position!!\n");
            return head;
        }
        else
        {
            if(pos==1)
            {
                new_node=(struct node *)malloc(sizeof(struct node));
                printf("Enter the element you want to insert at the position %d : ",pos);
                scanf("%d",&new_node->data);
                new_node->next=NULL;
                new_node->prev=NULL;
                new_node->next=head;
                head->prev=new_node;
                head=new_node;
            }
            else
            {
                temp=head;
                new_node=(struct node *)malloc(sizeof(struct node));
                printf("Enter the element you want to insert at the position %d : ",pos);
                scanf("%d",&new_node->data);
                new_node->next=NULL;
                new_node->prev=NULL;
                while(i<pos-1)
                {
                    i++;
                    temp=temp->next;
                }
                new_node->prev=temp;
                new_node->next=temp->next;
                temp->next->prev=new_node;
                temp->next=new_node;
            }
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
    head=insert_at_pos(head);
    printf("Doubly Linked list after instering a element at a position is : ");
    print(head);
    return 0;
}