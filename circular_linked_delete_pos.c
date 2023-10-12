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
struct node *delete_at_pos(struct node *head)
{
    if(head==NULL)  // List is empty
    {
        printf("List is empty, can't delete at a position!\n");
        return head;
    }
    struct node *temp, *prev;
    int count=0,pos,i=1;
    printf("Enter the position of the element which you want to delete : ");
    scanf("%d",&pos);
    temp=head;
    prev=NULL;
    do
    {
        count++;
        temp=temp->next;
    } while(temp!=head);
    if(pos<=0 || pos>count)
    {
        printf("Invalid position!\n");
        return head;
    }
    else if(pos==1) // Deleting the first node
    {
        if(head->next==head)
        {
            free(head);       // If there's only one element in the list
            head=NULL;
        }
        else
        {
            temp=head;
            struct node *end;
            end=head;
            while(end->next!=head)
            {
                end=end->next;
            }
            head=head->next;
            end->next=head; // Update the last node to point to the new head
            free(temp);
            temp=NULL;
        }
    }
    else
    {
        // Deleting a node at a position other than 1
        temp=head;
        while(i<pos)
        {
            i++;
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
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
    head=delete_at_pos(head);
    printf("After deleting an element at a position!!!\n");
    print(head);
    return 0;
}