#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>


struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;


void enqueue()
{
    int x;
    printf("Enter data : ");
    scanf("%d",&x);
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=x;
    new_node->next=NULL;
    if(front==NULL && rear==NULL)
        front=rear=new_node;
    else
    {
        rear->next=new_node;
        rear=new_node;
    }
    printf("%d enqueued onto the queue\n",new_node->data);
    //printf("%d enqueued onto the queue\n",x);               //This can also be written...
}


void dequeue()
{
    if (front==NULL)
    {
        printf("Queue is empty!Cannot dequeue!!\n");
    }
    else
    {
        printf("%d dequeued from the queue\n",front->data); 
        struct node *temp;
        temp=front;
        front=front->next;          //front=temp->next;
        free(temp);
        temp=NULL;
    }
}


void front_ele()
{
    if(front==NULL)
    {
        printf("Queue is empty!Cannot get front element!!\n");
    }
    else
    {
        printf("Front element : %d\n",front->data);
    }
}


void rear_ele()
{
    if(front==NULL)
    {
        printf("Queue is empty!Cannot get rear element!!\n");
    }
    else
    {
        printf("Rear element : %d\n",rear->data);
    }
}


void display()
{
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp;
        temp=front;
        printf("Queue elements : ");
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
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Front or Peek\n");
        printf("4.Rear\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    enqueue();
                    break;
            case 2:
                    dequeue();
                    break;
            case 3:
                    front_ele();
                    break;
            case 4:
                    rear_ele();
                    break;
            case 5: 
                    display();
                    break;
            case 6:
                    display();
                    exit(0);
                    break;
            default:
                    printf("Entered an invalid choice!!\n");
        }
    }
    return 0;
}