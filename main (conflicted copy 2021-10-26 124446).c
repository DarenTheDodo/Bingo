#include <stdio.h>

void print_array(int **num, int row, int col){
    int i, j;

    int *ptr = &num[0][0];
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", *(ptr + i * col + j));
        }
        printf("\n");
    }
}
int main() {
    int row = 5;
    int col = 5;
    int num[5][5] = {
            {1,  2,  3,  4,  5},
            {6,  7,  8,  9,  10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
    };
    print_array(&num, row, col);

    return 0;
}
