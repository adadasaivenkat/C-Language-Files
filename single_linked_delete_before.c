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
struct node *delete_before(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty!!Cannot delete!!\n");
        return NULL;    // return head;
    }
    int ele;
    printf("Enter the element before which you want to delete : ");
    scanf("%d",&ele);
    struct node *temp, *prev, *prev_to_prev;
    temp=head;
    prev=NULL;
    prev_to_prev=NULL;
    while(temp!=NULL)
    {
        if(temp->data==ele)
        {
            if(prev!=NULL)
            {
                if(prev_to_prev!=NULL)
                {
                    //prev_to_prev->next=prev->next;  // This also you can use..
                    prev_to_prev->next=temp;
                    free(prev);
                    return head;    // Return the modified head
                }
                else
                {
                    //head=prev->next;  // This also you can use..
                    head=temp;
                    free(prev);
                    return head;    // Return the modified head
                }
            }
            else
            {
                printf("There is no element before %d to delete!\n", ele);
                return head;    // Return the modified head
            }
        }
        prev_to_prev=prev;
        prev=temp;
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
    head=delete_before(head);
    printf("Linked list after deleting a element before an element is : ");
    print(head);
    return 0;
}