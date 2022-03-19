#include <stdio.h>

int findBombs(int row, int cols, int matrix[row][cols]) {
    int count = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < cols; ++j) {
            // kontrola prvku NAD
            if (i > 0 && matrix[i - 1][j] < matrix[i][j])
                continue;

            // kotrola prvku POD
            if (i < row - 1 && matrix[i + 1][j] < matrix[i][j])
                continue;

            // kotrola prvku VLEVO
            if (j > 0 && matrix[i][j - 1] < matrix[i][j])
                continue;

            // kotrola prvku VPRAVO
            if (j < cols - 1 && matrix[i][j + 1] < matrix[i][j])
                continue;


            ++count;
        }
    }
    return count;
}

int main() {
    int matrix[4][4] = {
            {1, 2, 3, 4},
            {4, 7, 3, 1},
            {2, 3, 1, 3},
            {4, 2, 3, 1}
    };

    int bombCount = findBombs(4, 4, matrix);
    printf("%d\n", bombCount);
    return 0;
}
