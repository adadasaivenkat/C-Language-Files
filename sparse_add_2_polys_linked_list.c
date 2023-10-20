#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>


struct sparse_poly
{
    int coef;
    int expo;
    struct sparse_poly *next;
};


//TO CREATE THE POLYNOMIAL
struct sparse_poly *create(int n)
{
    struct sparse_poly *head, *ns_term;  //ns_term=non sparse term
    head=NULL;
    int i;
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
    return head;
}


//TO DISPLAY THE POLYNOMIAL
void display_poly(struct sparse_poly *head)
{
    if(head==NULL)
    {
        printf("Empty polynomial!\n");
        return;
    }
    struct sparse_poly *temp;
    temp=head;
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


//TO ADD TWO POLYNOMIALS 
void add(struct sparse_poly *first_poly, struct sparse_poly *second_poly)
{
    struct sparse_poly *temp_1, *temp_2;
    temp_1=first_poly;
    temp_2=second_poly;
    while(temp_1!=NULL && temp_2!=NULL)
    {
        if(temp_1->expo == temp_2->expo)
        {
            printf("%dx^%d",(temp_1->coef+temp_2->coef),temp_1->expo);     //You can write temp_2->expo...Because, both exponents are same...
            temp_1=temp_1->next;
            temp_2=temp_2->next;
        }
        else if(temp_1->expo > temp_2->expo)
        {
            printf("%dx^%d",temp_1->coef,temp_1->expo);
            temp_1=temp_1->next;
        }
        else
        {
            printf("%dx^%d",temp_2->coef,temp_2->expo);
            temp_2=temp_2->next;
        }
        if(temp_1!=NULL || temp_2!=NULL)
        {
            printf(" + ");
        }
    }
    while(temp_1!=NULL)
    {
        printf("%dx^%d",temp_1->coef,temp_1->expo);
        temp_1=temp_1->next;
        if(temp_1!=NULL)
        {
            printf(" + ");
        }
    }
    while(temp_2!=NULL)
    {
        printf("%dx^%d",temp_2->coef,temp_2->expo);
        temp_2=temp_2->next;
        if(temp_2!=NULL)
        {
            printf(" + ");
        }
    }
}


//TO FREE THE MEMORY
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


//MAIN FUNCTION
int main()
{
    struct sparse_poly *first_poly, *second_poly;
    first_poly=NULL;
    second_poly=NULL;

    int n1,n2;
    printf("Fisrt polynomial\n");
    printf("Enter the number of non-sparse terms : ");
    scanf("%d",&n1);
    first_poly=create(n1);
    printf("The first polynomial is : ");
    display_poly(first_poly);

    printf("Second polynomial\n");
    printf("Enter the number of non-sparse terms : ");
    scanf("%d",&n2);
    second_poly=create(n2);
    printf("The second polynomial is : ");
    display_poly(second_poly);
    
    printf("Result polynomial after addition is : ");
    add(first_poly,second_poly);
    printf("\n");

    free_list(first_poly);
    free_list(second_poly);

    return 0;
}