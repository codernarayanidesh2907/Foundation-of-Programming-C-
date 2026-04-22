#include <stdio.h>

int main() {
    FILE *fp1, *fp2;
    char ch;

    
    fp1 = fopen("demo.txt", "w");

    if(fp1 == NULL) {
        printf("Error creating source file!");
        return 1;
    }

    fprintf(fp1, "Hello! This is sample text.\n");
    fprintf(fp1, "File handling in C.\n");

    fclose(fp1);  

    
    fp1 = fopen("demo.txt", "r");

    
    fp2 = fopen("random.txt", "w");

    if(fp1 == NULL || fp2 == NULL) {
        printf("Error opening file!");
        return 1;
    }

    // Step 4: Copy content
    while((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp2);
    }

    printf("File created and copied successfully!");

    fclose(fp1);
    fclose(fp2);

    return 0;
}