#include <stdio.h>

int main() {
    char orig[100], rev[100];
    char *p = orig;
    char *q = rev;
    int len = -1;

    printf("Enter a string: ");
    fgets(orig, sizeof(orig), stdin);

    // Remove newline if fgets adds it
    char *newline = orig;
    while (*newline != '\0') {
        if (*newline == '\n') {
            *newline = '\0';
            break;
        }
        newline++;
    }

    while (*p) {
        p++;
        len++;
    }

    while (len >= 0) {
        p--;
        *q = *p;
        q++;
        len--;
    }

    *q = '\0';

    printf("Reversed string: %s\n", rev);

    return 0;
}

