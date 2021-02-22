#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
// float Variables declarations
float l = 0;
float s = 0;
float w = 1;
int main()
{
    string text = get_string("Text: ");
    int n = strlen(text); // calculate the length of string by strlen() function
    for (int i = 0; i < n; i++) // count of letters in text
    {
        if (isalpha(text[i])) // if index is alphabet the add 1 to l
        {
            l += 1;
        }
    }
    // count of sentences in text
    for (int i = 0; i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            s += 1;
        }
    }
    // count of words in text
    for (int i = 0; i < n; i++)
    {
        if (text[i] == ' ')
        {
            w += 1;
        }
    }
    
    float avgL = l * 100 / w; // calcul average of letters per 100 words
    float avgS = s * 100 / w; // calcul average of sentences per 100 words
    // calcul grade level by The Coleman-Liau index
    float index = 0.0588 * avgL - 0.296 * avgS - 15.8;
    // use round( ) function to returns the nearest integer value of the float
    int grade = round(index);
    // print Grade level of text inserted by user 
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", grade);
    } 
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
    
}
    
