#include <stdio.h>
#include <math.h>

int main() {
    int choice, n, i, isPrime = 1;
    float result;

    printf("\n--- NUMBER OPERATIONS ---\n");
    printf("1. Square Root\n");
    printf("2. Square\n");
    printf("3. Cube\n");
    printf("4. Check Prime\n");
    printf("5. Factorial\n");
    printf("6. Prime Factors\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter a number: ");
    scanf("%d", &n);

    if(choice == 1) {   // Square root
        if(n >= 0) {
            result = sqrt(n);
            printf("Square Root = %.2f", result);
        } else {
            printf("Invalid input for square root");
        }
    }

    else if(choice == 2) {   // Square
        printf("Square = %d", n * n);
    }

    else if(choice == 3) {   // Cube
        printf("Cube = %d", n * n * n);
    }

    else if(choice == 4) {   // Prime check
        if(n <= 1) {
            isPrime = 0;
        } else {
            for(i = 2; i <= n/2; i++) {
                if(n % i == 0) {
                    isPrime = 0;
                    break;
                }
            }
        }

        if(isPrime)
            printf("Prime Number");
        else
            printf("Not a Prime Number");
    }

    else if(choice == 5) {   // Factorial
        int fact = 1;
        if(n < 0) {
            printf("Factorial not defined");
        } else {
            for(i = 1; i <= n; i++) {
                fact *= i;
            }
            printf("Factorial = %d", fact);
        }
    }

    else if(choice == 6) {   // Prime factors
        printf("Prime Factors: ");
        for(i = 2; i <= n; i++) {
            while(n % i == 0) {
                printf("%d ", i);
                n = n / i;
            }
        }
    }

    else {
        printf("Invalid choice");
    }

    return 0;
}