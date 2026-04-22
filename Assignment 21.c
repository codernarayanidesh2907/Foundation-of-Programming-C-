#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    int choice;

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("\n1.Length  2.Copy  3.Concat  4.Compare  5.Substring\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Length = %lu", strlen(s1));
    }

    else if(choice == 2) {
        strcpy(s2, s1);
        printf("Copied = %s", s2);
    }

    else if(choice == 3) {
        printf("Enter second string: ");
        scanf("%s", s2);
        strcat(s1, s2);
        printf("Result = %s", s1);
    }

    else if(choice == 4) {
        printf("Enter second string: ");
        scanf("%s", s2);
        if(strcmp(s1, s2) == 0)
            printf("Equal");
        else
            printf("Not Equal");
    }

    else if(choice == 5) {
        printf("Enter substring: ");
        scanf("%s", s2);
        if(strstr(s1, s2))
            printf("Found");
        else
            printf("Not Found");
    }

    else {
        printf("Invalid choice");
    }

    return 0;
}