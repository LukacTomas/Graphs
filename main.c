#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

unsigned int get_lastline_number_from_file(char *filename)
{
   
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error");
        exit(-1);
    }
    printf("File <%s> was succesfully open for reading\n", filename);
    printf("Getting number from last line\n");

    // MAX_LEN of last line to be read to buffer
    // e.g max two 10-digit int-s with space and \n 
    // (2*10 + 1 + 1) = 22
    static const long MAX_LEN = 22;
    char buffer[MAX_LEN + 1];

    // Read Last Line from File
    int setLastLine = fseek(file, -MAX_LEN, SEEK_END); 
    int readLastLineToBuffer = fread(buffer, MAX_LEN - 1, 1, file);
    int closeFile = fclose(file);
    buffer[MAX_LEN - 1] = 0;
    char *lastLine = strrchr(buffer, '\n') + 1;

    // Get First String (number) From Last Line
    int i = 0;
    while (lastLine[i] != ' ')
    {
        buffer[i - 1] = lastLine[i++];
    }
    buffer[i] = 0;
 
    int number = atoi(buffer);
    printf("Last line number is : %d\n", number);

    return number;
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

    return EXIT_SUCCESS;
}