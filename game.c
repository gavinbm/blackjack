#include "card.h"

 int main(void) {
    /* Your code goes here */
    char *hit;
    int playing = 1;
    card *deck = shuffle(make_deck());
    card *pDeck = deal(deck);
    card *dDeck = deal(deck);
    int pSize = count_deck(pDeck), dSize;

    printf("Welcome to Reno!");
    while(playing == 1) {
        if(total(dDeck) < 17) {
            while(total(dDeck) < 16) {
                dSize = count_deck(dDeck);
                dDeck[dSize + 1] = *deal(deck);
            }
        }

        show(pDeck);

        printf("\nhit or stand?\n");
        scanf("%s",hit);

        if(hit == "h" || hit == "H" || hit == "hit" || hit == "Hit") {
            while(hit == "h" || hit == "H" || hit == "hit" || hit == "Hit") {
                pSize = count_deck(pDeck);
                pDeck[pSize + 1] = *deal(deck);
                show(pDeck);
                printf("hit again?\n");
                scanf("%s",hit);
            }
        }

        else if(hit == "s" || hit == "S" || hit == "stand" || hit == "Stand") {
            printf("Players Cards: ");
            show(pDeck);
            printf("Dealers Cards: ");
            show(dDeck);

            if(total(dDeck) > 21) {printf("Dealer Bust!, Player Wins!");}
            if(total(pDeck) > 21) {printf("Player Bust!, Dealer Wins!");}
            if(total(pDeck) > 21 && total(dDeck) > 21) {printf("Both bust! No winner!");}

            if(total(pDeck) > total(dDeck)) {printf("Player Wins!");}
            if(total(dDeck) >= total(pDeck)) {printf("Dealer Wins!");}

            printf("Do you wanna play again? (1 for yes, 0 for no) ");
            scanf("%d", &playing);
        }
    }

    return 0;
 }
