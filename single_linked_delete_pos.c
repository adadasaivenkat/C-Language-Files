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
struct node *delete_at_pos(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty!!Cannot delete!!\n");
        return NULL;    // return head;
    }
    struct node *temp, *prev;
    int pos,i=1,count=0;
    temp=head;
    prev=NULL;
    while(temp!=NULL)       //Count the number of elements in the linked list
    {
        count++;
        temp=temp->next;
    }
    printf("Enter the position where you want to delete : ");
    scanf("%d",&pos);
    if(pos<=0 || pos>count)
    {
        printf("Invalid position!\n");
        exit(1);
    }
    temp=head;
    if(pos==1)
    {
        head=temp->next;
        free(temp); // Free the memory of the deleted node
    }
    else
    {
        while(i<pos)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        free(temp); // Free the memory of the deleted node
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
    printf("Linked list before deleting is : ");
    print(head);
    head=delete_at_pos(head);
    printf("Linked list after deleting a element at a position is : ");
    print(head);
    return 0;
}