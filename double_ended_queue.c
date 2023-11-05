// Here, dequeue means Double Ended Queue
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


struct node *create(int data)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}


void insert_at_front()
{
    int x;
    printf("Enter data : ");
    scanf("%d",&x);
    struct node *new_node;
    new_node=create(x);
    if(front==NULL)
    {
        front=rear=new_node;
    }
    else
    {
        new_node->next=front;
        front=new_node;
    }
    printf("%d inserted at the front of the dequeue\n",new_node->data);  // dequeue means Double Ended Queue
}


void insert_at_rear()
{
    int x;
    printf("Enter data : ");
    scanf("%d",&x);
    struct node *new_node;
    new_node=create(x);
    if(rear==NULL)
    {
        front=rear=new_node;
    }
    else
    {
        rear->next=new_node;
        rear=new_node;
    }
    printf("%d inserted at the rear of the dequeue\n",new_node->data);
}


void delete_at_front()
{
    if(front==NULL)
    {
        printf("Dequeue is empty!Cannot delete!!\n");
    }
    else if(front==rear)
    {
        printf("%d deleted at the front of the dequeue\n",front->data); 
        free(front);
        front=rear=NULL;
    }
    else
    {
        printf("%d deleted at the front of the dequeue\n",front->data); 
        struct node *temp;
        temp=front;
        front=front->next;          //front=temp->next;
        free(temp);
        temp=NULL;
    }
}


void delete_at_rear()
{
    if(rear==NULL)
    {
        printf("Dequeue is empty!Cannot delete!!\n");
    }
    else if(rear==front)
    {
        printf("%d deleted at the rear of the dequeue\n",rear->data); 
        free(rear);
        front=rear=NULL;
    }
    else
    {
        printf("%d deleted at the rear of the dequeue\n",rear->data); 
        struct node *temp, *prev;
        prev=NULL;
        temp=front;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        free(temp);
        temp=NULL;
        rear=prev;
        rear->next=NULL;
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
        printf("Deqeue is empty\n");
    }
    else
    {
        struct node *temp;
        temp=front;
        printf("Dequeue elements : ");
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
        printf("1.Insert at front\n");
        printf("2.Insert at rear\n");
        printf("3.Delete at front\n");
        printf("4.Delete at rear\n");
        printf("5.Front or Peek\n");
        printf("6.Rear\n");
        printf("7.Display\n");
        printf("8.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    insert_at_front();
                    break;
            case 2:
                    insert_at_rear();
                    break;
            case 3:
                    delete_at_front();
                    break;
            case 4: 
                    delete_at_rear();
                    break;
            case 5:
                    front_ele();
                    break;
            case 6:
                    rear_ele();
                    break;
            case 7: 
                    display();
                    break;
            case 8:
                    display();
                    exit(0);
                    break;
            default:
                    printf("Entered an invalid choice!!\n");
        }
    }
    return 0;
}