#include <stdio.h>
#include <math.h>

int okay(int a, int b, int c) {

	int i;

	for(i = 1 ; i < 500 ; i++) {
		if(c == i*i && a+b+i == 1000) {
			return 1;
		}
	}

	return 0;

}

int main() {

	int a, b, c;
	long product;

	for(a = 1 ; a < 500 ; a++) {
		int flag = 0;
		for(b = 1 ; b < 500 ; b++) {
			int c = a*a + b*b;
			if( okay(a, b, c) ) {
				product = a * b * sqrt(c);
				break;
			}
		}
		if(flag) {
			break;
		}
	}

	printf("%ld\n", product);

	return 1;

}
