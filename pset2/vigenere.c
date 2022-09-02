// Enciphering User input using Vigenere. First prompting keyword then plaintext returning ciphertext

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shift(char c);
string get_plaintext(string prompt);

bool letters = true;

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //Iterating trough key checking if exclusively letters are contained
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (argv[1][i] < 65 || (argv[1][i] < 97 && argv[1][i] > 90) || argv[1][i] > 122)
            {
                letters = false;
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
        if (letters == true)
        {
            string keyword = argv[1]; // Saving keyword input in variable for visibility
            int keyCounter = 0 ; // Used to move trough keyword
            int key ;
            string plaintext = get_plaintext("plaintext : "); //Prompting plaintext from user
            int safetyInt; //Later used to prvent end of ASCII values

            for (int j = 0, n1 = strlen(plaintext); j < n1; j++) //Iterating trough plaintext
            {
                if (keyCounter >= strlen(keyword)) // Going back to first letter if end of keyword is reached
                {
                    keyCounter = 0;
                }

                key = shift(argv[1][keyCounter]);
                // Variable used the distinguish lowercase ASCII from uppercase after key was added
                bool uppercase = false;
                // ASCII value converted to int in case ASCII would exceed 127
                safetyInt = (int) plaintext[j];

                //Adding key onto plaintext if char is a letter
                if ((plaintext[j] > 64 && plaintext[j] < 91) ||
                    (plaintext[j] > 96 && plaintext[j] < 123))
                {
                    // Used in case uppercase letters would reach lowercase ASCII range
                    if (plaintext[j] > 64 && plaintext[j] < 91)
                    {
                        uppercase = true;
                    }
                    // Cheking if converted int would exceed 127,to ASCII errors
                    if (safetyInt + key > 127)
                    {
                        // New ASCII value claculated with int, afterwards casted as char
                        safetyInt = safetyInt + key - 26;
                        plaintext[j] = (char) safetyInt;
                        keyCounter++ ;
                    }
                    else
                    {
                        plaintext[j] = plaintext[j] + key;
                        keyCounter++;
                    }
                }
                //Matching ASCII back to letter ranges if letters would exceed "Z" or "z"
                if ((plaintext[j] > 122) ||
                    (plaintext[j] > 90 && uppercase == true))
                {
                    plaintext[j] = plaintext[j] - 26;
                }
            }
            printf("ciphertext: %s\n", plaintext);
            return 0;
        }
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}

int shift(char c) // Matching letters to their respective nr. e.g. A/a = 0, B/b = 1 etc.
{
    int key;

    if (c > 64 && c < 91) // Checking for uppercase letters
    {
        key = ((int) c) - 65; // Matching to respective position in alphabet
        return key;
    }
    else
    {
        if (c > 96 && c < 123) // Checking for lowercase letters
        {
            key = ((int)c) - 97; // Matching to respective position in alphabet
            return key; // Returns prompted key´s respective value as ant
        }
        return 1;
    }
}

string get_plaintext(string prompt) // Prompting a string from user until input is not void
{
    string plaintext;
    string leer = "";
    do
    {
        plaintext = get_string("%s", prompt);
    }
    while (plaintext == leer);
    return plaintext;
}
