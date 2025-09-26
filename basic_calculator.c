#include <stdio.h>
int main(void)
{
        double num1, num2;
        char op;

        printf("Please enter an operator \'+ , -, *, /\' ");
        scanf(" %c", &op);

        while(op!='+' && op!='-' && op!='*' && op!='/')
        {
                printf("Invalid choice! Try again.\a\n");
                scanf(" %c", &op);
        }


        printf("Please enter the first number: ");
        scanf(" %lf", &num1);

        printf("Please enter the second number: ");
        scanf("%lf", &num2);

        switch(op)
        {
                case '+':
                        printf("The sum of the numbers is: %lf\n", num1+num2);
                        break;
                case '-':
                        printf("The difference of the numbers is: %lf\n", num1-num2);
                        break;
                case '*':
                        printf("The multiplication of the numbers is: %lf\n", num1*num2);
                        break;
                case '/':
                        printf("The division of the numbers is: %lf\n", num1/num2);
                        break;
                default:
                        printf("Invalid choice!\a\n");
                        break;
        }
        return 0;
}
