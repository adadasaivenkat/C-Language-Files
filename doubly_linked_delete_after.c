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
struct node *delete_after(struct node *head)
{
    if(head==NULL)
    {
        printf("Doubly linked list is empty!!Cannot delete!!\n");
        return NULL;    // return head;
    }
    int ele;
    printf("Enter the element after which you want to delete : ");
    scanf("%d",&ele);
    /*
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
                if(after->next!=NULL)
                {
                    after->next->prev=temp;       //Update the next node's prev pointer
                }
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
    */
    struct node *temp;
    temp=head;
    while(temp!=NULL)
   {
        if(temp->data==ele)
        {
            if(temp->next!=NULL)
            {
                if(temp->next->next!=NULL)
                {
                    temp->next=temp->next->next;
                    free(temp->next->prev);
                    temp->next->prev=temp;
                }
                else
                {
                    free(temp->next);
                    temp->next=NULL;
                }
                return head;
            }
            else
            {
                printf("There is no element after %d to delete!\n", ele);
                return head;
            }
        }
        temp=temp->next;
   }
    printf("Element %d is not found in the list!\n", ele);
    exit(1);    //return head;  // Return the modified head
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
    head=delete_after(head);
    printf("Doubly Linked list after deleting a element after an element is : ");
    print(head);
    return 0;
}