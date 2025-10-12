#include <stdio.h>

#define MAX 100

double stack[MAX];
int top = -1;

void push(double x) { stack[++top] = x; }
double pop() { return stack[top--]; }

void apply(char op) {
    double b = pop(), a = pop();
    switch (op) {
        case '+': push(a + b); break;
        case '-': push(a - b); break;
        case '*': push(a * b); break;
        case '/': push(a / b); break;
        case '%': push((int)a % (int)b); break;
    }
}

void eval() {
    int c;
    double num = 0;
    int reading = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            reading = 1;
        } else if (c == ' ' || c == '\t') {
            if (reading) push(num), num = 0, reading = 0;
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
            if (reading) push(num), num = 0, reading = 0;
            apply(c);
        } else if (c == '\n') {
            if (reading) push(num), num = 0, reading = 0;
            if (top >= 0) printf("Result: %.2f\n", stack[top]);
            top = -1;
            printf("Enter another: ");
        }
    }
}

int main() {

    printf("Separate your numbers with ' ' please\n");
    printf("Enter postfix expressions (Ctrl+D to exit): ");
    eval();
    return 0;
}

