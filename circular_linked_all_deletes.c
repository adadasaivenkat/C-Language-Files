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


// DELETE AT THE BEGINNING
struct node *delete_at_beginning(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty, can't delete!\n");
    }
    else if (head->next==head)     // If there's only one element in the list
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *temp, *end;
        temp=head;
        end=head;
        while(end->next!=head)
        {
            end=end->next;
        }
        head=temp->next;    //head=head->next;
        end->next=head;
        free(temp);
        temp=NULL; 
    }
    return head;
}


// DELETE AT THE END
struct node *delete_at_end(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty, can't delete!\n");
    }
    else if (head->next==head)     // If there's only one element in the list
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *temp, *prev;
        temp=head;
        prev=NULL;
        while(temp->next!=head)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=head;
        free(temp);
        temp=NULL;
    }
    return head;
}


// DELETE AT A POSITION
struct node *delete_at_pos(struct node *head)
{
    if(head==NULL)  // List is empty
    {
        printf("List is empty, can't delete at a position!\n");
        return head;
    }
    struct node *temp, *prev;
    int count=0,pos,i=1;
    printf("Enter the position of the element which you want to delete : ");
    scanf("%d",&pos);
    temp=head;
    prev=NULL;
    do
    {
        count++;
        temp=temp->next;
    } while(temp!=head);
    if(pos<=0 || pos>count)
    {
        printf("Invalid position!\n");
        return head;
    }
    else if(pos==1) // Deleting the first node
    {
        if(head->next==head)
        {
            free(head);       // If there's only one element in the list
            head=NULL;
        }
        else
        {
            temp=head;
            struct node *end;
            end=head;
            while(end->next!=head)
            {
                end=end->next;
            }
            head=head->next;
            end->next=head; // Update the last node to point to the new head
            free(temp);
            temp=NULL;
        }
    }
    else
    {
        // Deleting a node at a position other than 1
        temp=head;
        while(i<pos)
        {
            i++;
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
        temp=NULL;
    }
    return head;
}


// DELETE AFTER AN ELEMENT
struct node *delete_after(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty, can't delete after an element!\n");
        return head;
    }
    struct node *temp, *after;
    temp=head;
    after=NULL;
    int ele;
    printf("Enter the element after which you want to delete : ");
    scanf("%d",&ele);
    do
    {
        if(temp->data==ele)
        {
            after=temp->next;
            if(after!=head)
            {
                temp->next=after->next;
                free(after);
                after=NULL;
                return head;
            }
            else       // Here, else means it will be executed when (after==head)
            {
                temp->next=head->next;
                head=head->next;    // head=temp->next;  // Update head if the element to be deleted is the first element
                free(after);
                after=NULL;
                return head;
            }
        }
        temp=temp->next;
    }while(temp!=head);
    printf("Element %d is not found in the list!\n",ele);
    return head;  
}


// DELETE BEFORE AN ELEMENT
struct node *delete_before(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty, can't delete before an element!\n");
        return head;
    }
    struct node *temp, *prev, *prev_to_prev;
    temp=head;
    prev=NULL;
    prev_to_prev=NULL;
    int ele;
    printf("Enter the element before which you want to delete : ");
    scanf("%d",&ele);
    do
    {
        if(temp->data==ele)
        {
            if(prev!=NULL)
            {
                if(prev_to_prev!=NULL)
                {
                    //prev_to_prev->next=prev->next;  
                    prev_to_prev->next=temp;
                    free(prev);
                    prev=NULL;
                    return head;
                }
                else    // If the previous node is the head, update the head.
                {
                    struct node *end;
                    end=head;
                    while(end->next!=head)
                    {
                        end=end->next;
                    }
                    //head=prev->next;
                    head=temp;
                    end->next=head;
                    free(prev);
                    prev=NULL;
                    return head;
                }
            }
            else                // Here, else means it will be executed when element is the head...
            {
                struct node *e, *e_before;      // Here, 'e' means 'end'... 'end' is already used above so taken a variable 'e'...
                e=head;
                e_before=NULL;
                while(e->next!=head)
                {
                    e_before=e;
                    e=e->next;
                }
                e_before->next=head;
                free(e);
                e=NULL;
                return head;
            }
        }
        prev_to_prev=prev;
        prev=temp;
        temp=temp->next;
    } while(temp!=head);
    printf("Element %d is not found in the list!\n",ele);
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
