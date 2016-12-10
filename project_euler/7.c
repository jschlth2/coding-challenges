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

	long count = 1;
	long prime = 2;

	while(count != 10001) {
		prime = nextPrime(prime);
		count++;
	}

	printf("%ld\n", prime);

	return 1;

}
