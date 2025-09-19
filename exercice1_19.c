#include <stdio.h>

int main() {
    char line[1000];
    int len = 0, c;

    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            line[len++] = c;
        } else {
            for (int i = len - 1; i >= 0; i--)
                putchar(line[i]);
            putchar('\n');
            len = 0;
        }
    }
    return 0;
}
