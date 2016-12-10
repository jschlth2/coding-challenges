#include <stdio.h>

int main() {

	long i;
	long sum_of_squares = 0;
	long square_of_sums = 0;
	
	for(i = 0 ; i < 101 ; i++) {
		sum_of_squares += i*i;
		square_of_sums += i;
	}

	square_of_sums *= square_of_sums;

	printf("%ld\n", square_of_sums - sum_of_squares);

	return 1;	

}
