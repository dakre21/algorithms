#include <iostream>
#include <math.h>
#include <bits/stdc++.h> 

#define N 4 

using namespace std; 
  
  
void rotateMatrix(int mat[N][N]) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int tmp = mat[i][j];
            mat[i][j] = mat[N - j - 1][i];
            mat[N - j - 1][i] = mat[N - i - 1][N - j - 1];
            mat[N - i - 1][N - j - 1] = mat[j][N - i - 1];
            mat[j][N - i - 1] = tmp;
        }
    }
}

void displayMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    int one[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Original Matrix" << endl;
    displayMatrix(one);
    rotateMatrix(one);

    cout << "Rotated Matrix 90 degrees CW" << endl;
    displayMatrix(one);

    return 0;
}
