#include <stdio.h>
#include <stdlib.h>

typedef struct Card{
	int rank;
	char suit;
	struct Card *next;
} card;

card *make_deck(void);
card *shuffle(card *deck);
card *deal(card *deck);
int count(card *deck);
int total(card *deck);
void destroy(card *deck);
void show(card *deck);

int main() {
	card *deck = make_deck();
	shuffle(deck);
	return 0;
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

card *shuffle(card *deck) {
	card *ndeck[52];
	int c = 0;
	//filling the ndeck array
	for(card *tmp = deck; tmp->next != NULL; tmp = tmp->next) {
		ndeck[c] = tmp;
		c++;
		printf("%d%c\n", ndeck[c]->rank, ndeck[c]->suit);	
	}
	/*//randomizing ndeck array
	for(int i = 0; i < 51; i++) {
		int j = i + rand() / (52/(52-i) + 1);
		card *tmp = ndeck[j];
		ndeck[j] = ndeck[i];
		ndeck[i] = tmp;
		printf("%d%c\n", ndeck[i]->rank, ndeck[i]->suit);
	}*/
	//making new linked list out of ndeck array
	printf("\n");
	card *head = ndeck[0]; 
	for(int i = 1; i < 52; i++) {
		head->next = ndeck[i];
	}
	show(head);
	return head;
}

card *deal(card *deck) {
	card *ret = (card*)malloc(sizeof(card));

	for(card *tmp = deck; deck->next != NULL; tmp = tmp->next) {
		if(tmp->next == NULL) {
			ret = tmp;
			ret->next = malloc(sizeof(card));
			deck = NULL;
		}
	}
	return ret;
}

int count(card *deck) {
	int count = 0;
	for(card *tmp = deck; tmp->next != NULL; tmp = tmp->next) {
		count++;
	}
	return count;
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

void show(card *deck) {
	for(card *tmp = deck; tmp->next != NULL; tmp = tmp->next) {
		printf("%d%c\n", tmp->rank, tmp->suit);
	}
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
