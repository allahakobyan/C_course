#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itob(int n, char s[], int b) {
    int i = 0;
    int sign = n;

    if (n == 0) {
        s[i++] = '0';
        s[i] = '\0';
        return;
    }

    if (sign < 0 && b == 10)
        n = -n; // only base 10 numbers can be negative

    while (n != 0) {
        int rem = n % b;
        if (rem < 10)
            s[i++] = rem + '0';
        else
            s[i++] = rem - 10 + 'A'; // for hex digits A-F
        n /= b;
    }

    if (sign < 0 && b == 10)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

int main() {
    int n;
    int base;
    char s[50];

    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("Enter base (2-16): ");
    scanf("%d", &base);

    itob(n, s, base);
    printf("Number in base %d: %s\n", base, s);

    return 0;
}
