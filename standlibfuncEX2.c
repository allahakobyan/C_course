#include <stdio.h>
#include <time.h>

int main() {
	time_t t;
	time(&t);

	struct tm *current = localtime(&t);


	printf("Date: %04d-%02d-%02d\n",
		current->tm_year + 1900,
		current->tm_mon + 1,
		current->tm_mday);

	printf("Time: %02d:%02d:%02d\n",
		current->tm_hour,
		current->tm_min,
		current->tm_sec);

	return 0;
}
