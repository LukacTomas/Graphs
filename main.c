#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned int get_lastline_number_from_file(char *filename)
{
    printf("Getting number from last line\n");
    FILE *file = fopen(filename, "r");
    int number;
    static const long MAX_LEN = 20;
    char buff[MAX_LEN + 1];
    fseek(file, -MAX_LEN, SEEK_END); // set pointer to the end of file minus the length you need. Presumably there can be more than one new line caracter
    fread(buff, MAX_LEN - 1, 1, file);
    buff[MAX_LEN - 1] = '\0';                 // close the string
    char *last_newline = strrchr(buff, '\n'); // find last occurrence of newlinw
    char *last_line = last_newline + 1;
    int i;
    int len = strlen(last_line);
    for (i = 0; i < len; ++i)
    {
        if (last_line[i] == ' ')
        {
            break;
        }
        buff[i] = last_line[i];
    }
    buff[i + 1] = '\0';
    number = atoi(buff);
    fclose(file);
    printf("Last line number is : %f\n", number);

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