#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct node
{
    int data;
    struct node *next;
};
void print(struct node *head)
{
    struct node *temp;
    if(head==NULL)
    printf("List is empty!!\n");
    /*else
    {
        printf("Circular linked list : ");
        temp=head;
        do
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        } while(temp!=head);
        printf("\n");
    }*/
    else
    {
        printf("Circular linked list : ");
        temp=head;
        while(temp->next!=head)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("%d -> ",temp->data);
        printf("\n");
    }
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
        head->next=head;    // Make it circular
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=head;    // Make it circular
    }
    return head;        // Return the modified head
}
int main()
{
    struct node *head, *temp, *new_node;
    head=NULL;
    int n,i;
    printf("Enter size of the circular linked list : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("Enter element %d : ",i+1);
        scanf("%d",&new_node->data);
        if(head==NULL)
            head=temp=new_node;
        else
        {
            temp->next=new_node;
            temp=new_node;                     //temp=temp->next;
        }
        temp->next=head;    //Link the last node to the head to make it circular.
    }
    print(head);
    head=insert_at_end(head);
    printf("After inserting an element at the end!!!\n");
    print(head);
    return 0;
}