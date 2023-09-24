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


// INSERT AT THE BEGINNING
struct node *insert_at_beginning(struct node *head)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element you want to insert at the beginning : ");
    scanf("%d",&new_node->data);
    new_node->next=head;
    head=new_node;
    return head;        // Return the modified head
}


// INSERT AT THE END
struct node *insert_at_end(struct node *head)
{
    struct node *new_node, *temp;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element you want to insert at the end : ");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }
    return head;        // Return the modified head
}


// INSERT AT A POSITION
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
        return head;            //exit(1);
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


// INSERT AFTER AN ELEMENT
struct node *insert_after(struct node *head)
{
    struct node *new_node, *temp;
    int ele;
    printf("Enter the element after which you want to insert : ");
    scanf("%d",&ele);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==ele)
        {
            new_node=(struct node *)malloc(sizeof(struct node));
            printf("Enter the element you want to insert after %d : ",ele);
            scanf("%d",&new_node->data);
            new_node->next=temp->next;
            temp->next=new_node;
            return head;        // Return the modified head
        }
        temp=temp->next;
    }
    // If the element is not found, exit the program with an error code
    printf("Element %d is not found in the list!\n", ele);
    return head;            //exit(1);
}


// INSERT BEFORE AN ELEMENT
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
    return head;            //exit(1);
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
        printf("1.Insert at the beginning\n");
        printf("2.Insert at the end\n");
        printf("3.Insert at a position\n");
        printf("4.Insert after an element\n");
        printf("5.Insert before an element\n");
        printf("6.Display linked list\n");
        printf("7.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    head=insert_at_beginning(head);
                    break;
            case 2:
                    head=insert_at_end(head);
                    break;
            case 3:
                    head=insert_at_pos(head);
                    break;
            case 4:
                    head=insert_after(head);
                    break;
            case 5:
                    head=insert_before(head);
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