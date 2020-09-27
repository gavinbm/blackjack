#include "card.h"

void show(card *deck) {
	for(card *tmp = deck; tmp->next != NULL; tmp = tmp->next) {
		printf("%d%c\n", tmp->rank, tmp->suit);
	}
}

int total(card *deck) {
	int add, ret = 0;
	for(card *tmp = deck; tmp->next != NULL; tmp = tmp->next) {
		if(tmp->rank > 10) {add = 10;}
		else {add = tmp->rank;}
		ret = ret + add;
	}
	return ret;
}

card *deal(card *deck) {
	card *ret;

	for(card *tmp = deck; tmp->next != NULL; tmp = tmp->next) {
		if(tmp->next == NULL) {
			ret = tmp;
		}
	}
	return ret;
}

void destroy(card *deck) {
	card *curr = deck;
	card *next = curr;
	while(curr != NULL) {
		next = curr->next;
		free(curr);
		curr = next;
	}
}

card *make_deck() {
	int total = 53, number = 1;
	card *head = NULL;
	card *tmp = NULL;
	card *p = NULL;

	while(number <= total) {
		tmp =(card*)malloc(sizeof(card));
		if(number <= 13) {
			tmp->rank = number;
			tmp->suit = 'C';
		} else if(number > 13 && number <= 26) {
			tmp->rank = number - 13;
			tmp->suit = 'H';
		} else if(number > 26 && number <= 39) {
			tmp->rank = number - 26;
			tmp->suit = 'D';
		} else {
			tmp->rank = number - 39;
			tmp->suit = 'S';
		}

		tmp->next = NULL;

		if(head == NULL) {
			head = tmp;
		} else {
			p = head;
			while(p->next != NULL) {
				p = p->next;
			}
			p->next = tmp;
		}
		number++;
	}
	return head;
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
