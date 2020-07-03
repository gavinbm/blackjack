#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int rank;
	char suit;
} card;

card *make_deck(void);
card *shuffle(card *deck);
card deal(card *deck);
int count(card *deck);
int total(card *deck);
void destroy(card *deck);
void show(card *deck);

int main() {
	char *hit;
	int playing = 1;
	int psize, dsize;
	card *deck;
	card *player;
	card *dealer;

	while(playing) {
		deck = make_deck();
		player = malloc(10 * sizeof(card));
		dealer = malloc(10 * sizeof(card));
		player[0] = deal(deck);
		dealer[0] = deal(deck);
		psize = count(player);
		dsize = count(dealer);

		printf("Welcome to Reno!");
		if(total(dealer) < 16) {
			while(total(dealer) < 16) {
				dealer[dsize + 1] = deal(deck);
				dsize = count(dealer);
			}
		}

		show(player);
		printf("(h)it or (s)tand?\n");
		scanf("%s", hit);

		if(hit == "h") {
			while(hit == "h") {
				player[psize + 1] = deal(deck);
				psize = count(player);
				printf("(h)it again?\n");
				scanf("%s", hit);
			}
		}

		if(hit == "s") {
			int pscore = total(player);
			int dscore = total(dealer);
			show(player);
			show(dealer);

			if(dscore > pscore || dscore == pscore) {printf("dealer wins");}
			else {printf("player wins");}
			destroy(deck);
			destroy(player);
			destroy(dealer);
			playing = 0;
		}
	}
	return 0;
}


card *make_deck() {
	card *deck = malloc(52 * sizeof(card));

	for(int i = 0; i < 52; i++) {
		card *ncard = malloc(sizeof(card));

		for(int j = 0; j < 13; j++) {
			ncard->rank = j + 1;
		}

		for(int k = 0; k < 4; k++) {
			if(k == 0) {ncard->suit = 'C';}
			else if(k == 1) {ncard->suit = 'H';}
			else if(k == 2) {ncard->suit = 'D';}
			else if(k == 3) {ncard->suit = 'S';k = 0;}
		}

		deck[i] = *ncard;
	}
	return deck;
}

card *shuffle(card *deck) {
	card tmp;
	int j;
	for(int i = 0; i < 52; i++) {
		j = rand() % 52;
		tmp = deck[i];
		deck[i] = deck[j];
		deck[j] = tmp;
	}
	return deck;
}

card deal(card *deck) {
	card *ret = malloc(sizeof(card));
	int size = count(deck);
	ret[0] = deck[size - 1];
	return *ret;
}

int count(card *deck) {
	return sizeof(deck) / sizeof(card);
}

int total(card *deck) {
	int add, ret = 0, size = count(deck);
	for(int i = 0; i < size; i++) {
		if(deck[i].rank > 10) {add = 10;}
		else {add = deck[i].rank;}
		ret = ret + add;
	}
	return ret;
}

void show(card *deck) {
	int size = count(deck);
	for(int i = 0; i < size; i++) {
		printf("%d%c", deck[i].rank, deck[i].suit);
	}
}

void destroy(card *deck) {
	free(deck);
}
