#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Point{
    unsigned long x;
    unsigned long y;
};

void primeFinder(unsigned long n);

// int main(void){
//     printf("starting\n");
//     unsigned long num;
//     printf("Enter number here\n");
//     scanf("%lu", &num);
//     printf("Printing primes...\n");
//     clock_t start = clock();
//     pairFinder(num);
//     clock_t end = clock();
//     double time = ((double) (end - start))/CLOCKS_PER_SEC;
//     printf("%f\n", time);
//     return 0;
// }



void naive(unsigned long n){

    unsigned long k = n;
    unsigned long upper_bound = (1.25506*k)/log(k) + 1;
    unsigned long *primes = malloc(upper_bound*sizeof(unsigned long));

    primes[0] = 2;
    int prime_count = 1;
    unsigned long i = 3;

    while(i<k){
        bool isPrime = true;

        unsigned long max_thresh = sqrt(i) + 1;

        int h = 0;

        while(primes[h]<=max_thresh && primes[h]!=0 && isPrime){
            if(i%primes[h]==0){isPrime=false;}
            h++;
        }

        if(isPrime){
            primes[prime_count] = i;
            prime_count++;
            // printf("%lu\n", i);
        }

        i++;
    }

    printf("%d\n", prime_count);
}