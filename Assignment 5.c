#include <stdio.h>

int main() {
    int choice, i, j;
    int A[10][10], B[10][10], C[10][10];
    int r, c;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter Matrix A:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d", &B[i][j]);

    printf("\n1. Addition\n2. Saddle Point\n3. Inverse (2x2 only)\n4. Magic Square Check\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1: // Addition
            printf("Result Matrix:\n");
            for(i=0;i<r;i++) {
                for(j=0;j<c;j++) {
                    C[i][j] = A[i][j] + B[i][j];
                    printf("%d ", C[i][j]);
                }
                printf("\n");
            }
            break;

        case 2: // Saddle Point
            for(i=0;i<r;i++) {
                int min = A[i][0], col = 0;
                for(j=1;j<c;j++) {
                    if(A[i][j] < min) {
                        min = A[i][j];
                        col = j;
                    }
                }

                int k, flag = 1;
                for(k=0;k<r;k++) {
                    if(A[k][col] > min) {
                        flag = 0;
                        break;
                    }
                }

                if(flag) {
                    printf("Saddle Point = %d\n", min);
                    return 0;
                }
            }
            printf("No Saddle Point\n");
            break;

        case 3: // Inverse (2x2 only)
            if(r == 2 && c == 2) {
                int det = A[0][0]*A[1][1] - A[0][1]*A[1][0];

                if(det == 0) {
                    printf("Inverse not possible\n");
                } else {
                    printf("Inverse Matrix:\n");
                    printf("%.2f %.2f\n", (float)A[1][1]/det, (float)-A[0][1]/det);
                    printf("%.2f %.2f\n", (float)-A[1][0]/det, (float)A[0][0]/det);
                }
            } else {
                printf("Only 2x2 matrix allowed\n");
            }
            break;

        case 4: // Magic Square Check
            int sum = 0, magic = 1;

            for(j=0;j<c;j++)
                sum += A[0][j];

            for(i=0;i<r;i++) {
                int rowSum = 0;
                for(j=0;j<c;j++)
                    rowSum += A[i][j];
                if(rowSum != sum)
                    magic = 0;
            }

            for(j=0;j<c;j++) {
                int colSum = 0;
                for(i=0;i<r;i++)
                    colSum += A[i][j];
                if(colSum != sum)
                    magic = 0;
            }

            if(magic)
                printf("Magic Square\n");
            else
                printf("Not a Magic Square\n");

            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}