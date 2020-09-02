#include "card.h"

 int main(void) {
    
 	char *hit = "e";
	int playing = 1;
	card *deck;
	card *player;
	card *dealer;
	int psize, dsize;

	printf("testing make_deck() and show()");	
	deck = make_deck();
	show(deck);

	return 0;	
 }

