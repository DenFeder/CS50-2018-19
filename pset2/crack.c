#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

// Cracked passwords:
//
// anushree:50xcIMJ0y.RXo => YES
// brian:50mjprEcqC/ts => CA
// bjbrown:50GApilQSG3E2 => UPenn
// lloyd:50n0AAUD.pL8g => lloyd
// malan:50CcfIk1QrPr6 => maybe
// maria:509nVI8B9VfuA => TF
// natmelo:50JIIyhDORqMU => nope
// rob:50JGnXUgaafgc => ROFL
// stelios:51u8F0dkeDSbY => NO
// zamyla:50cI2vYkF0YU2 => LOL

bool ishash (char *prompt);
char *getsalt(char *prompt);
char *gsalt;

int main(int argc, char *argv[])
{
    char *key = malloc(6);
    char *salt = getsalt(argv[1]);
    if (argc == 2 && ishash(argv[1]) == true)
    {
        char *hash = argv[1];
        char *letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const int letters_count = 52;

        for (int key5 = 0; key5 < letters_count; key5++)
        {
            for (int key4 = 0; key4 < letters_count; key4++)
            {
                for (int key3 = 0; key3 < letters_count; key3++)
                {
                    for (int key2 = 0; key2 < letters_count; key2++)
                    {
                        for (int key1 = 0; key1 < letters_count; key1++)
                        {
                            key[0] = letters[key1];
                            key[1] = letters[key2];
                            key[2] = letters[key3];
                            key[3] = letters[key4];
                            key[4] = letters[key5];

                            //printf("%s\n", key);


                            if (strcmp (crypt(key,salt), hash) == 0)
                            {
                                printf("%s\n", key);
                                free(gsalt);
                                free(key);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        printf("Usage: ./crack hash\n");
        free(gsalt);
        free (key);
        return 1;
    }
}

bool ishash(char * prompt)
{
    char *c = prompt;
    bool issalt = false;

    for (int i = 0 ; i < 2; i++)
    {
        if((c[i] > 45 && c[i] < 58) ||
           (c[i] > 64 && c[i] < 91) ||
           (c[i] > 96 && c[i] < 123) )
        {

            issalt = true ;
        }
        else
        {
           return false;
        }
    }
    if (issalt == true && strlen(c) == 13)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char *getsalt(char *prompt)
{
    char *c = prompt;
    gsalt = malloc(3);

    for (int i = 0; i<2; i++)
    {
        gsalt[i] = c[i];
    }
    //char *salz = salt;
    //free(salt);
    return gsalt;
}

