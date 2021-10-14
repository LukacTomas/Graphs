#ifndef GRAPH_H_
#define GRAPH_H_
typedef struct Graph graph;
typedef struct Node node;

graph *createGraph(int vertices);
node *createNode(int vertex);
void addEdge(graph *graph, int src, int dest);
void printGraph(graph *graph);
#endif