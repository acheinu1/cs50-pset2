#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool check_valid_key(string s);

int main(int argc, string argv[])
{
    if (argc != 2 || !check_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    int key = atoi(argv[1]);  //===to make sure the key is always a number

    string plaintext = get_string("plaintext: ");  // take input text from the user

    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)    // iterating through the input text alphabet by alphabet using for loop
    {
        char textcase = plaintext[i];   // store the plaintext in a variable called textcase
        if (isalpha(textcase))     // checking if textcase is upper or lower case using if else statement
        {
            char m = 'A';
            if (islower(textcase))

                m = 'a';

            printf("%c", (textcase - m + key) % 26 + m);  // use  modulo 26 to

        }
        else

            printf("%c", textcase);

    }
    printf("\n");
}

bool check_valid_key(string s)
{
    for(int i = 0, len = strlen(s); i < len; i++)
        if(!isdigit(s[i]))
            return false;
    return true;
}