#include <stdio.h>

int main() {
    int a, b, i, gcd;
    int sd1 = 0, sd2 = 0;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    for(i = 2; i <= a; i++) {
        if(a % i == 0) {
            sd1 = i;
            break;
        }
    }

    for(i = 2; i <= b; i++) {
        if(b % i == 0) {
            sd2 = i;
            break;
        }
    }

    printf("\nSmallest divisor of %d = %d", a, sd1);
    printf("\nSmallest divisor of %d = %d", b, sd2);

    for(i = 1; i <= a && i <= b; i++) {
        if(a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    printf("\nGCD of %d and %d = %d", a, b, gcd);

    return 0;
}