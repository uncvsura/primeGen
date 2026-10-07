#include "../header/algos.h"

int main(void){

    uint32_t num;

    printf("Enter even number:\n");
    scanf("%d", &num);

    int print;

    printf("Print? 1(Yes) 0(No):\n");
    scanf("%d", &print);

    printf("Calculating...\n");

    uint32_t pairCount = pairFind(num,print);

    printf("G(%d): %d\n",num,pairCount);

    return 0;

}