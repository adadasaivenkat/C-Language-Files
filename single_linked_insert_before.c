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
struct node *insert_before(struct node *head)
{
    struct node *new_node, *temp, *prev;
    int ele;
    printf("Enter the element before which you want to insert : ");
    scanf("%d",&ele);
    temp=head;
    prev=NULL;
    while(temp!=NULL)
    {
        if(temp->data==ele)
        {
            new_node=(struct node *)malloc(sizeof(struct node));
            printf("Enter the element you want to insert before %d : ",ele);
            scanf("%d",&new_node->data);
            new_node->next=temp;
            if(prev==NULL)
            {
                head=new_node;  // If we're inserting before the head, update the head
            }
            else
            {
                prev->next=new_node;
            }
            return head; // Return the modified head
        }
        prev=temp;
        temp=temp->next;
    }
    // If the element is not found, exit the program with an error code
    printf("Element %d is not found in the list!\n", ele);
    exit(1);
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
    head=insert_before(head);
    printf("Linked list after inserting before an element is : ");
    print(head);
    return 0;
}