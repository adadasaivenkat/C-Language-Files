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
            else
            {
                printf("There is no element after %d to delete!\n", ele);
                return head;
            }
        }
        temp=temp->next;
    }while(temp!=head);
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
    head=delete_after(head);
    printf("After deleting an element after an element!!!\n");
    print(head);
    return 0;
}