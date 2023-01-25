#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string text = get_string("Text: ");
    double letlen = count_letters(text);
    double worlen = count_words(text);
    double senlen = count_sentences(text);
    double L = letlen / worlen * 100.0;
    double S = senlen / worlen * 100.0;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // printf("%s\n", text); // -------------------------------------- for debug
    // printf("%f letters\n", letlen);
    // printf("%f words\n", worlen);
    // printf("%f sentences\n", senlen);
    // printf("%f index\n", index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string s)
{
    int letters = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        s[i] = toupper(s[i]);
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string s)
{
    int words = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            words++;
        }
    }
    return words + 1;
}

int count_sentences(string s)
{
    int sentences = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}