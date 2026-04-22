#include <stdio.h>

int main() {
    int choice;
    float a, b, result;
    int i, n, fact;

    printf("\n--- CALCULATOR ---\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n");
    printf("4. Division\n5. Power (x^y)\n6. Factorial (x!)\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice >= 1 && choice <= 5) {
        printf("Enter two numbers: ");
        scanf("%f %f", &a, &b);
    }

    if(choice == 1) {
        printf("Result = %.2f", a + b);
    }
    else if(choice == 2) {
        printf("Result = %.2f", a - b);
    }
    else if(choice == 3) {
        printf("Result = %.2f", a * b);
    }
    else if(choice == 4) {
        if(b != 0)
            printf("Result = %.2f", a / b);
        else
            printf("Error! Division by zero");
    }
    else if(choice == 5) {   
        result = 1;
        for(i = 1; i <= b; i++) {
            result = result * a;
        }
        printf("Result = %.2f", result);
    }
    else if(choice == 6) {   
        printf("Enter a number: ");
        scanf("%d", &n);

        fact = 1;
        for(i = 1; i <= n; i++) {
            fact = fact * i;
        }
        printf("Factorial = %d", fact);
    }
    else {
        printf("Invalid choice");
    }

    return 0;
}