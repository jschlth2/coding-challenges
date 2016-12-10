#include <stdio.h>
#include <math.h>

long nextPrime(long curr_prime) {

        long next = curr_prime + 1;
        long i;

        for(i = 2 ; i < sqrt(next)+1 ; i++) {
                if(next % i == 0) return nextPrime(next);
        }

        return curr_prime + 1;

}

int main() {

        long sum = 0;
        long prime = 2;

        while(prime < 2000000) {
		sum += prime;
                prime = nextPrime(prime);
        }

        printf("%ld\n", sum);

        return 1;

}
