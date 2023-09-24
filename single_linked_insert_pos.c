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
struct node *insert_at_pos(struct node *head)
{
    struct node *new_node, *temp;
    int pos,count=0,i=1;
    temp=head;
    while(temp!=NULL)       //Count the number of elements in the linked list
    {
        count++;
        temp=temp->next;
    }
    //printf("No.of elements in the linked list is : %d\n",count);
    printf("Enter the position where you want to insert : ");
    scanf("%d",&pos);
    if(pos<=0 || pos>count+1)
    /*
    If you want to disallow insertion at the end of the list (only allow positions 1 to count), you can 
    change the condition to pos <= 0 || pos > count. This would prevent inserting a node after the last element.
    */
    {
        printf("Invalid position!\n");
        exit(1);
    }
    if(pos==1)
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("Enter the element you want to insert at the position %d : ",pos);
        scanf("%d",&new_node->data);
        new_node->next=head;
        head=new_node;
    }
    else
    {
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("Enter the element you want to insert at the position %d : ",pos);
        scanf("%d",&new_node->data);
        new_node->next=temp->next;
        temp->next=new_node;
    }
    return head;        // Return the modified head
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
    head=insert_at_pos(head);
    printf("Linked list after instering a element at position is : ");
    print(head);
    return 0;
}