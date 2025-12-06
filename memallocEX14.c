#include <stdio.h>
#include <stdlib.h>

int main() {
	int *arr;
	int n, i, j, temp;

	printf("\nSorting an array using pointers\n");
	printf("--------------------------------\n");

	printf("How many elements? ");
	scanf("%d", &n);


	arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("Memory allocation failed.\n");
		return 0;
	}


	for (i = 0; i < n; i++) {
		printf("Enter value %d: ", i + 1);
		scanf("%d", arr + i);
	}


	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (*(arr + j) < *(arr + i)) {
				temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}

	printf("\nSorted values:\n");
	for (i = 0; i < n; i++) {
		printf(" %d -> %d\n", i + 1, *(arr + i));
	}

	free(arr);
	return 0;
}
