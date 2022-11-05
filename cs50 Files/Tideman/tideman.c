#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Evaluate if the name voted for is valid by looping through all candidate names
    // if valid, ???
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    //For each voter we start with the first candidate they ranked and ++ for each other candidate, and then move to the next until all ranks are considered
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 1 + i; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    //if preferences[i][j] > 0, i is winner and j is loser
    //if preferences[i][j] == 0, then no entry, no other possibilities
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // using bubble sort to put the higher strength value to the left if left < right value and comparing down the line
    pair sorter;
    for (int i = 0; i < pair_count; i++)
    {
        int k = 0;
        for (int j = 0; j < pair_count - 1; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] < preferences[pairs[j + 1].winner][pairs[j + 1].loser])
            {
                sorter = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = sorter;
                k++;
            }
        }
        if (k == 0)
        {
            break;
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // loop through each pair and evaluate the winner to decide if it can be locked or not
    for (int i = 0; i < pair_count; i++)
    {
        int e = pairs[i].winner; // set test variable to current pair's winner
        for (int j = 0; j < candidate_count; j++) // loop through all candidates
        {
            if (locked[j][e] == false) // validate if winner was ever a loser in a locked pair
            {
                if (j == candidate_count - 1)
                {
                    locked[pairs[i].winner][pairs[i].loser] = true; // if never a loser, lock the pair
                    break;
                }
            }
            if (locked[j][e] == true) // if current winner is a loser, validate if that winner is the loser of current pair
            {
                if (j == pairs[i].loser) // if at any point the winner we evaluate lost to the current pair's loser, that will be a cycle and edge should be skipped
                {
                    break;
                }
                else // if the current validation's winner did not lose to current pair's loser, evalute the next winner
                {
                    e = j;
                    j = 0;
                }
            }
        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    // TODO - in locked[i][j] == true, which i was never a j?
    for (int i = 0; i < candidate_count; i++) // loop for each winner spot in locked
    {
        for (int j = 0; j < candidate_count; j++) // loop for each loser spot in locked
        {
            if (locked[i][j] == true) // looking for locked pairs to evaluate for winners
            {
                int test_winner = i; // identify the first winner and test to see if overall winner
                int w = 0;
                for (int k = 0; k < candidate_count; k++) // loop through each winner spot in locked again
                {
                    for (int l = 0; l < candidate_count; l++) // loop through each loser spot in locked again
                    {
                        if (locked[k][l] == true) // identify a locked pair to validate first winner for overall winner
                        {
                            if (test_winner == l) // if test_winner is a loser, then increase validation variable
                            {
                                w++; //
                            }
                        }
                    }
                }
                if (w == 0) // if validation variable is 0, then winner was never a loser and is overall winner
                {
                    printf("%s\n", candidates[test_winner]);
                    break;
                }
            }
        }
    }
    return;
}