#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int grade_level(string text);
int count_sentences(string text);
int count_words(string text);
int count_letters(string text);


int main(void)
{
    // Prompt the user for the text
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Get the grade level of the text using the Coleman-Liau formula
    float calculation = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;
    int index = round(calculation);

    //Print the reading level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (1 < index && index < 16)
    {
        printf("Grade %i\n", index);
    }
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
}

// Count the number of letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // Got this function from Youtube (https://www.youtube.com/watch?v=zundkuh-CiI)
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// Count the number of words
int count_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

// Count the number of sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.')
        {
            sentences++;
        }
        if (text[i] == '!')
        {
            sentences++;
        }
        if (text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
