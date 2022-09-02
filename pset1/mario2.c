#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);

int main(void)
{
    int i, j, height, space ;
    height = get_height("Enter height (Number between 1 & 8):\n");

    if(height>=1 && height<=8)
    {
        for (i=1; i<=height; i++)
        {
            //spaces before first # in row
            for (space = height-i; space>=0; space--)
            {
                printf(" ") ;
            }
            //first # batch
            for (j=1; j<=i; j++)
            {
                printf("#");
            }

            //Seperating space
            printf ("  ");

            //second # batch
            for (j=1; j<=i; j++)
            {
                printf("#");
            }
            printf("  \n") ;
        }
    }
}

int get_height(string prompt)
{
    int height;
    do
    {
        height = get_int("%s",prompt);
    }
    while (height<1 || height>8);
    return height;
}