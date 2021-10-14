#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "fileread.h"
#include "graph.h"

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

    printGraph(graph);
    return EXIT_SUCCESS;
}