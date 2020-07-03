#include "card.h"

 int main(void) {
    
 	char *hit = "e";
	int playing = 1;
	card *deck;
	card *player;
	card *dealer;
	int psize, dsize;
	
	do { 	
		/* Introduction */
		printf("Welcome to Reno!");	

		/* initializing variables at game start */
		deck = shuffle(make_deck());
		player = deal(deck);
		dealer = deal(deck);
		psize = count_deck(player);
		dsize = count_deck(dealer);
		
		/* handling dealer deck */
		if(total(dealer) < 17) {
			dealer[dsize].next = deal(deck);
		}

		/* handling player deck */
		show(player);
		printf("Now that the dealer has their cards, (h)it or (s)tand?\n");
		scanf("%s", hit);

		if(hit == "h" || hit == "H" || hit == "hit" || hit == "Hit") {
			while(hit == "h" || hit == "H" || hit == "hit" || hit == "Hit") {
				player[psize].next = deal(deck);
				printf("(h)it again?\n");
				show(player);
				scanf("%s", hit);
			}
		}
		
		else if(hit == "s" || hit == "S" || hit == "stand" || hit == "Stand") {
			int pscore = total(player), dscore = total(dealer);
			char *again;
			if(pscore <= 21 && dscore <= 21) {
				if(pscore > dscore) {printf("You win!");}
				else if(dscore > pscore) {printf("You lose!");}
				else {printf("Tie!");}
			} else if(pscore > 21 && dscore > 21) {
				printf("Double bust! No winner!");
			} else if(pscore > 21 && dscore <= 21) {
				printf("Player bust! Dealer wins!");
			} else if(pscore <= 21 && dscore >21) {
				printf("Dealer bust! You win!");
			}

			printf("Game over! Wanna play again? [y/n]\n");
			scanf("%s", again);

			if (again == "y") {playing = 1;}
			else {destroy_deck(deck); playing = 0;}

		}

	} while(playing);

    return 0;	
 }

