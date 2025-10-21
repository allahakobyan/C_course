#include <stdio.h>
#include <string.h>

int main() {
        int n;
        printf("Enter the number of names: ");
        scanf("%d", &n);

        char names[n][50];
        printf("Enter %d names:\n", n);
        for (int i=0; i<n; i++) {
                scanf("%s", names[i]);
        }
        printf("Duplicate names:\n");
        int found=0;
        for (int i=0; i<n; i++) {
                for(int j=i+1; j<n; j++) {
                        if (strcmp(names[i], names[j])==0) {
                                printf("%s\n", names[i]);
                                found=1;
                                break;
                        }
                }
        }
        if(!found) {
                printf("no duplicates.\n");
        }

        return 0;
}
