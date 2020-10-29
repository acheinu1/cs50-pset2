#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string s = get_string("Text:");
    int words, sentences, letters;
    words = sentences = letters = 0;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
          letters++;
        if((i == 0 && s[i] != ' ') || (i != len - 1 && s[i] == ' ' && s[i + 1] != ' '))
          words++;
        if(s[i] == '.' || s[i] == '?' || s[i] == '!')
          sentences++;
    }
    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if(index < 1)
        printf("Before Grade 1\n");

    else if(index >= 16)
        printf("Grade 16+\n");

    else
        printf("Grade %i\n", index);
}