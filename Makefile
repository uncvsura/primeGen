CC     = gcc
CFLAGS = -Iheader -Wall -Wextra
LDLIBS = -lm

primeGen: main/primeGenMain.c algorithms/Sieves/SuraSieves/SuraSieveV5.c
	$(CC) $(CFLAGS) $^ -o $@

pairFind: main/pairFindMain.c algorithms/Goldbach/pairFinder.c algorithms/Sieves/SuraSieves/SuraSieveV5.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f primeGen pairFind

.PHONY: clean