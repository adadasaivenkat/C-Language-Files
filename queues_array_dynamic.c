#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>


int *queue=NULL;
int front=-1,rear=-1;


void enqueue(int N)
{
    if (rear==(N-1))
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
        rear++;
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
        front++;
        printf("%d dequeued from the queue\n",item);
    }
}


void peek()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty!Cannot peek!!\n");
    }
    else
    {
        printf("Front element : %d\n",queue[front]);
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
        int i;
        //printf("Queue size : %d\n",rear-front+1);
        printf("Queue elements : ");
        for(i=front; i<rear+1; i++)         //for(i=front; i<=rear; i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}


int main()
{
    int N;
    printf("Enter the queue size : ");
    scanf("%d",&N);
    queue=(int *)malloc(N*sizeof(int));
    if(queue==NULL)
    {
        printf("Memory allocation failed!Exiting!!\n");
        exit(1);
    }
    int choice;
    while(1)
    {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Front or Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    enqueue(N);
                    break;
            case 2:
                    dequeue();
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