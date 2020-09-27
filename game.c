#include "card.h"

 int main(void) {
    
 	char *hit = "e";
	int playing = 1;
	card *deck;
	card *player;
	card *dealer;
	int psize, dsize;
	
	deck = shuffle(make_deck());
	player = deal(deck);
	show(player);

	return 0;	
 }

