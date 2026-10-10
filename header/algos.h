#ifndef ALGOS_H
#define ALGOS_H

#include "external.h"

uint32_t priminatorv8(bool *primes, uint32_t n, bool print);

uint32_t pairFind(bool *primes, uint32_t even, bool print);

void cometMaker(uint32_t n);

void setBit(uint8_t* x, int i);

void clearBit(uint8_t *x, int i);

uint8_t checkBit(uint8_t *x, int i);

uint64_t priminatorv9(uint8_t *primes, uint64_t n, bool print);

#endif