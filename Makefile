EXEC = dame

CC = cc

CFLAGS  = --std=c99 --pedantic -Wall -W -O2
LDFLAGS = -lm

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -fv *.o $(EXEC) *~