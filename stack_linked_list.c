#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>


struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;


void push()
{
    int x;
    printf("Enter data : ");
    scanf("%d",&x);
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=x;
    new_node->next=top;
    top=new_node;
    printf("%d pushed onto the stack\n",new_node->data);
    //printf("%d pushed onto the stack\n",x);               //This can also be written...
}


void pop()
{
    if (top==NULL)
    {
        printf("Stack is empty!Cannot pop!!\n");
    }
    else
    {
        printf("%d popped from the stack\n",top->data);
        struct node *temp;
        temp=top;
        top=temp->next;     //top=top->next;
        free(temp);
        temp=NULL;
    }
}


void peek()
{
    if(top==NULL)
    {
        printf("Stack is empty!Cannot peek!!\n");
    }
    else
    {
        printf("Top element : %d\n",top->data);
    }
}


void display()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node *temp;
        temp=top;
        printf("Stack elements : ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}


int main()
{
    int choice;
    while(1)
    {
        printf("STACK OPERATIONS\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    push();
                    break;
            case 2:
                    pop();
                    break;
            case 3:
                    peek();
                    break;
            case 4: 
                    display();
                    break;
            case 5:
                    display();
                    exit(0);
                    break;
            default:
                    printf("Entered an invalid choice!!\n");
        }
    }
    return 0;
}