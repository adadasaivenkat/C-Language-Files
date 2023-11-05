#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>


struct node
{
    char data;
    struct node *next;
};
struct node *top=NULL;


//Function to push a character onto the stack
void push(char x)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=x;
    new_node->next=top;
    top=new_node;
}


//Function to pop a character from the stack
char pop()
{
    char popped;
    popped=top->data;
    struct node *temp;
    temp=top;
    top=temp->next;     //top=top->next;
    free(temp);
    temp=NULL;
    return popped;
}


//Function to determine the precedence of an operator
int precedence(char operator)
{
    if(operator=='+' || operator=='-')
        return 1;
    else if(operator=='*' || operator=='/')
        return 2;
    else if(operator=='^')
        return 3;
    else
        return 0;   //Default precedence for other characters
}


//Main function
int main()
{
    char infix[100],postfix[100];
    int index=0,p_index=0;
    printf("Enter an infix expression : ");
    gets(infix);
    push('$');              //Push a dollar sign ('$') onto the stack as a bottom marker
    while(infix[index]!='\0')
    {
        char current;
        current=infix[index];
        switch(current)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                    while(precedence(current)<=precedence(top->data))
                    {
                        postfix[p_index]=pop();
                        p_index++;
                    }
                    push(current);
                    break;
            case '(':
                    push('(');
                    break;
            case ')':
                    while(top->data!='(')
                    {
                        postfix[p_index]=pop();
                        p_index++;
                    }
                    pop();      //Pop the '(' from the stack
                    break;
            default:
                    postfix[p_index]=current;
                    p_index++;
                    break;
        }
        index++;
    }

    //Pop any remaining operators from the stack
    while(top->data!='$')
    {
        postfix[p_index]=pop();
        p_index++;
    }
    postfix[p_index]='\0';

    //Print the resulting postfix expression
    printf("The postfix expression : %s\n",postfix);
    return 0;
}