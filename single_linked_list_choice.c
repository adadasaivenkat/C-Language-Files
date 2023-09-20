#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main(void)
{
    char choice;
    struct node *head, *new_node, *temp;
    head=NULL;
    printf("Do you want to continue adding elements(y/n) : ");
    scanf(" %c",&choice);           // Note the space before %c to consume the newline character
    while(choice=='y'||choice=='Y')
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("Enter element : ");
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        if(head==NULL)
            head=temp=new_node;
        else
        {
            temp->next=new_node;
            temp=new_node;
        }
        printf("Do you want to continue adding elements(y/n) : ");
        scanf(" %c",&choice);           // Note the space before %c to consume the newline character
    }
    temp=head;
    printf("Linked list is : ");
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n"); // Print "NULL" to indicate the end of the list
    return 0;
}