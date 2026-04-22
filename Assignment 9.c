#include <stdio.h>

int main() {
    int num, original, rem;
    int sum = 0;

    printf("Enter a 3-digit number: ");
    scanf("%d", &num);

    original = num;

    while(num > 0) {
        rem = num % 10;          
        sum = sum + (rem * rem * rem);  
        num = num / 10;          
    }

    if(sum == original)
        printf("Armstrong Number");
    else
        printf("Not an Armstrong Number");

    return 0;
}