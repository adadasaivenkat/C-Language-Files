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
struct node *delete_before(struct node *head)
{
    if(head==NULL)
    {
        printf("Doubly linked list is empty!!Cannot delete!!\n");
        return NULL;    // return head;
    }
    int ele;
    printf("Enter the element before which you want to delete : ");
    scanf("%d",&ele);
    /*
    struct node *temp, *before;
    temp=head;
    before=NULL;
    while(temp!=NULL)
    {
        if(temp->data==ele)
        {
            if(before!=NULL)
            {
                if(before->prev!=NULL)
                {
                    //before->prev->next=before->next;    // This also you can use..
                    before->prev->next=temp;
                    free(before);
                    return head;
                }
                else
                {
                    //head=before->next;  // This also you can use..
                    head=temp;
                    free(before);
                    return head;
                }
            }
            else
            {
                printf("There is no element before %d to delete!\n",ele);
                return head;
            }
        }
        before=temp;
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
            if(temp->prev!=NULL)
            {
                if(temp->prev->prev!=NULL)
                {
                    temp->prev->prev->next=temp;
                    free(temp->prev);
                    return head;
                }
                else
                {
                    head=temp;
                    free(temp->prev);
                    return head;
                }
            }
            else
            {
                printf("There is no element before %d to delete!\n",ele);
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
    head=delete_before(head);
    printf("Doubly Linked list after deleting a element before an element is : ");
    print(head);
    return 0;
}