//
// AUTHOR : JOSHUA SCHULTHEISS
// LANGUAGE : C
// PROBLEM STATEMENT : https://www.reddit.com/r/dailyprogrammer/comments/3r7wxz/20151102_challenge_239_easy_a_game_of_threes/
//

#include <stdio.h>

void threes(int number) {
    if(number==1) {
        printf("1\n");
        return;
    } else if (number%3==0) {
        printf("%d 0\n",number);
        number /= 3;
        threes(number);
    } else if (number%3==1) {
        printf("%d -1\n",number);
        number--;
        number /= 3;
        threes(number);
    } else {
        printf("%d 1\n",number);
        number++;
        number /= 3;
        threes(number);
    }
}

int main() {
    int sample = 100;
    threes(sample);     // recursive
    return 0;
}
