#include<stdio.h>

int main() {

	int prev1 = 1;
	int prev2 = 2;
	int curr  = 3;
	int sum   = 2;

	while(curr < 4000000) {
		if(curr%2 ==0) {
			sum += curr;
		}
		prev1 = prev2;
		prev2 = curr;
		curr = prev1 + prev2;
	}

	printf("%d\n",sum);

	return 1;

}
