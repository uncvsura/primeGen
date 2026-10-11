ifeq ($(OS),Windows_NT)
    DETECTED_OS := Windows
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        DETECTED_OS := Linux
    endif
    ifeq ($(UNAME_S),Darwin)
        DETECTED_OS := macOS
    endif
endif

CC      = gcc
CFLAGS  = -Iheader -O3 -Wall -Wextra
LDFLAGS =
LDLIBS  = -lm

ifeq ($(DETECTED_OS),macOS)

    LIBOMP_PREFIX := $(shell brew --prefix libomp 2>/dev/null)
    ifneq ($(LIBOMP_PREFIX),)
        CFLAGS  += -Xpreprocessor -fopenmp -I$(LIBOMP_PREFIX)/include
        LDFLAGS += -L$(LIBOMP_PREFIX)/lib
        LDLIBS  += -lomp
    else
        CFLAGS  += -Xpreprocessor -fopenmp
        LDLIBS  += -lomp
    endif
else
    CFLAGS += -fopenmp
endif

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
