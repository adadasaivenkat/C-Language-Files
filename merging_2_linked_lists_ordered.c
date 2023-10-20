#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>


struct node
{
    int data;
    struct node *next;
};


//TO CREATE THE LINKED LIST
struct node *create(int n)
{
    struct node *head, *temp, *new_node;
    head=NULL;
    temp=NULL;
    int i;
    if (n>0)
        printf("ENTER THE ELEMENTS IN SORTED ORDER i.e., IN ASCENDING ORDER!!\n");
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
    return head;
}


//TO DISPLAY THE LINKED LIST
void print(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty!\n");
    }
    else
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
}


//TO MERGE THE TWO LINKED LISTS
void merge(struct node *first_list, struct node *second_list)
{
    struct node *temp_1, *temp_2;
    temp_1=first_list;
    temp_2=second_list;
    if(temp_1==NULL && temp_2==NULL)
    {
        printf("Result linked list is empty!!");
        return;
    }
    while(temp_1!=NULL && temp_2!=NULL)
    {
        if(temp_1->data <= temp_2->data)
        {
            printf("%d -> ",temp_1->data);
            temp_1=temp_1->next;
        }
        else
        {
            printf("%d -> ",temp_2->data);
            temp_2=temp_2->next;
        }
    }
    while(temp_1!=NULL)
    {
        printf("%d -> ",temp_1->data);
        temp_1=temp_1->next;
    }
    while(temp_2!=NULL)
    {
        printf("%d -> ",temp_2->data);
        temp_2=temp_2->next;
    }
    printf("NULL\n");   // Print "NULL" to indicate the end of the list
}


//TO FREE THE MEMORY
void free_list(struct node *head)
{
    while (head!=NULL)
    {
        struct node *temp;
        temp=head;
        head=head->next;
        free(temp);
    }
}


//MAIN FUNCTION
int main()
{
    struct node *first_list, *second_list;
    first_list=NULL;
    second_list=NULL;

    int n1,n2;
    printf("First linked list\n");
    printf("Enter number of elements in the linked list : ");
    scanf("%d",&n1);
    first_list=create(n1);
    printf("The first linked list is : ");
    print(first_list);

    printf("Second linked list\n");
    printf("Enter number of elements in the linked list : ");
    scanf("%d",&n2);
    second_list=create(n2);
    printf("The second linked list is : ");
    print(second_list);
    
    printf("Result linked list after merging is : ");
    merge(first_list,second_list);

    free_list(first_list);
    free_list(second_list);

    return 0;
}