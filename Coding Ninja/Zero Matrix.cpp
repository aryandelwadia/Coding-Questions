//link
//https://www.naukri.com/code360/problems/zero-matrix_1171153

#include <bits/stdc++.h> 

void markRow(vector<vector<int>> &matrix, int n, int m, int i) {

    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

 

void markCol(vector<vector<int>> &matrix, int n, int m, int j) {

    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

 

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}