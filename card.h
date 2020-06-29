#include <stdio.h>
#include <stdlib.h>

typedef struct Card {
  int rank;
  char suit;
  struct Card *next;
} card;

int count_deck(card *deck);
card *shuffle(card *deck);
card *make_deck(void);
void destroy_deck(card *deck);
card *deal(card *deck);
int total(card *card);
void show(card *card);
