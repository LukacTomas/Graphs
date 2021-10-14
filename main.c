#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "fileread.h"
#include "graph.h"
#include "queue.h"

void bfs(graph *graph, int startVertex)
{
    queue *q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q))
    {
        //printQueue(q);
        int currentVertex = dequeue(q);
        //printf("Visited %d\n", currentVertex);

        node *temp = graph->adjLists[currentVertex];

        while (temp)
        {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <filename.c>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];

    unsigned int NUM_GRAPH_NODES = get_lastline_number_from_file(filename);

    graph *graph = createGraph(NUM_GRAPH_NODES);

    unsigned int from, to;
    FILE *file = fopen(filename, "r");
    while (fscanf(file, "%d %d", &from, &to) != EOF)
    {
        addEdge(graph, from, to);
    }
    fclose(file);
    printf("Done reading File\n");
    printGraph(graph);
    printf("Starting BFS\n\n");
    
    return EXIT_SUCCESS;
}