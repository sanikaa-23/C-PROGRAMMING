#include <stdio.h>

int main()
{
    int a[3][3], b[3][3], sum[3][3];
    int i, j, n;

    printf("Enter order of matrix (2 or 3): ");
    scanf("%d", &n);

    // INPUT
    printf("Enter first matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter second matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&b[i][j]);

    // ADDITION
    printf("\nAddition:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    // SADDLE POINT
    int min, col, found = 0;

    for(i=0;i<n;i++)
    {
        min = a[i][0];
        col = 0;

        for(j=1;j<n;j++)
        {
            if(a[i][j] < min)
            {
                min = a[i][j];
                col = j;
            }
        }

        for(j=0;j<n;j++)
        {
            if(a[j][col] > min)
                break;
        }

        if(j == n)
        {
            printf("\nSaddle point = %d\n", min);
            found = 1;
        }
    }

    if(found == 0)
        printf("\nNo saddle point\n");

    // INVERSE (ONLY 2x2)
    if(n == 2)
    {
        int det;
        det = a[0][0]*a[1][1] - a[0][1]*a[1][0];

        if(det == 0)
            printf("\nInverse not possible\n");
        else
        {
            printf("\nInverse of matrix:\n");
            printf("%d %d\n", a[1][1], -a[0][1]);
            printf("%d %d\n", -a[1][0], a[0][0]);
        }
    }
    else
    {
        printf("\nInverse only for 2x2 matrix\n");
    }

    // MAGIC SQUARE
    int s = 0, magic = 1;

    for(j=0;j<n;j++)
        s += a[0][j];   // first row sum

    for(i=0;i<n;i++)
    {
        int row = 0, colm = 0;

        for(j=0;j<n;j++)
        {
            row += a[i][j];
            colm += a[j][i];
        }

        if(row != s || colm != s)
            magic = 0;
    }

    int d1 = 0, d2 = 0;
    for(i=0;i<n;i++)
    {
        d1 += a[i][i];
        d2 += a[i][n-i-1];
    }

    if(d1 != s || d2 != s)
        magic = 0;

    if(magic == 1)
        printf("\nMagic Square\n");
    else
        printf("\nNot a Magic Square\n");

    return 0;
}
