#include <stdio.h>

int main() {
	int arr[25];
	int n, i;

	printf("Pointer example: reading and printing array values\n");
	printf("--------------------------------------------------\n");

	printf("How many elements do you want to enter? ");
	scanf("%d", &n);

	printf("Enter %d integers:\n", n);
	for (i = 0; i < n; i++) {
		printf("Value %d: ", i);
		scanf("%d", arr + i);
	}

	printf("\nYou entered these values:\n");
	for (i = 0; i < n; i++) {
		printf("Index %d -> %d\n", i, *(arr + i));
	}

	return 0;
}
