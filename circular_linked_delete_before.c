#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct node
{
    int data;
    struct node *next;
};
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
        printf("Circular linked list : ");
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
int main()
{
    struct node *head, *temp, *new_node;
    head=NULL;
    int n,i;
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
    print(head);
    head=delete_before(head);
    printf("After deleting an element before an element!!!\n");
    print(head);
    return 0;
}
