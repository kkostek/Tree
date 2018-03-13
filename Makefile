CFLAGS ?= -Wall -Wextra -g

solution: solution.o tree.o list.o
	$(CC) $(CFLAGS) -o solution solution.o tree.o list.o
	
list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

tree.o: tree.c tree.h list.h
	$(CC) $(CFLAGS) -c tree.c

solution.o: solution.c tree.h list.h
	$(CC) $(CFLAGS) -c solution.c

clean:
	rm -f *.o solution

.PHONY: clean
