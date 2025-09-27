#include <stdio.h>

void to_str(int n, char s[]) {
    int sign;
    int i = 0;

    if (n < 0) {
        sign = n;
        n = -n;
    }
    do {
        int digit = n % 10;
        s[i++] = '0' + digit;
        n = n / 10;
    } while (n > 0);

    if (sign < 0) s[i++] = '-';
    s[i++] = '\0';

    --i;
    int j = 0;
    while (j < i) {
        char tmp = s[j];
        s[j] = s[i - 1];
        s[i - 1] = tmp;
        j++;
        i--;
    }
}

int main(void) {
    int num;
    char str_num[11];

    scanf("%d", &num);
    to_str(num, str_num);
    printf("The converted value is: %s\n", str_num);

    return 0;
}

