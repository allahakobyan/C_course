#include <stdio.h>

int main() {
    char alph[26];
    int i;
    char *ptr;

    ptr = alph;
    for (i = 0; i < 26; i++) {
        *ptr = 'A' + i;
        ptr++;
    }

    ptr = alph;

    printf("Uppercase letters A-Z:\n");
    for (i = 0; i < 26; i++) {
        printf("%c ", *ptr);
        ptr++;
    }
    printf("\n");

    return 0;
}

