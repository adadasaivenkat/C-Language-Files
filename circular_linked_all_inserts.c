#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};


// TO DISPLAY THE CIRCULAR LINKED LIST
void print(struct node *head)
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty!!\n");
        return;
    }
    /*else
    {
        printf("Circular linked list : ");
        temp=head;
        do
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        } while(temp!=head);
        printf("\n");
    }*/
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("%d -> ",temp->data);
        printf("\n");
    }
}


// INSERT AT THE BEGINNING
struct node *insert_at_beginning(struct node *head)
{
    struct node *new_node, *temp;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element you want to insert at the beginning : ");
    scanf("%d",&new_node->data);
    if(head==NULL)
    {
        head=new_node;
        head->next=head;        //head->next=new_node;      // Make it circular
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        new_node->next=head;
        head=new_node;
        temp->next=head;    //temp->next=new_node;
    }
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
        head->next=head;    // Make it circular
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=head;    // Make it circular
    }
    return head;        // Return the modified head
}


// INSERT AT A POSITION
struct node *insert_at_pos(struct node *head)
{
    if (head==NULL)
    {
        printf("List is empty, can't insert at a position!\n");
        return head;
    }
    struct node *new_node, *temp;
    int i=1,pos,count=0;
    temp=head;
    do
    {
        count++;
        temp=temp->next;
    }while(temp!=head);
    printf("Enter the position where you want to insert the element : ");
    scanf("%d",&pos);
    if(pos<=0 || pos>count)
    {
        printf("Invalid Position!!\n");
        return head;
    }
    else
    {
        temp=head;
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("Enter the element you want to insert at the position %d : ",pos);
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        if(pos==1)  // Insert at the beginning
        {
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            new_node->next=head;
            head=new_node;
            temp->next=head;    //temp->next=new_node;
        }
        else
        {
            while(i<pos-1)
            {
                i++;
                temp=temp->next;
            }
            new_node->next=temp->next;
            temp->next=new_node;
        }
    }
    return head;
}


// INSERT AFTER AN ELEMENT
struct node *insert_after(struct node *head)
{
    if (head==NULL)
    {
        printf("List is empty, can't insert after an element!\n");
        return head;
    }
    struct node *new_node, *temp;
    temp=head;
    int ele;
    printf("Enter the element after which you want to insert : ");
    scanf("%d",&ele);
    do
    {
        if(temp->data==ele)
        {
            new_node=(struct node *)malloc(sizeof(struct node));
            printf("Enter the element you want to insert after the element %d : ",ele);
            scanf("%d",&new_node->data);
            new_node->next=NULL;
            new_node->next=temp->next;
            temp->next=new_node;
            return head;
        }
        temp=temp->next;
    }while(temp!=head);
    printf("Element %d is not found in the list!\n", ele);
    return head;
}


// INSERT BEFORE AN ELEMENT
struct node *insert_before(struct node *head)
{
    if (head==NULL)
    {
        printf("List is empty, can't insert before an element!\n");
        return head;
    }
    struct node *new_node, *temp, *prev;
    temp=head;
    prev=NULL;
    int ele;
    printf("Enter the element before which you want to insert : ");
    scanf("%d",&ele);
    do
    {
        if(temp->data==ele)
        {
            new_node=(struct node *)malloc(sizeof(struct node));
            printf("Enter the element you want to insert before the element %d : ",ele);
            scanf("%d",&new_node->data);
            new_node->next=NULL;
            if(prev==NULL)
            {
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                new_node->next=head;
                head=new_node;  // If we're inserting before the head, update the head
                temp->next=head;    //Make it circular
            }
            else
            {
                new_node->next=temp;     //new_node->next=prev->next;
                prev->next=new_node;
            }
            return head;
        }
        prev=temp;
        temp=temp->next;
    }while(temp!=head);
    printf("Element %d is not found in the list!\n", ele);
    return head;
}


// MAIN FUNCTION
int main()
{
    struct node *head, *temp, *new_node;
    head=NULL;
    int i,n,choice;
    printf("Enter size of the circular linked list : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("Enter element %d : ",i+1);
        scanf("%d",&new_node->data);
        if(head==NULL)
            head=temp=new_node;
        else
        {
            temp->next=new_node;
            temp=new_node;                     //temp=temp->next;
        }
        temp->next=head;    //Link the last node to the head to make it circular.
    }
    printf("Circular Linked list is : ");
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
                    printf("Circular Linked list is : ");
                    print(head);
                    break;
            case 7:
                    printf("Updated circular linked list is : ");    // Print the updated circular linked list before exiting
                    print(head);
                    exit(0);
                    break;
            default:
                    printf("Entered invalid choice!!\n");
        }
    }
    return 0;
}