#include <stdio.h>
#include <stdlib.h>

#define MAXLINES 1000
#define MAXLEN 1000

int my_strlen(char *s) {
	int len=0;
	while (s[len] != '\0') len++;
	return len;
}

void my_strcpy(char *dest, char *src) {
	int i=0;
	while (src[i] != '\0') {
		dest[i]=src[i];
		i++;
	}
	dest[i] = '\0';
}

int main(int argc, char *argv[]) {
	int n=10;

	if (argc==2) {
		if (argv[1][0]=='-') {
			n=0;
			int i = 1;
			while (argv[1][i]!= '\0') {
				n=n*10+(argv[1][i]-'0');
				i++;
			}
			if (n<=0) n=10;
		}
	}
		char *lines[MAXLINES];
		int count = 0;
		char buffer[MAXLEN];


		while (fgets(buffer, MAXLEN, stdin) != NULL) {
			int len = my_strlen(buffer);
			lines[count]=(char*)malloc((len+1) * sizeof(char));
			if (lines[count]==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
			}
			my_strcpy(lines[count], buffer);
			count++;
			if (count >= MAXLINES) break;
		}

		int start = count - n;
		if (start<0) start=0;

		for (int i=start; i<count; i++) {
			printf("%s", lines[i]);
			free(lines[i]);

		}

		return 0;
}
