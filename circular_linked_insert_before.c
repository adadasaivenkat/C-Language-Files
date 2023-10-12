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
struct node *insert_before(struct node *head)
{
    if (head==NULL)
    {
        printf("List is empty, can't insert before an element!\n");
        return head;
    }
    struct node *new_node, *temp, *prev;
    temp=head;
    prev=NULL;
    int ele;
    printf("Enter the element before which you want to insert : ");
    scanf("%d",&ele);
    do
    {
        if(temp->data==ele)
        {
            new_node=(struct node *)malloc(sizeof(struct node));
            printf("Enter the element you want to insert before the element %d : ",ele);
            scanf("%d",&new_node->data);
            new_node->next=NULL;
            if(prev==NULL)
            {
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                new_node->next=head;
                head=new_node;  // If we're inserting before the head, update the head
                temp->next=head;    //Make it circular
            }
            else
            {
                new_node->next=temp;     //new_node->next=prev->next;
                prev->next=new_node;
            }
            return head;
        }
        prev=temp;
        temp=temp->next;
    }while(temp!=head);
    printf("Element %d is not found in the list!\n", ele);
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
    head=insert_before(head);
    printf("After inserting an element before an element!!!\n");
    print(head);
    return 0;
}