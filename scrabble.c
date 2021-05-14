#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    
    //compare scores to see which player wins print the player that won
    if (score1 > score2)
    {
        printf("Player 1 Wins!");
    }
    else if (score1 < score2)
    {
        printf("player 2 Wins!");
    }
    else
    {
        printf("Tie");
    }
    
}

//This is a function that gives you the amount of scrable points each word is worth
int compute_score(string word)
{
   
    //set the return variable
    int total = 0;
    //iterarte through the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        //convert to uppercase
        int character = toupper(word[i]);
        
        if (character >= 'A' && character <= 'Z')
        {
            //add one to index till you hit the character we are curently looking at
            int index = 0;
            for (int j = 65; j < character; j++)
            {
                index++;
            }
         
            //add points 
            total += POINTS[index]; 
        }
        else 
        {
            total += 0;
        }

        
    }
    
    return total;
}