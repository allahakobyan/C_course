#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i;
	float *arr, maxVal;

	printf("\nDynamic Memory Allocation: Find the largest number\n");
	printf("---------------------------------------------------\n");

	printf("How many numbers do you want to enter (1–100)? ");
	scanf("%d", &n);

	arr = (float *)calloc(n, sizeof(float));
	if (arr == NULL) {
		printf("Memory allocation failed.\n");
		return 0;
	}


	for (i = 0; i < n; i++) {
		printf("Enter value %d: ", i + 1);
		scanf("%f", arr + i);
	}

	maxVal = arr[0];

	for (i = 1; i < n; i++) {
		if (*(arr + i) > maxVal) {
			maxVal = *(arr + i);
		}
	}

	printf("\nLargest value = %.2f\n\n", maxVal);

	free(arr);
	return 0;
}
