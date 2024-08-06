#include <stdio.h>
#include <string.h>
#include <math.h> 

int main(int argc, char* argv[])
{
    char words[1000000];
    int sentenceCounter = 0;
    int letterCounter = 0; 
    int wordCounter = 1;
    printf("Enter text here: ");
    fgets(words, sizeof(words), stdin); 
    int len = strlen(words);
    int i = 0;
    while (i < len)
    {
        if (words[i] == '.' || words[i] == '!' || words[i] == '?')
        {
            sentenceCounter++;
        }
        else if ((words[i] >= 'a' && words[i] <= 'z') || (words[i] >= 'A' && words[i] <= 'Z'))
        {
            letterCounter++;
        }
        else if (words[i] == ' ')
        {
            wordCounter++;
        }
        i++;
    }
    float l = (float) letterCounter / wordCounter * 100;
    float s = (float) sentenceCounter / wordCounter * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int roundedIndex = round(index);
    if (roundedIndex >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (roundedIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        printf("Grade %i\n", roundedIndex); 
    }
} 