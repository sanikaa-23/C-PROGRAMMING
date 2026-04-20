#include <stdio.h>

void matrixAddition(int a[10][10], int b[10][10], int r, int c) {
    int sum[10][10];
    printf("\nResultant Matrix (A + B):\n");
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

void saddlePoint(int m[10][10], int r, int c) {
    int found = 0;

    for(int i=0;i<r;i++) {
        int rowMin = m[i][0], colIndex = 0;

        for(int j=1;j<c;j++) {
            if(m[i][j] < rowMin) {
                rowMin = m[i][j];
                colIndex = j;
            }
        }

        int isSaddle = 1;
        for(int k=0;k<r;k++) {
            if(m[k][colIndex] > rowMin) {
                isSaddle = 0;
                break;
            }
        }

        if(isSaddle) {
            printf("\nSaddle Point Found: %d at position (%d, %d)\n", rowMin, i+1, colIndex+1);
            found = 1;
        }
    }

    if(!found)
        printf("\nNo Saddle Point Found.\n");
}

void inverse2x2(int m[2][2]) {
    int det = (m[0][0]*m[1][1]) - (m[0][1]*m[1][0]);

    if(det == 0) {
        printf("\nInverse not possible (Determinant = 0).\n");
        return;
    }

    printf("\nInverse Matrix:\n");
    printf("%.2f %.2f\n", (float)m[1][1]/det, (float)(-m[0][1])/det);
    printf("%.2f %.2f\n", (float)(-m[1][0])/det, (float)m[0][0]/det);
}

void magicSquareCheck(int m[3][3]) {
    int sum = 0;
    for(int j=0;j<3;j++)
        sum += m[0][j];

    for(int i=0;i<3;i++) {
        int rowSum = 0;
        for(int j=0;j<3;j++)
            rowSum += m[i][j];
        if(rowSum != sum) {
            printf("\nNot a Magic Square.\n");
            return;
        }
    }

    for(int j=0;j<3;j++) {
        int colSum = 0;
        for(int i=0;i<3;i++)
            colSum += m[i][j];
        if(colSum != sum) {
            printf("\nNot a Magic Square.\n");
            return;
        }
    }

    int diag1 = m[0][0] + m[1][1] + m[2][2];
    int diag2 = m[0][2] + m[1][1] + m[2][0];

    if(diag1 == sum && diag2 == sum)
        printf("\nIt is a Magic Square.\n");
    else
        printf("\nNot a Magic Square.\n");
}

int main() {
    int choice;
    int r, c;
    int a[10][10], b[10][10];

    printf("\n--- MATRIX OPERATIONS MENU ---\n");
    printf("1. Addition of Two Matrices\n");
    printf("2. Saddle Point of a Matrix\n");
    printf("3. Inverse of 2x2 Matrix\n");
    printf("4. Magic Square Check (3x3)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r, &c);

            printf("Enter Matrix A:\n");
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    scanf("%d", &a[i][j]);

            printf("Enter Matrix B:\n");
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    scanf("%d", &b[i][j]);

            matrixAddition(a, b, r, c);
            break;

        case 2:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r, &c);

            printf("Enter Matrix:\n");
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    scanf("%d", &a[i][j]);

            saddlePoint(a, r, c);
            break;

        case 3: {
            int m[2][2];
            printf("Enter 2x2 Matrix:\n");
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    scanf("%d", &m[i][j]);

            inverse2x2(m);
            break;
        }

        case 4: {
            int m[3][3];
            printf("Enter 3x3 Matrix:\n");
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    scanf("%d", &m[i][j]);

            magicSquareCheck(m);
            break;
        }

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
