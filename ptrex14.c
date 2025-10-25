#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, temp;
    int *a;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    a = (int*)malloc(n * sizeof(int));

    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (*(a + i) > *(a + j)) {
                temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");

    free(a);
    return 0;
}
