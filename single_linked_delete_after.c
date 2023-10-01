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
struct node *delete_after(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty!!Cannot delete!!\n");
        return NULL;    // return head;
    }
    int ele;
    printf("Enter the element after which you want to delete : ");
    scanf("%d",&ele);
    struct node *temp, *after;
    temp=head;
    after=NULL;
    while(temp!=NULL)
    {
        if(temp->data==ele)
        {
            after=temp->next;
            if(after!=NULL)
            {
                temp->next=after->next;
                free(after);
                return head;    // Return the modified head
            }
            else
            {
                printf("There is no element after %d to delete!\n", ele);
                return head;    // Return the modified head
            }
        }
        temp=temp->next;
    }
    // If the element is not found, exit the program with an error code
    printf("Element %d is not found in the list!\n", ele);
    exit(1);    //return head;  // Return the modified head
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
    head=delete_after(head);
    printf("Linked list after deleting a element after an element is : ");
    print(head);
    return 0;
}