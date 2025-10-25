#include <stdio.h>
#include <string.h>

void swapChars(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *word, int start, int end) {
    if (start == end)
        printf("%s  ", word);
    else {
        for (int i = start; i <= end; i++) {
            swapChars(&word[start], &word[i]);
            permute(word, start + 1, end);
            swapChars(&word[start], &word[i]);
        }
    }
}

int main() {
    char word[] = "abcd";
    printf("Permutations of the word:\n");
    int n = strlen(word);
    permute(word, 0, n - 1);
    printf("\n");
    return 0;
}

