#include <stdio.h>
#include <stdlib.h>
int main() {
	int rows, cols;

	printf("Enter number of rows and columns: ");
	scanf("%d %d", &rows, &cols);

	int i, j;

	int **matrix=(int**)malloc(rows* sizeof(int*));
	for (int i=0; i<rows; i++) {
		matrix[i]=(int*)malloc(cols * sizeof(int));
	}
	printf("Enter elements of the matrix:\n");
	for (int i=0; i<rows ; i++) {
		for (int j=0; j<cols; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	printf("Transpose of the matrix:\n");
	for (int i=0; i<cols; i++) {
		for (int j=0; j<rows; j++) {
			printf("%d ", matrix[j][i]);
		}
		printf("\n");
	}
	for (int i=0; i<rows; i++) {
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}
