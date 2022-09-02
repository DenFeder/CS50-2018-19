#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//for crypt:
#include <crypt.h>
int main(int argc, char *argv[])
{
    //only one command line argument ist allowed
    if(argc != 2)
    {
        printf("Usage: ./crack hashed_password\n");
        return 1;
    }

    //hashed_pw
    char* hashed_pw = argv[1];

    //put the salt together
    char salt[2];
    sprintf(salt, "%c%c", hashed_pw[0], hashed_pw[1]);

    //optional characters to test
    string cs = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        //cs="\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";


    //length of opt chars -> 26x2 + null character
    int len = 52; //53
        //printf("cs: %s", cs);
    
    string pw_try = malloc(6);
        // string pw_try = NULL;
    
    sprintf(pw_try, "%c%c%c%c%c%c", cs[29], cs[27], cs[0], cs[0], cs[0],cs[0]);
    printf("pwtry: %s\n", pw_try);
    
    string hsh_try = crypt(pw_try, salt);
    printf("hsh_try: %s\n", hsh_try);
    
    int compare = strcmp(hashed_pw, hsh_try);
    printf("Compare: %i\n", compare);
    
    //string hsh_try = crypt(&c[i], salt);
    
    if(strcmp(hashed_pw, hsh_try) == 0) // argv -> hased_pw
    {
        printf("Stimmt überein\n");
        return 0;
    }
    /**
    //first loop beginning with 1 to skip the null character - password cannot be empty
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            for (int k = 0; k < len; k++)
            {
                for (int l = 0; l < len; l++)
                {
                    for (int m = 1; m < len; m++)
                    {
                        string pw_try=NULL;
                        sprintf(pw_try, "%c%c%c%c%c", cs[m], cs[l], cs[k], cs[j], cs[i]);
                        string hsh_try = crypt(pw_try, salt);
                        //string hsh_try = crypt(&c[i], salt);
                        printf("%i", i);
                        //argv anstelle von hashed_pw weil es damit nicht geklappt hat
                        if(strcmp(argv[1], hsh_try)==0)
                        {
                            printf("Stimmt überein\n");
                            return 0;
                        }
                    }
                }
            }
        }
    }
    **/
}
/**
        string hsh_try = crypt(&opt_chars[i], salt);
        printf("%i", i);
        //printf("This is a string: %s\n", hsh_try);
        //argv anstelle von hashed_pw weil es damit nicht geklappt hat
        if(strcmp(argv[1], hsh_try)==0)
        {
            printf("Stimmt überein\n");
            return 0;
        }
**/