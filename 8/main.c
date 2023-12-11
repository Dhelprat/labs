#include <stdio.h>
#include <limits.h>

int main() {
    FILE *file = fopen("C:\\untitled\\input.txt", "r");

    int n;
    fscanf(file, "%d", &n);

    int matrix[n][n];
    int mn = INT_MAX;
    int mx = INT_MIN;
    int count_mx = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fscanf(file, "%d", &matrix[i][j]);
            if (matrix[i][j] <= mn) {
                mn = matrix[i][j];
            }
            if (matrix[i][j] >= mx) {
                mx = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == mx) {
                count_mx ++;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == mn) {
                matrix[i][j] = count_mx;
            }
            printf("% 5d", matrix[i][j]);
        }
        printf("\n");
    }

    fclose(file);

}