#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct graph
{
    int vertices;
    int **adj_matrix;
};
struct graph *create_graph(int vertices)
{
    struct graph *temp;
    temp=(struct graph *)malloc(sizeof(struct graph));
    temp->vertices=vertices;
    temp->adj_matrix=(int **)malloc(vertices*sizeof(int *));
    int i,j;
    for(i=0; i<vertices; i++)
    {
        temp->adj_matrix[i]=(int *)malloc(vertices*sizeof(int));
    }
    for(i=0; i<vertices; i++)
    {
        for(j=0; j<vertices; j++)
        {
            temp->adj_matrix[i][j]=0;
        }
    }
    return temp;
}
void add_edge(struct graph *temp, int v1, int v2)
{
    temp->adj_matrix[v1][v2]=1;
    temp->adj_matrix[v2][v1]=1;  //For undirected graph (remove this line for directed graph)
}
int main()
{
    int vertices,edges,v1,v2,i,j;
    printf("Enter the number of vertices : ");
    scanf("%d",&vertices);
    struct graph *temp;
    temp=create_graph(vertices);
    printf("Enter the number of edges : ");
    scanf("%d",&edges);
    for(i=0; i<edges; i++)
    {
        printf("Enter edge (vertex 1 and vertex 2) : ");
        scanf("%d %d",&v1,&v2);
        add_edge(temp,v1,v2);
    }
    printf("Adjaceny matrix : \n");
    for(i=0; i<temp->vertices; i++)
    {
        for(j=0; j<temp->vertices; j++)
        {
            printf("%d\t",temp->adj_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}