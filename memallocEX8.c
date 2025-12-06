#include <stdio.h>
#include <string.h>


void swapChars(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void permute(char *s, int left, int right) {
	if (left == right) {
		printf("%s  ", s);
		return;
	}

	for (int i = left; i <= right; i++) {
		swapChars(s + left, s + i);
		permute(s, left + 1, right);
		swapChars(s + left, s + i);
	}
}

int main() {
	char str[] = "abcd";
	int len = strlen(str);

	printf("\nPermutation of characters using pointers:\n");
	printf("------------------------------------------\n");

	permute(str, 0, len - 1);

	printf("\n\n");
	return 0;
}
