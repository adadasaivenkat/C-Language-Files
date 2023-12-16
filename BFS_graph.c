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
void bfs(struct graph *temp,int start_vertex)
{
    int *queue, *visited;
    queue=(int *)malloc(temp->vertices*sizeof(int));
    visited=(int *)malloc(temp->vertices*sizeof(int));
    int front=-1, rear=-1;
    int i,current;
    for(i=0; i<temp->vertices; i++)
    {
        visited[i]=0;
    }
    //Enqueue the starting vertex
    queue[++rear]=start_vertex;
    visited[start_vertex]=1;
    printf("BFS visited vertices are : ");
    while(front!=rear)
    {
        //Dequeue the vertex
        current=queue[++front];
        printf("%d ",current); 
        for(i=0; i<temp->vertices; i++)
        {
            if(temp->adj_matrix[current][i]==1)
            {
                if(visited[i]==0)
                {
                    queue[++rear]=i;
                    visited[i]=1;
                }
            }
        }
    }
}
int main()
{
    int vertices,edges,v1,v2,i,j,start_vertex;
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
    printf("Enter the starting vertex of the bfs : ");
    scanf("%d",&start_vertex);  
    bfs(temp,start_vertex);  
    return 0;
}