#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string get_plaintext(string prompt);

int main(int argc, string argv[])
{

    if (argc == 2)
    {
        //iterates trough key & checks if key only contains digits
        bool digit = false;
        for (int i = 0, n = strlen(argv[1]); i<n; i++)
        {
            if (argv[1][i]>47 && argv[1][i]<58)
            {
                digit = true;
            }
        }
        //Converting key to int and matchin it to 26 scale
        int key = atoi(argv[1]);
        if (key > 26)
        {
            key = key % 26;
        }
        //Getting plaintext and shifting characters
        string plaintext = get_plaintext("plaintext : ");
        int safetyInt;

        for (int i = 0, n = strlen(plaintext); i<n; i++)
        {
            bool uppercase = false;
            safetyInt = (int) plaintext[i]; // Integer used incase ASCII would exceed 127
            //Adding key onto plaintext if char is a letter
            if ((plaintext[i]>64 && plaintext[i]<91) ||
                (plaintext[i]>96 && plaintext[i]<123))
            {
                if (plaintext[i]>64 && plaintext[i]<91)
                {
                    uppercase = true;
                }
                //Cheking if ASCII would exceed 127, working around with integer
                if(safetyInt + key > 127)
                {
                    safetyInt = safetyInt + key - 26;
                    plaintext[i] = (char) safetyInt;
                }
                else
                {
                    plaintext[i] = plaintext[i] + key;
                }
            }
            //Matching ascii back to letter ranges if letters would exceed "Z" or "z"
            if ((plaintext[i] > 122) ||
                (plaintext[i] > 90 && uppercase == true))
            {
                plaintext[i] = plaintext[i] - 26;
            }
        }
        printf("ciphertext: %s\n", plaintext);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

string get_plaintext(string prompt)
{
    string plaintext;
    string leer = "";
    do
    {
        plaintext = get_string("%s",prompt);
    }
    while(plaintext == leer);
    return plaintext;
}
