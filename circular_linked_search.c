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
    do
    {
        if(temp->data==search)
        {
            printf("Element %d is found at position %d in the list!!\n",search,pos+1);
            found=1;
            break;
        }
        pos++;
        temp=temp->next;
    }while(temp!=head);
    if(found!=1)
        printf("Element %d is not found in the list!!\n",search);
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
    search_ele(head);
    return 0;
}