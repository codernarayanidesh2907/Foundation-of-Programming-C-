#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp;
    int choice, i, len, flag = 1;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("\n1. Length\n2. Reverse\n3. Equality Check\n4. Palindrome\n5. Substring Check\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1) {   
        len = strlen(str1);
        printf("Length = %d", len);
    }

    else if(choice == 2) {   
        len = strlen(str1);
        for(i = 0; i < len/2; i++) {
            temp = str1[i];
            str1[i] = str1[len - i - 1];
            str1[len - i - 1] = temp;
        }
        printf("Reversed string = %s", str1);
    }

    else if(choice == 3) {   
        printf("Enter second string: ");
        scanf("%s", str2);

        if(strcmp(str1, str2) == 0)
            printf("Strings are Equal");
        else
            printf("Strings are Not Equal");
    }

    else if(choice == 4) {   
        len = strlen(str1);
        for(i = 0; i < len/2; i++) {
            if(str1[i] != str1[len - i - 1]) {
                flag = 0;
                break;
            }
        }

        if(flag)
            printf("Palindrome String");
        else
            printf("Not a Palindrome");
    }

    else if(choice == 5) {   
        printf("Enter substring: ");
        scanf("%s", str2);

        if(strstr(str1, str2) != NULL)
            printf("Substring found");
        else
            printf("Substring not found");
    }

    else {
        printf("Invalid choice");
    }

    return 0;
}