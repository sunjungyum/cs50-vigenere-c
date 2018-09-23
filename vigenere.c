// Sun-Jung Yum
// September 27 2018
// Problem Set 2

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool allAlphabetic(string input);
int convert(char c);
bool handle(char input, int key);
void shiftletter(char input, int key);

int main(int argc, string argv[])
{
    // Checks that there is only 1 command-line argument and that the key is alphabetic
    if (argc != 2 || !allAlphabetic(argv[1]))
    {
        printf("Usage: ./viginere keyword\n");
        return 1;
    }
    else
    {
        // Prompts for plaintext
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        // Declares int variable for the length of the keyword
        int keylength = strlen(argv[1]);
        // Declares int counter variable for the position of the char to be handled
        int textcounter = 0;
        // Declares int counter variable for the chars in the key that were used
        int keycounter = 0;
        // Iterates through each character of the plaintext
        while (textcounter < strlen(plaintext))
        {
            // Declares int variable key after being converted from alphabetical key
            int key = convert(argv[1][keycounter % keylength]);
            // Adds 1 to keycounter if the char being handled was alphabetical
            if (handle(plaintext[textcounter], key))
            {
                keycounter++;
            }
            // Adds 1 to the textcounter after handling the char
            textcounter++;
        }
        printf("\n");
    }
}

// Checks if the command-line argument for the keyword is alphabetic
bool allAlphabetic(string input)
{
    // "Count" keeps track of the number of chars that are not alphabetic
    int count = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isalpha(input[i]) == 0)
        {
            count++;
        }
    }
    // Returns "true" if the number of non-alphabetic chars is 0
    return count == 0;
}

// Converts a char to its positional integer value
int convert(char c)
{
    int base;
    if (isupper(c))
    {
        base = 65;
    }
    else
    {
        base = 97;
    }
    return c - base;
}

// Handles each character in plaintext, directing letters to the "shift" function.
// Returns true if the char was alphabetic, false if not
bool handle(char input, int key)
{
    // Directs letters to the "shift" function
    if (isalpha(input))
    {
        shiftletter(input, key);
        return true;
    }
    // Prints non-letters as is
    else
    {
        printf("%c", (input));
        return false;
    }
}

// Shifts the inputted char by the int value of the appropriate char in key
void shiftletter(char input, int key)
{
    // Converts the char into an int so that A (or a) = 0, etc.
    int convertedplain = convert(input);
    // Shifts the int value of char by the key value, rotating through alphabet
    int convertedcipher = ((convertedplain + key) % 26) + 65;
    // Makes the case correct, based on plaintext case, and prints cipher char
    if (islower(input))
    {
        printf("%c", tolower(convertedcipher));
    }
    else
    {
        printf("%c", toupper(convertedcipher));
    }
}
