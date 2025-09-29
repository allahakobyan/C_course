#include <stdio.h>

// escape: convert real \n and \t into visible \\n and \\t
void escape(char s[], const char t[]) {
    int i, j;
    for (i = 0, j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

// unescape: convert visible \\n and \\t into real \n and \t
void unescape(char s[], const char t[]) {
    int i, j;
    for (i = 0, j = 0; t[i] != '\0'; i++) {
        if (t[i] == '\\') {
            i++;
            switch (t[i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

int main() {
    char input[300];
    char output[600];
    int choice;

    printf("Choose an option:\n");
    printf("1. Escape (make \\n and \\t visible)\n");
    printf("2. Unescape (turn visible \\n and \\t into real characters)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    getchar();

    printf("\nEnter text (finish with Ctrl+D / Ctrl+Z):\n");

    int c, i = 0;
    while ((c = getchar()) != EOF && i < 299) {
        input[i++] = (char)c;
    }
    input[i] = '\0';

    switch (choice) {
        case 1:
            escape(output, input);
            printf("\nEscaped string:\n%s\n", output);
            break;
        case 2:
            unescape(output, input);
            printf("\nUnescaped string:\n%s\n", output);
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
    }

    return 0;
}

