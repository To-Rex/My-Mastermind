CC=gcc
CFLAGS=-I.
DEPS = my_mastermind.c
OBJ = my_mastermind.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

make:
	$(CC) my_mastermind.c -o my_mastermind
.PHONY: clean
clean:
	rm -f *.o my_mastermind 
