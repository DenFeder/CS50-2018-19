#include <stdio.h>
#include <stdlib.h>
//for crypt:
#include <crypt.h>
int main(void)
{
    char *c = "Hallo";
    char *salt = malloc(3);

    for (int i = 0; i < 2; i++)
    {
        salt[i] =   c[i];
    }   
    //char *salz = salt;
    
    printf("%s\n", salt);
    free(salt);
}
