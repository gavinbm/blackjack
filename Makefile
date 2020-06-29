all:game
game: game.o card.o
	gcc -o game game.o card.o

c2o: gameO cardO
gameO: game.c card.h
	gcc -c game.c -I ~/include
cardO: card.c card.h
	gcc -c card.c -I ~/include

clean:
	rm -f *.o game
