#include <stdio.h>

int main()
{
    int a[100][3], b[100][3], c[100][3];
    int x[10][10] = {0}, y[10][10] = {0};
    int rows, cols, n, i, j, k, temp, choice;

    printf("1. Initialize Empty Matrix\n");
    printf("2. Insert Element\n");
    printf("3. Sort Matrix\n");
    printf("4. Add Matrices\n");
    printf("5. Transpose Matrix\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        a[0][0] = 0;
        a[0][1] = 0;
        a[0][2] = 0;

        printf("Empty sparse matrix initialized.\n");
    }

    else if (choice == 2)
    {
        printf("Enter rows and columns: ");
        scanf("%d %d", &rows, &cols);

        a[0][0] = rows;
        a[0][1] = cols;
        a[0][2] = 1;

        printf("Enter row, column and value: ");
        scanf("%d %d %d", &a[1][0], &a[1][1], &a[1][2]);

        printf("Element inserted successfully.\n");
    }

    else if (choice == 3)
    {
        printf("Enter number of non-zero elements: ");
        scanf("%d", &n);

        a[0][0] = 3;
        a[0][1] = 3;
        a[0][2] = n;

        printf("Enter row, column and value:\n");

        for (i = 1; i <= n; i++)
        {
            scanf("%d %d %d",
                  &a[i][0], &a[i][1], &a[i][2]);
        }

        for (i = 1; i < n; i++)
        {
            for (j = 1; j <= n - i; j++)
            {
                if (a[j][0] > a[j + 1][0] ||
                   (a[j][0] == a[j + 1][0] &&
                    a[j][1] > a[j + 1][1]))
                {
                    for (k = 0; k < 3; k++)
                    {
                        temp = a[j][k];
                        a[j][k] = a[j + 1][k];
                        a[j + 1][k] = temp;
                    }
                }
            }
        }

        printf("Sorted sparse matrix:\n");

        for (i = 0; i <= n; i++)
        {
            printf("%d %d %d\n",
                   a[i][0], a[i][1], a[i][2]);
        }
    }

    else if (choice == 4)
    {
        printf("Enter rows and columns: ");
        scanf("%d %d", &rows, &cols);

        printf("Enter number of non-zero elements in A: ");
        scanf("%d", &n);

        printf("Enter row, column and value for A:\n");

        for (i = 0; i < n; i++)
        {
            int r, col, val;
            scanf("%d %d %d", &r, &col, &val);
            x[r][col] = val;
        }

        printf("Enter number of non-zero elements in B: ");
        scanf("%d", &n);

        printf("Enter row, column and value for B:\n");

        for (i = 0; i < n; i++)
        {
            int r, col, val;
            scanf("%d %d %d", &r, &col, &val);
            y[r][col] = val;
        }

        k = 1;

        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                temp = x[i][j] + y[i][j];

                if (temp != 0)
                {
                    c[k][0] = i;
                    c[k][1] = j;
                    c[k][2] = temp;
                    k++;
                }
            }
        }

        c[0][0] = rows;
        c[0][1] = cols;
        c[0][2] = k - 1;

        printf("Added sparse matrix:\n");

        for (i = 0; i < k; i++)
        {
            printf("%d %d %d\n",
                   c[i][0], c[i][1], c[i][2]);
        }
    }

    else if (choice == 5)
    {
        printf("Enter rows, columns and non-zero count: ");
        scanf("%d %d %d", &rows, &cols, &n);

        a[0][0] = rows;
        a[0][1] = cols;
        a[0][2] = n;

        printf("Enter row, column and value:\n");

        for (i = 1; i <= n; i++)
        {
            scanf("%d %d %d",
                  &a[i][0], &a[i][1], &a[i][2]);
        }

        b[0][0] = cols;
        b[0][1] = rows;
        b[0][2] = n;

        for (i = 1; i <= n; i++)
        {
            b[i][0] = a[i][1];
            b[i][1] = a[i][0];
            b[i][2] = a[i][2];
        }

        printf("Transposed sparse matrix:\n");

        for (i = 0; i <= n; i++)
        {
            printf("%d %d %d\n",
                   b[i][0], b[i][1], b[i][2]);
        }
    }

    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}