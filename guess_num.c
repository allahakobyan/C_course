#include <stdio.h>
#include <stdlib.h>

int main(){
	int nu;
	int n=rand();
	printf("Guess the number: ");
	scanf("%d", &nu);

	if(nu==n)
		printf("You guessed it right, its %d", n);
	else
		printf("Wrong number it was %d, try again.\a\n", n);
	return 0;
}
