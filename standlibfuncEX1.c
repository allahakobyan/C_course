#include <stdio.h>
#include <string.h>

int main() {
        char str1[101], str2[101], copy[101];

        printf("Enter first string: ");
        fgets(str1, 101, stdin);

        printf("Enter second string: ");
        fgets(str2, 101, stdin);

        str1[strcspn(str1, "\n")] = '\0';
        str2[strcspn(str2, "\n")] = '\0';

        char concat[205];
        strcpy(concat, str1);
        strcat(concat, str2);
        printf("\nConcatenated: %s\n", concat);

        if (strcmp(str1, str2) == 0)
                printf("Strings are the same.\n");
        else
                printf("Strings are different.\n");

        printf("Length of string 1: %lu\n", strlen(str1));
        printf("Length of string 2: %lu\n", strlen(str2));

        strcpy(copy, str1);
        printf("Copy of string 1: %s\n", copy);

        return 0;
}
