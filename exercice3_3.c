#include <stdio.h>
#include <ctype.h>

void expand(const char s1[], char s2[]) {
    int i, j;
    char c;

    for (i = 0, j = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '-' && i > 0 && s1[i+1] != '\0') {
            // check if we can expand: s1[i-1] to s1[i+1]
            if ((islower(s1[i-1]) && islower(s1[i+1]) && s1[i-1] <= s1[i+1]) ||
                (isupper(s1[i-1]) && isupper(s1[i+1]) && s1[i-1] <= s1[i+1]) ||
                (isdigit(s1[i-1]) && isdigit(s1[i+1]) && s1[i-1] <= s1[i+1])) {

                for (c = s1[i-1] + 1; c <= s1[i+1]; c++) {
                    s2[j++] = c;
                }
                i++;
            } else {
                s2[j++] = '-';
            }
        } else {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

int main() {
    char input[100], output[500];

    printf("Enter shorthand string: ");
    scanf("%99s", input);

    expand(input, output);

    printf("Expanded string: %s\n", output);
    return 0;
}

