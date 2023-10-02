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
    temp=head;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n"); // Print "NULL" to indicate the end of the list
}
struct node *reverse(struct node *head)
{
    struct node *temp, *prev, *after;
    temp=head;
    prev=NULL;
    after=NULL;
    if(head==NULL)
    {
        printf("List is empty!!Cannot reverse!!\n");
        return head;
    }
    else
    {
        while(temp!=NULL)
        {
            after=temp->next;
            temp->next=prev;
            prev=temp;
            temp=after;
        }
        head=prev;
    }
    return head;    // Return the modified head
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
    printf("Linked list is : ");
    print(head);
    head=reverse(head);
    printf("Linked list in reverse order is : ");
    print(head);    //Print the list in reverse order..using print function..
    return 0;
}