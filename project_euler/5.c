#include <stdio.h>

int okay(int num) {

	int i;

	for(i = 1 ; i <= 20 ; i++) {
		if(num%i != 0) return 0;
	}

	return 1;

}

int main() {

	int curr = 2520;

	while(1) {
		if(okay(curr)) break;
		curr++;			
	}

	printf("%d\s", curr);

	return 1;

}
