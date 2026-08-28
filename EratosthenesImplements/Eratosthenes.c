#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Naive.c"

void findPrimes(unsigned long n);

int main(void){
    unsigned long num;
    printf("Enter number here\n");
    scanf("%lu", &num);
    // printf("Starting naive\n");
    printf("Starting sieve\n");
    printf("Calculating primes...\n");
    clock_t start = clock();
    // primeFinder(num);
    findPrimes(num);
    clock_t end = clock();
    double time = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
}

void findPrimes(unsigned long n){

    unsigned long upper_bound = (1.25506*n)/log(n) + 1;
    unsigned long *primes = malloc(upper_bound*sizeof(unsigned long));

    unsigned long *list = malloc(n*sizeof(unsigned long));

    for (int i = 0; i < n - 1; i++){
        list[i] = i+2;
    }

    printf("done populating");

    unsigned long h = 0;
    int prime_count = 0;

    while(list[h]<n){
        unsigned long k = list[h];
        if(k!=0){
            printf("%lu\n", k);
            primes[prime_count]=k;
            prime_count++;
            if(k<n/2){
                int i = 2;
                while(i*k<n){
                    list[k*i-2]=0;
                    i++;
                }
            }
            
        }
        h++;
    }

    printf("Prime Count: %d\n", prime_count);

}