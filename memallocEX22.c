#include <stdio.h>

int main() {
	char text[50];
	char reversed[50];
	char *p1 = text;
	char *p2 = reversed;
	int len = 0;

	printf("\nReverse a string using pointers\n");
	printf("--------------------------------\n");

	printf("Enter a word: ");
	scanf("%49s", text);


	while (*(p1 + len) != '\0') {
		len++;
	}

	for (int i = len - 1; i >= 0; i--) {
		*p2 = *(p1 + i);
		p2++;
	}

	*p2 = '\0';  // end of string marker

	printf("Reversed: %s\n\n", reversed);

	return 0;
}
