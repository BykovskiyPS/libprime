#include <stdio.h>
#include "prime.h"
#define N 100

void PrimeNumbers(int count) {
    int sieve[N] = {0};
    int i;
    for(i = 2; i * i < count; ++i) {
        if(sieve[i] == 0){
            int j;
            for(j = i * i; j < count; j += i) {
                sieve[j] = 1;
            }
        }
    }
    
    int k;
    for(k = 1; k < count; ++k) {
        if(sieve[k] == 0) {
            printf("%d ", k);
        }
    }
}

