#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main (int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf (stderr, "Usage: resize n infile outfile\n");
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 1 || n > 100)
    {
        printf ("Usage: resize n infile outfile\nn must be a from 1 to 100\n");
        return 2;
    }
    // remember filenames & n
    char *infile = argv[2];
    char *outfile = argv[3];

    //success
    printf ("Success\n");
    return 0;
}
