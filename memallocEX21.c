#include <stdio.h>

int main() {
	char letters[27];
	char *p;
	int i;

	printf("\nDisplaying alphabets using a pointer\n");
	printf("-----------------------------------\n");

	p = letters;


	for (i = 0; i < 26; i++) {
		*(p + i) = 'A' + i;
	}

	printf("Alphabets:\n");


	p = letters;
	for (i = 0; i < 26; i++) {
		printf(" %c ", *(p + i));
	}

	printf("\n\n");
	return 0;
}
