#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct sparse_poly
{
    int coef;
    int expo;
    struct sparse_poly *next;
};
void display_poly(struct sparse_poly *head)
{
    if(head==NULL)
    {
        printf("Empty polynomial!\n");
        return;
    }
    struct sparse_poly *temp;
    temp=head;
    printf("The polynomial is : ");
    while(temp!=NULL)
    {
        if(temp->next!=NULL)
        {
            printf("%dx^%d + ",temp->coef,temp->expo);
        }
        else
        {
            printf("%dx^%d",temp->coef,temp->expo);
        }
        temp=temp->next;
    }
    printf("\n");
}
void free_list(struct sparse_poly *head)
{
    while (head!=NULL)
    {
        struct sparse_poly *temp;
        temp=head;
        head=head->next;
        free(temp);
    }
}
int main()
{
    int n,i;
    printf("Enter the number of non-sparse terms : ");
    scanf("%d",&n);
    struct sparse_poly *head, *temp, *ns_term;  //ns_term=non sparse term
    head=NULL;
    temp=NULL;
    for(i=0; i<n; i++)
    {
        ns_term=(struct sparse_poly *)malloc(sizeof(struct sparse_poly));
        printf("Enter the coefficient and exponent of the non-sparse term %d : \n",i+1);
        scanf("%d %d",&ns_term->coef, &ns_term->expo);
        ns_term->next=NULL;
        if(head==NULL)
            head=ns_term;
        else
        {
            struct sparse_poly *temp, *prev;
            temp=head;
            prev=NULL;
            while(temp!=NULL && ns_term->expo < temp->expo)
            {
                prev=temp;
                temp=temp->next;
            }
            if(prev==NULL)
            {
                ns_term->next=temp;
                head=ns_term;
            }
            else
            {
                ns_term->next=temp;
                prev->next=ns_term;
            }
        }
    }
    display_poly(head);
    free_list(head);
    return 0;
}