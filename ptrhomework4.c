#include <stdio.h>
#include <stdlib.h>

int my_strcmp(const char *a, const char *b) {
	int i =0;
	while (a[i] !='\0' && b[i] != '\0') {
		if (a[i]!=b[i]) return a[i]-b[i];
		i++;
	}
	return a[i]-b[i];
}
typedef int (*CompareFunc)(const char* , const char*);

void sortStrings(char *arr[], int n, CompareFunc cmp) {
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<n-i-1 ; j++) {
			if (cmp(arr[j], arr[j+1])>0) {
				char *temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

}

int ascending(const char *a, const char *b) {
	return my_strcmp(a, b);
}

int descending(const char *a, const char *b) {
	return -my_strcmp(a, b);
}


int main() {
	char *arr[]= {"banana", "apple", "orange", "grape"};
	int n=sizeof(arr)/sizeof(arr[0]);


	printf("Original array:\n");
	for (int i=0; i<n; i++) printf("%s\n", arr[i]);

	sortStrings(arr, n, ascending);
	printf("\nSorted ascending:\n");
	for (int i=0; i<n; i++) printf("%s\n", arr[i]);

	sortStrings(arr, n, descending);
	printf("\nSorted  descending\n");
	for (int i=0; i<n; i++) printf("%s\n", arr[i]);

	return 0;
}
