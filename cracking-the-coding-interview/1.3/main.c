#import <stdio.h>
#import <string.h>

void URLify(char* url, int len) {
	int spaces = 0;

	int idx;
	for(idx = 0 ; idx < len ; idx++) {
		if(url[idx] == ' ') spaces++;
	}

	int scan_idx = (len-1) - (spaces*2);
	int print = len-1;
	for(idx = scan_idx ; idx >=0 ; --idx) {
		if(url[idx] == ' ') {
			url[print] = '0';
			url[print-1] = '2';
			url[print-2] = '%';
			print -= 3;
		} else {
			url[print] = url[idx];
			print -= 1;
		}
	}

	return;
}

int main() {

	char str[43];
	strcpy(str, "Joshua Schultheiss: Computer Engineer");

	printf("%s\n", str);
	URLify(str, 43);
	printf("%s\n", str);

	return 1;

}
