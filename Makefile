CC     = gcc
CFLAGS = -Iheader -Wall -Wextra
LDLIBS = -lm

primeGen: main/primeGenMain.c Sieves/SuraSieves/SuraSieveV5.c
	$(CC) $(CFLAGS) $^ -o $@

pairFind: main/pairFindMain.c pairFinder.c Sieves/SuraSieves/SuraSieveV5.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f primeGen pairFind

.PHONY: clean