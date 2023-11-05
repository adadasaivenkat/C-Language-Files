#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>


#define N 5     //Define the queue size
int queue[N];
int front=-1,rear=-1;


void enqueue()
{
    if(((rear+1)%N)==front)
    {
        printf("Queue is full!Cannot enqueue!!\n");
    }
    else if(front==-1 && rear==-1)
    {
        int x;
        printf("Enter data : ");
        scanf("%d",&x);
        front=rear=0;
        queue[rear]=x;
        printf("%d enqueued onto the queue\n",x);
    }
    else
    {
        int x;
        printf("Enter data : ");
        scanf("%d",&x);
        rear=(rear+1)%N;
        queue[rear]=x;
        printf("%d enqueued onto the queue\n",x);
    }
}


void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty!Cannot dequeue!!\n");
    }
    else if(front==rear)
    {
        int item;
        item=queue[front];
        front=rear=-1;
        printf("%d dequeued from the queue\n",item); 
    }
    else
    {
        int item;
        item=queue[front];
        front=(front+1)%N;
        printf("%d dequeued from the queue\n",item);
    }
}


void front_ele()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty!Cannot get front element!!\n");
    }
    else
    {
        printf("Front element : %d\n",queue[front]);
    }
}


void rear_ele()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty!Cannot get rear element!!\n");
    }
    else
    {
        printf("Rear element : %d\n",queue[rear]);
    }
}


void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i=front;
        printf("Queue elements : ");
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }
        printf("%d\n",queue[rear]);
    }
}


int main()
{
    printf("Queue size : %d\n",N);      //Inform the user about the queue size
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