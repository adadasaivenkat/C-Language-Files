#include<stdio.h>
#include<stdlib.h>


#define N 5
int s1[N],s2[N];
int top1=-1,top2=-1;
int count=0;


void push1(int data)
{
    top1++;
    s1[top1]=data;
}


void push2(int data)
{
    top2++;
    s2[top2]=data;
}


int pop1()
{
    return s1[top1--];
}


int pop2()
{
    return s2[top2--];
}


void enqueue()
{
    if(count<N)
    {
        int x;
        printf("Enter data : ");
        scanf("%d",&x);
        push1(x);
        count++;
        printf("%d enqueued onto the queue\n",x);
    }
    else
    {
        printf("Queue is full!Cannot enqueue!!\n");
    }
}


void dequeue()
{
    if(count>0)
    {
        while(top1>=0)
        {
            push2(pop1());
        }
        int item=pop2();
        count--;
        while(top2>=0)
        {
            push1(pop2());
        }
        printf("%d dequeued from the queue\n",item);
    }
    else
    {
        printf("Queue is empty!Cannot dequeue!!\n");
    }
}


void front_ele()
{
    if(count>0)
    {
        while(top1>=0)
        {
            push2(pop1());
        }
        int front=s2[top2];
        while(top2>=0)
        {
            push1(pop2());
        }
        printf("Front element : %d\n",front);
    }
    else
    {
        printf("Queue is empty!Cannot get front element!!\n");
    }
}


void rear_ele()
{
    if(count>0)
    {
        int rear=s1[top1];
        printf("Rear element : %d\n",rear);
    }
    else
    {
        printf("Queue is empty!Cannot get rear element!!\n");
    }
}


void display()
{
    if(count>0)
    {
        int i;
        printf("Queue elements : ");
        for(i=0; i<=top1; i++)
        {
            printf("%d ",s1[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Queue is empty\n");
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
                    break;
        }
    }
    return 0;
}