#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};


// TO DISPLAY THE LINKED LIST (OR) TRAVERSAL
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


// REVERSE THE LINKED LIST
struct node *reverse(struct node *head)
{
    struct node *temp, *prev, *after;
    temp=head;
    prev=NULL;
    after=NULL;
    if(head==NULL)
    {
        printf("List is empty!!Cannot reverse!!\n");
        return head;
    }
    else
    {
        while(temp!=NULL)
        {
            after=temp->next;
            temp->next=prev;
            prev=temp;
            temp=after;
        }
        head=prev;
    }
    return head;    // Return the modified head
}


// SEARCH AN ELEMENT IN THE LIST
void search_ele(struct node *head)
{
    if (head==NULL)
    {
        printf("List is empty!!Cannot search for elements!!\n");
        return; // Exiting the function without returning a value...
    }
    int search,found=0,pos=0;
    printf("Enter the element you want to search in the list : ");
    scanf("%d",&search);
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==search)
        {
            printf("Element %d is found at position %d in the list!!\n",search,pos+1);
            found=1;
            break;
        }
        pos++;
        temp=temp->next;
    }
    if(found!=1)
        printf("Element %d is not found in the list!!\n",search);
}


// LENGTH OF THE LINKED LIST
void length(struct node *head)
{
    struct node *new_node, *temp;
    int count=0;
    temp=head;
    while(temp!=NULL)       //Count the number of elements in the linked list
    {
        count++;
        temp=temp->next;
    }
    printf("Length of the linked list is %d\n",count);
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
        printf("**********OPTIONS**********\n");
        printf("1.Display linked list (or) Traversal\n");
        printf("2.Insert at the beginning\n");
        printf("3.Insert at the end\n");
        printf("4.Insert at a position\n");
        printf("5.Insert after an element\n");
        printf("6.Insert before an element\n");
        printf("7.Delete at the beginning\n");
        printf("8.Delete at the end\n");
        printf("9.Delete at a position\n");
        printf("10.Delete after an element\n");
        printf("11.Delete before an element\n");
        printf("12.Reverse the linked list\n");
        printf("13.Search an element in the list\n");
        printf("14.Length of the linked list\n");
        printf("15.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("Linked list is : ");
                    print(head);
                    break;
            case 2:
                    head=insert_at_beginning(head);
                    break;
            case 3:
                    head=insert_at_end(head);
                    break;
            case 4:
                    head=insert_at_pos(head);
                    break;
            case 5:
                    head=insert_after(head);
                    break;
            case 6:
                    head=insert_before(head);
                    break;
            case 7:
                    head=delete_at_beginning(head);
                    break;
            case 8:
                    head=delete_at_end(head);
                    break;
            case 9:
                    head=delete_at_pos(head);
                    break;
            case 10:
                    head=delete_after(head);
                    break;
            case 11:
                    head=delete_before(head);
                    break;
            case 12:
                    head=reverse(head);
                    break;
            // case 13 and case 14 are for searching and counting the linked list...
            case 13:
                    search_ele(head);
                    break;
            case 14:
                    length(head);
                    break;
            case 15:
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