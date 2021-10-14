#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

graph *createGraph(int vertices)
{
    graph *graph = malloc(sizeof(struct Graph));
    if (graph == NULL)
    {
        perror("Graph Not Initialized");
        return NULL;
    }

    // Init graph properties
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(node *));
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

node *createNode(int vertex)
{
    node *newNode = malloc(sizeof(node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(graph *graph, int src, int dest)
{
    // Add edge from src to dest
    node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    /*newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;*/
}

void printGraph(graph *graph)
{
    int MAX = 30;
    int maxPrint = graph->numVertices > MAX ? MAX : graph->numVertices;
    for (int i = 0; i <= maxPrint; i++)
    {
        if (graph->adjLists[i] == NULL)
        {
            continue;
        }

        node *pointer = graph->adjLists[i];
        printf("%i: ", i);
        
        while (pointer != NULL)
        {
            if (pointer != NULL)
            {
                printf("%d ", pointer->vertex);
                pointer = pointer->next;
            }

            
        }
        printf("\n");
    }
}