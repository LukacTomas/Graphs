#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "fileread.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <filename.c>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];

    unsigned int NUM_GRAPH_NODES = get_lastline_number_from_file(filename);

    return EXIT_SUCCESS;
}