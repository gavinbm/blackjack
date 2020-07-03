#include "card.h"

void remove_element(card *deck, int index, int size)
{
   int i;
   for(i = index; i < size - 1; i++) deck[i] = deck[i + 1];
}

void show(card *deck) {
    int size = count_deck(deck);
    for(int i = 0; i < size; i++) {
        printf("%d%c ", deck[i].rank,deck[i].suit);
    }
}

int total(card *card) {
    int add, ret = 0;
    int size = count_deck(card);
    for(int i = 0; i < size; i++) {
        if(card[i].rank > 10) {add = 10;}
        else {add = card[i].rank;}
        ret += add;
    }
    return ret;
}

card *deal(card *deck) {
    int size = count_deck(deck);
    card ncard = deck[size];
    printf("%d%c ", ncard.rank, ncard.suit);
    remove_element(deck, size, size);
    card *p2c = &ncard;
    return p2c;
}

void destroy_deck(card *deck) {
    free(deck);
}

card *make_deck(void) {
    card *deck = malloc(sizeof(card));
    for(int i = 0; i < 52; i++) {
    	deck[i].next = malloc(sizeof(card));
	for(int j = 1; j <= 13; j++) {
	    deck[i].rank = j;
	    if(j >= 13) {j = 1;}
	}
	for(int k = 1; k <= 5; k++) {
	    switch(k) {
	    	case 1 :
		    deck[i].suit = 'C';
		    break;
		case 2 :
		    deck[i].suit = 'D';
		    break;
		case 3 :
		    deck[i].suit = 'H';
		    break;
		case 4 :
		    deck[i].suit = 'S';
		    break;
		default :
		    k = 1;
	    }
	}
    }
    return deck;
}

/* counts the number of cards in the list headed by "deck" */
int count_deck(card *deck) {
    int count=0;
    /* No initialization required. When "deck" is NULL (zero), it's at the end. Otherwise, move to the
    next card and increment the count. No body of the for loop! */
    for(;deck;deck=deck->next,count++);
    return count;
}

/* Emulates a "riffle shuffle" of "deck". */
card *shuffle(card *deck) {
    int size = count_deck(deck);
    card *cut=deck;
    for(int i=0; i<size/2; i++){
        cut=cut->next;
    }
    /* cut is now the card 1/2 way through the deck */
    card *riffle=cut->next;
    cut->next = 0; /* deck and riffle now head separate lists */
    /* Shuffle the deck by randomly pulling a card from the head of "deck" or "riffle"
       and make it the new head of "retdeck" */
    card *retdeck=0;
    for(;deck || riffle;) { /* just like a while loop */
        card *temp;
        if(deck && (!riffle || drand48()<0.5)) {
            /* next card comes from the top of 'deck' */
            temp=deck;
            deck=deck->next;
        } else if(riffle) {
            /* next card comes from the top of 'riffle' */
            temp=riffle;
            riffle=riffle->next;
        }
        /* put the card at the top of the "retdeck" */
        temp->next=retdeck;
        retdeck=temp;
    }
    return retdeck;
}
