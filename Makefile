CC     = gcc
CFLAGS = -Iheader -Wall -Wextra
LDLIBS = -lm

SIEVE_DEPS = algorithms/Sieves/SuraSieves/SuraSieveV5.c
GOLD_DEPS = $(SIEVE_DEPS) algorithms/Goldbach/pairFinder.c
COMET_DEPS = $(GOLD_DEPS) algorithms/Goldbach/cometMaker.c

primeGen: main/primeGenMain.c $(SIEVE_DEPS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

pairFind: main/pairFindMain.c $(GOLD_DEPS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

cometMake: main/cometMain.c $(COMET_DEPS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

clean:
	rm -f primeGen pairFind cometMake

.PHONY: clean