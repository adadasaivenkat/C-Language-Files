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
    {
        printf("List is empty!!\n");
        return;
    }
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
struct node *delete_at_beginning(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty, can't delete!\n");
    }
    else if (head->next==head)     // If there's only one element in the list
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *temp, *end;
        temp=head;
        end=head;
        while(end->next!=head)
        {
            end=end->next;
        }
        head=temp->next;    //head=head->next;
        end->next=head;
        free(temp);
        temp=NULL; 
    }
    return head;
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
    head=delete_at_beginning(head);
    printf("After deleting an element at the beginning!!!\n");
    print(head);
    return 0;
}