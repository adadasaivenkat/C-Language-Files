#include<stdio.h>
int main()
{
    int vertices,edges,v1,v2,i,j;
    printf("Enter the number of vertices : ");
    scanf("%d",&vertices);
    int matrix[vertices][vertices];
    for(i=0; i<vertices; i++)
    {
        for(j=0; j<vertices; j++)
        {
            matrix[i][j]=0;
        }
    }
    printf("Enter the number of edges : ");
    scanf("%d",&edges);
    for(i=0; i<edges; i++)
    {
        printf("Enter edge (vertex 1 and vertex 2) : ");
        scanf("%d %d",&v1,&v2);
        matrix[v1][v2]=1;
        matrix[v2][v1]=1;
    }
    printf("Adjaceny matrix : \n");
    for(i=0; i<vertices; i++)
    {
        for(j=0; j<vertices; j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}