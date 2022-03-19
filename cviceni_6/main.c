#include <stdio.h>
#include "math.h"

void ins(int matrix[2][3], int row, int column) {
    int i, j;

    for (i = 0; i < row; ++i) {
        for (j = 0; j < column; ++j) {
            printf("ROW %d  COL %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int count77rows(int matrix[4][4], int row, int column) {
    int i, j, count = 0;

    for (i = 0; i < row; ++i) {
        for (j = 0; j < column; ++j) {
            printf("%d\n", *(*(matrix+i) +j));
            if (*(*(matrix+i) +j) == 77) {
                ++count;
                break;
            }
        }
    }
    return count;
}


int main() {
    // Hlavičkové soubory a makra ==============
    /*
    printf("Použití funkce z hlavičky %d \n", add(4, 2));
    printf("Použití makra z hlavičky %d \n", ADD(2, 3));
    */
    // 2D pole ==============
    /*
    int normalni_pole[4]; // 16B
    int dvou_d_pole[4][5]; // 4ř, 5s = 4 * 5 = 20 * sizeof int = 80B

    int arr[2][3] = {1, 2, 3, 4, 5, 6};
    int arr2[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
    };

    printf("%d\n", arr2[1][1]);
    printf("%d\n", *(*(arr2 + 1) + 1));
    */

    // 2D pole dynamické ==============
    /*
    int row, col;
    printf("Input rows: ");
    scanf("%d", &row);
    printf("Input cols: ");
    scanf("%d", &col);

    int mat[row][col];
    printf("Input data:\n");
    ins(mat, row, col);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    */

    // Search-77


    int row = 4;
    int col = 4;
    int arr3[4][4] = {
            {1, 1, 2, 4},
            {99, 1, 100, 77},
            {2, 2, 77, 100},
            {4, 77, 77, 8}
    };
    printf("77 rows count: %d", count77rows(arr3, 4, 4));


    return 0;
}
