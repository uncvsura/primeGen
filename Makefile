CC      = gcc
CFLAGS  = -Iheader -O3 -Wall -Wextra -Xpreprocessor -fopenmp -I$(shell brew --prefix libomp)/include
LDFLAGS = -L$(shell brew --prefix libomp)/lib
LDLIBS  = -lm -lomp

SIEVE_DEPS = algorithms/Sieves/SuraSieves/SuraSieveV5.c
GOLD_DEPS = $(SIEVE_DEPS) algorithms/Goldbach/pairFinder.c
COMET_DEPS = $(GOLD_DEPS) algorithms/Goldbach/cometMaker.c
BITSIEVE_DEPS = algorithms/Sieves/SSieveBitArray.c

bitSieve: main/bitSieveMain.c $(BITSIEVE_DEPS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

primeGen: main/primeGenMain.c $(SIEVE_DEPS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

pairFind: main/pairFindMain.c $(GOLD_DEPS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

comet: main/cometMain.c $(COMET_DEPS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

clean:
	rm -f primeGen pairFind comet bitSieve

.PHONY: clean