#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct sparse_matrix
{
    int row;
    int column;
    int value;
    struct sparse_matrix *next;
};
void print_list(struct sparse_matrix *head)
{
    if(head==NULL)
    {
        printf("No non-zero values in the matrix!\n");
        return;
    }
    struct sparse_matrix *temp;
    temp=head;
    printf("Linked list is : ");
    while(temp!=NULL)
    {
        printf("(%d, %d, %d)-> ",temp->row, temp->column, temp->value);
        temp=temp->next;
    }
    printf("NULL\n"); // Print "NULL" to indicate the end of the list
}
/*void print_matrix(int row, int column, struct sparse_matrix *head)
{
    struct sparse_matrix *temp;
    temp=head;
    int matrix[row][column],i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            matrix[i][j]=0;         //Initialize the matrix to zeros
        }
    }
    while(temp!=NULL)
    {
        matrix[temp->row][temp->column]=temp->value;
        temp=temp->next;
    }
    printf("Sparse Matrix is : \n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}*/
void print_matrix(int row, int column, struct sparse_matrix *head)
{
    struct sparse_matrix *temp;
    temp=head;
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            if(temp!=NULL && temp->row==i && temp->column==j)
            {
                printf("%d\t",temp->value);
                temp=temp->next;
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }            
}
void free_list(struct sparse_matrix *head)
{
    while (head!=NULL)
    {
        struct sparse_matrix *temp;
        temp=head;
        head=head->next;
        free(temp);
    }
}
int main()
{
    int row,column,non_zeros,i;
    printf("Enter the number of rows in the sparse matrix : ");
    scanf("%d",&row);
    printf("Enter the number of columns in the sparse matrix : ");
    scanf("%d",&column);
    printf("Enter the number of non-zero values in the sparse matrix : ");
    scanf("%d",&non_zeros);
    if(non_zeros > row*column)
    {
        printf("Number of non-zero elements exceeds matrix capacity!!\n");
        return 1;   //exit(0);  //Exit with an error code
    }
    struct sparse_matrix *head, *temp, *nz_element;
    head=NULL;
    temp=NULL;
    for(i=0; i<non_zeros; i++)
    {
        nz_element=(struct sparse_matrix *)malloc(sizeof(struct sparse_matrix));
        printf("Enter the row, column and value of the non-zero element %d : \n",i+1);
        scanf("%d %d %d",&nz_element->row, &nz_element->column, &nz_element->value);
        nz_element->next=NULL;
        if(nz_element->row >= 0 && nz_element->row < row && nz_element->column >= 0 && nz_element->column < column)
        {
            nz_element->next=NULL;
            if(head==NULL)
                head=temp=nz_element;
            else
            {
                temp->next=nz_element;
                temp=nz_element;  //temp=temp->next;
            }
        }
        else
        {
            printf("Invalid input!Enter a valid row or column!!\n");
            free(nz_element);
            return 1;   //exit(0);  //Exit with an error code
        }
    }
    print_list(head);
    if (row>0 && column>0)
        print_matrix(row,column,head);
    free_list(head);
    return 0;
}
