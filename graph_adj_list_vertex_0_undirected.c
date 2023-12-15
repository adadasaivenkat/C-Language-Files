#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct node
{
    int data;
    struct node *next;
};
struct graph
{
    int vertices;
    struct node **adj_list;
};
struct node *create(int data)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}
struct graph *create_graph(int vertices)
{
    struct graph *temp;
    temp=(struct graph*)malloc(sizeof(struct graph));
    temp->vertices=vertices;
    temp->adj_list=(struct node **)malloc(vertices*sizeof(struct node *));
    int i;
    for(i=0; i<vertices; i++)
    {
        temp->adj_list[i]=NULL;
    }
    return temp;
}
void add_edge(struct graph *temp,int source, int destination)
{
    struct node *new_node;
    //Add edge from source to destination
    new_node=create(destination);
    new_node->next=temp->adj_list[source];
    temp->adj_list[source]=new_node;
    
    //Add edge from destination to source
    //For undirected graph (remove this for directed graph)
    new_node=create(source);
    new_node->next=temp->adj_list[destination];
    temp->adj_list[destination]=new_node;
}
int main()
{
    int vertices,edges,source,destination,i;
    printf("Enter the number of vertices : ");
    scanf("%d",&vertices);
    struct graph *temp;
    temp=create_graph(vertices);
    printf("Enter the number of edges : ");
    scanf("%d",&edges);
    for(i=0; i<edges; i++)
    {
        printf("Enter source : ");
        scanf("%d",&source);
        printf("Enter destination : ");
        scanf("%d",&destination);
        add_edge(temp,source,destination);
    }
    for(i=0; i<temp->vertices; i++)
    {
        printf("Adjaceny list for vertex %d : ",i);
        struct node *current;
        current=temp->adj_list[i];
        while(current!=NULL)
        {
            printf("%d -> ",current->data);
            current=current->next;
        }
        printf("NULL\n");
    }
    return 0;
}