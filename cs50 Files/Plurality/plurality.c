#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // I'm creating a new array using the candidate struct created globablly to store the sorted list of results into as they are evaluated
    candidate results[candidate_count];

    // I am evaluating all possible number of votes (starting at 0) against the vote totals of each candidate
    // if they are equal, that candidate is assigned the next spot in the results array until the array is full
    for (int i = 0, k = 0; k < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[j].votes == i)
            {
                results[k] = candidates[j];
                k++;
            }
        }
    }

    // this prints the name of the candidate in the highest array of results
    printf("%s\n", results[candidate_count - 1].name);

    // This checks for a tie with the inner by comparing the votes total from the winner with each other candidate descending and prints their name if the votes are equal
    for (int i = 2, j = 0; j < candidate_count - 1; i++, j++)
    {
        if (results[candidate_count - 1].votes == results[candidate_count - i].votes)
        {
            printf("%s\n", results[candidate_count - i].name);
        }
    }
}

//what do I know? # of votes (candidates[i].votes can be 0-5)
// evaluate each c[i].votes against each possible vote count from 0-5
// if [0] == 0, else if [1] == 0, etc.
// if one is 0, then it becomes [0]