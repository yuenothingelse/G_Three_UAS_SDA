CC=gcc

CFLAGS=-Wall

SRC=main.c \
src/bst.c \
src/search.c \
src/playlist.c \
src/history.c \
src/recommendation.c \
src/fileio.c \
src/menu.c

OUT=drag

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS)

run:
	./drag

clean:
	rm -f drag
