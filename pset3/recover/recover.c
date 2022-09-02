#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc !=2)
    {
        fprintf (stderr, "Usage: recover filename.raw\n");
        return 1;
    }

    // remember file name
    char *infile = argv[1];

    // open input file
    FILE *input = fopen(infile, "r");
    if (input == NULL)
    {
        fprintf(stderr, "Could not open %s. \n", infile);
        return 2;
    }
    // creating buffer array
    unsigned char buffer[BLOCK_SIZE];

    // JPEG file count
    int filecounter = 0;

    FILE *jpg;

    // Variable to check if jpg was already found
    int jpg_found = 0; //false

    // reading through cardfile until EOF
    while(fread(buffer, BLOCK_SIZE, 1, input) == 1)
    {
        // Reading first 4 bytes to check if they match jpg header
        if (buffer [0] == 0xff && buffer [1] == 0xd8 &&
            buffer [2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpg_found == 1)
            {
                // Start of new jpg found, old jpg will be closed
                fclose (jpg);
            }
            else
            {
                // first jpg found
                jpg_found = 1;
            }

            // creating new jpg file
            char filename [8];
            sprintf(filename, "%03d.jpg", filecounter);
            jpg = fopen(filename,"a");
            filecounter++;
        }

        if (jpg_found == 1)
        {
            // writing 512 bytes once jpg is found
            fwrite(&buffer, BLOCK_SIZE, 1, jpg);
        }

    }

    // close files
    fclose(input);
    fclose(jpg);

    return 0;
}
