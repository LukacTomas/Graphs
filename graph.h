#ifndef GRAPH_H_
#define GRAPH_H_
typedef struct Node
{
    int vertex;
    struct Node *next;
} node;

typedef struct Graph
{
    int numVertices;
    node **adjLists;
    int *visited;
}graph;



graph *createGraph(int vertices);
node *createNode(int vertex);
void addEdge(graph *graph, int src, int dest);
void printGraph(graph *graph);
#endif