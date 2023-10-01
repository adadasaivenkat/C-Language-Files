#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};


// TO DISPLAY THE LINKED LIST
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


// DELETE AT THE BEGINNING
struct node *delete_at_beginning(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty!!Cannot delete!!\n");
        return NULL;    // return head;
    }
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);
    return head;        // Return the modified head
}


// DELETE AT THE END
struct node *delete_at_end(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty!!Cannot delete!!\n");
        return NULL;    // return head;
    }
    struct node *temp, *prev;
    temp=head;
    prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL)      //if(temp==head)        // Only one node in the list
    {
        head=NULL;
    }
    else
    {
        prev->next=NULL;
    }
    free(temp);
    return head;        // Return the modified head
}


// DELETE AT A POSITION
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
        return head;    // Return the modified head    //exit(1);
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


// DELETE AFTER AN ELEMENT
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
    return head;    // Return the modified head    //exit(1);
}


// DELETE BEFORE AN ELEMENT
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
    return head;    // Return the modified head    //exit(1);
}


// MAIN FUNCTION
int main(void)
{
    int i,n,choice;
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
    while(1)
    {
        printf("1.Delete at the beginning\n");
        printf("2.Delete at the end\n");
        printf("3.Delete at a position\n");
        printf("4.Delete after an element\n");
        printf("5.Delete before an element\n");
        printf("6.Display linked list\n");
        printf("7.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    head=delete_at_beginning(head);
                    break;
            case 2:
                    head=delete_at_end(head);
                    break;
            case 3:
                    head=delete_at_pos(head);
                    break;
            case 4:
                    head=delete_after(head);
                    break;
            case 5:
                    head=delete_before(head);
                    break;
            case 6:
                    printf("Linked list is : ");
                    print(head);
                    break;
            case 7:
                    printf("Updated linked list is : ");    // Print the updated linked list before exiting
                    print(head);
                    exit(0);
                    break;
            default:
                    printf("Entered invalid choice!!\n");
        }
    }
    return 0;
}