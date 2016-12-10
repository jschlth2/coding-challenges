#include <stdio.h>
#include <math.h>

long nextPrime(long curr_prime) {

	long next = curr_prime + 1;
	long i;

	for(i = 2 ; i < sqrt(next) ; i++) {
		if(next % i == 0) return nextPrime(curr_prime + 1);
	}

	return curr_prime + 1;

}

int main() {
	
	long number = 600851475143;
	long largest = -1;

	while(number != 1) {
		long prime = 2;;
		while(number % prime != 0) {
			prime = nextPrime(prime);
		}
		number /= prime;
		if(prime > largest) {
			largest = prime;
		}
	}	

	printf("%ld\n", largest);

	return 1;

}
