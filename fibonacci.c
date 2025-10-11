#include <stdio.h>

int fib(int n){
	if (n==0)
		return 0;
	else if (n==1)
		return 1;
	else{
		return fib(n-1)+fib(n-2);
	}
}

int main() {
	int n;
	int i;
	printf("Enter the N: ");
	scanf("%d", &n);
	printf("The fibonacci numbers up to %d are\n", n);

	for(i=0; i<=n; i++) {
		printf("F%d : %d\n",i, fib(i));

	}

	printf("\n");
	return 0;
}



