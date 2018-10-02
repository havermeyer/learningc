#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define RANK_INDEX 0
#define SUIT_INDEX 1


bool straight, flush, four, three, ace_high;
int pairs;

void read_cards(int[NUM_CARDS][2]);
void analyze_hand(int[NUM_CARDS][2]);
void print_result(void);
bool card_exists(int rank, int suit, int hand[NUM_CARDS][2]);
void sort_hand(int hand[NUM_CARDS][2]);
void print_hand(int hand[NUM_CARDS][2]);

int main(void)
{
    int hand[NUM_CARDS][2];
    for (int i=0;i<NUM_CARDS;i++)
    {
        hand[i][RANK_INDEX] = -1;   
        hand[i][SUIT_INDEX] = -1;
    }

    for (;;) {
        read_cards(hand);
        analyze_hand(hand);
        print_result();
    }
}

void read_cards(int hand[NUM_CARDS][2])
{
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;


    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank = 0; break;
            case '3':           rank = 1; break;
            case '4':           rank = 2; break;            
            case '5':           rank = 3; break;
            case '6':           rank = 4; break;
            case '7':           rank = 5; break;
            case '8':           rank = 6; break;
            case '9':           rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            bad_card = true;
        }

        while ((ch=getchar()) != '\n')
            if (ch != ' ') bad_card = true;
        
        if (bad_card)
            printf("Bad card; ignored.\n");
        else if (card_exists(rank, suit, hand))
            printf("Duplicate card; ignored.\n");
        else {
            hand[cards_read][RANK_INDEX] = rank;
            hand[cards_read][SUIT_INDEX] = suit;
           
            cards_read++;
        }
    }

}

void analyze_hand(int hand[NUM_CARDS][2])
{
    int num_consec = 0;
    int rank, suit;
    ace_high = false;
    straight = true;
    flush = true;
    four = false;
    three = false;
    pairs = 0;

    /* check for flush */
    suit = hand[0][SUIT_INDEX];
    for (int i = 1; i < NUM_CARDS; i++)
        if (hand[i][SUIT_INDEX] != suit)
        {
            flush = false;
            break;
        }

    /* check for straight */
    int min_rank = 100;
    for (int i=0;i<NUM_CARDS;i++)
    {
        if ((hand[i][RANK_INDEX]) < min_rank)
        {
            min_rank = hand[i][RANK_INDEX];
        }
    }

    bool still_good = false;
    for (int j=min_rank;j<min_rank+NUM_CARDS;j++)
    {
        still_good = false;
        for (int i=0;i<NUM_CARDS;i++)
        {
            if (hand[i][RANK_INDEX] == j)
            {
                still_good = true;
                break;
            }    
        }
        if (!still_good)
        {
            straight = false;
            break;
        }
    }
    
    sort_hand(hand);

    if (hand[NUM_CARDS-1][RANK_INDEX]==12)
    {
        ace_high = true;
    }
    //print_hand(hand);

    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    /*
    for (rank = 0; rank < NUM_RANKS; rank++) {
        if (num_in_rank[rank] == 4) four = true;
        if (num_in_rank[rank] == 3) three = true;
        if (num_in_rank[rank] == 2) pairs ++;
    }
    */

    bool get_new = true;
    int same_counter = 0;
    for (int i = 0; i < NUM_CARDS; i++)
    {
        if (same_counter == 0)
        {
            rank = hand[i][RANK_INDEX];
            same_counter = 1;
        }
        else
        {
            if (rank == hand[i][RANK_INDEX])
            {
                same_counter++;
            }
            else 
            {
                if (same_counter == 2)
                    pairs++;
                else if (same_counter == 3)
                    three = true;
                else if (same_counter == 4)
                    four = true;

                same_counter = 1;
                rank = hand[i][RANK_INDEX];
            }
        }
        
    }
    if (same_counter == 2)
        pairs++;
    else if (same_counter == 3)
        three = true;
    else if (same_counter == 4)
        four = true;


}

void print_result(void)
{
    if (ace_high && straight && flush) printf("Royal flush");
    else if (straight && flush)     printf("Straight flush");
    else if (four)                  printf("Four of a kind");
    else if (three &&
            pairs == 1)     printf("Full house");
    else if (flush)         printf("Flush");
    else if (straight)      printf("Straight");
    else if (three)         printf("Three of a kind");
    else if (pairs == 2)    printf("Two Pairs");
    else if (pairs == 1)    printf("Pair");
    else                    printf("High card");
    
    printf("\n\n");
}

void print_hand(int hand[NUM_CARDS][2])
{
    for (int i=0;i<NUM_CARDS;i++)
    {
        printf("%d: %d\n", i, hand[i][RANK_INDEX]);
    }
}

bool card_exists(int rank, int suit, int hand[NUM_CARDS][2]) {

    bool res = false;
    for (int i=0; i < NUM_CARDS; i++)
    {
        if ((hand[i][RANK_INDEX] == rank) && (hand[i][SUIT_INDEX] == suit))
        {
            return true;
        }
        
    }

    return res;
}

void sort_hand(int hand[NUM_CARDS][2])
{
    int temp[2];

    int min_index = 0;
    for (;min_index < NUM_CARDS;min_index++) 
    {
        for (int i=min_index;i<NUM_CARDS;i++)
        {
            if (hand[i][RANK_INDEX] < hand[min_index][RANK_INDEX])
            {
                temp[RANK_INDEX] = hand[min_index][RANK_INDEX];
                temp[SUIT_INDEX] = hand[min_index][SUIT_INDEX];
                hand[min_index][RANK_INDEX] = hand[i][RANK_INDEX];
                hand[min_index][SUIT_INDEX] = hand[i][SUIT_INDEX];
                hand[i][RANK_INDEX] = temp[RANK_INDEX];
                hand[i][SUIT_INDEX] = temp[SUIT_INDEX];
            }
        }
    }

}