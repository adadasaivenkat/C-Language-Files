#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>


struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;


//Function to push an integer onto the stack
void push(int x)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=x;
    new_node->next=top;
    top=new_node;
}


//Function to pop an integer from the stack
int pop()
{
    int popped;
    popped=top->data;
    struct node* temp;
    temp=top;
    top=temp->next;
    free(temp);
    temp=NULL;
    return popped;
}


//Main function
int main()
{
    char postfix[100];
    int index=0,a,b,result;
    printf("Enter the postfix expression to be evaluated : ");
    gets(postfix);
    while(postfix[index]!='\0')
    {
        if(postfix[index]>='0' && postfix[index]<='9')          //If the character is a digit, push it onto the stack
        {
            push(postfix[index]-'0');       // Here, this is written because for example ASCII CODE OF '2' is 50 if you want the integer 2 then you should subtract from '0' which is 48 so,50-48=2 
        }
        else                                                    //If the character is an operator, pop two operands and perform the operation
        {
            a=pop();
            b=pop();
            switch(postfix[index])
            {
                case '+':
                        result=b+a;
                        push(result);
                        break;
                case '-':
                        result=b-a;
                        push(result);
                        break;
                case '*':
                        result=b*a;
                        push(result);
                        break;
                case '/':
                        result=b/a;
                        push(result);
                        break;
                default:
                        break;
            }
        }
        index++;
    }
    //The final result should be on the top of the stack
    result=pop();
    //Print the resulting value
    printf("The result of the postfix expression : %d\n",result);
    return 0;
}