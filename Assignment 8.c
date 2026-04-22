#include <stdio.h>

int main() {
    float m1, m2, m3, m4, m5;
    float total, percentage;

    printf("Enter marks of 5 subjects:\n");
    scanf("%f %f %f %f %f", &m1, &m2, &m3, &m4, &m5);

    // Check pass or fail
    if(m1 < 40 || m2 < 40 || m3 < 40 || m4 < 40 || m5 < 40) {
        printf("Result: FAIL");
    } 
    else {
        total = m1 + m2 + m3 + m4 + m5;
        percentage = total / 5;

        printf("Result: PASS");
        printf("\nPercentage: %.2f%%", percentage);

        // Grade using if-else ladder
        if(percentage >= 75)
            printf("\nGrade: Distinction");
        else if(percentage >= 60 && percentage < 75)
            printf("\nGrade: First Division");
        else if(percentage >= 50 && percentage < 60)
            printf("\nGrade: Second Division");
        else if(percentage >= 40 && percentage < 50)
            printf("\nGrade: Third Division");
    }

    return 0;
}