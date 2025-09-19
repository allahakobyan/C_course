#include <stdio.h>

int main() {
    char line[1000];
    int i = 0;
    char c;

    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            line[i++] = c;
        } else {
            line[i] = '\0';

            if (i > 80) {
                printf("%s\n", line);
            }

            i = 0;
        }
    }

    return 0;
}

