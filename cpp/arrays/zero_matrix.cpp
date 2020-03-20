#include <iostream>
#include <vector>


using namespace std;

void zeroMatrix(vector<vector<int> >& matrix) {
    vector<bool> row_zeros(matrix.size(), false);
    vector<bool> col_zeros(matrix.size(), false);

    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            if (0 == matrix[i][j]) {
                row_zeros[i] = true;
                col_zeros[j] = true;
            }
        }
    }

    for (size_t i = 0; i < row_zeros.size(); i++) {
        if (row_zeros[i]) {
            for (size_t j = 0; j < row_zeros.size(); j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (size_t i = 0; i < col_zeros.size(); i++) {
        if (col_zeros[i]) {
            for (size_t j = 0; j < col_zeros.size(); j++) {
                matrix[j][i] = 0;
            }
        }
    }
}

void displayMatrix(const vector<vector<int> >& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main(int argc, char* argv[]) {
    vector<vector<int> > one{
        { 1, 2, 3, 4},
        { 0, 5, 6, 7},
        { 8, 0, 10, 11},
        { 12, 13, 14, 15}
    };

    cout << "Original matrix" << endl;
    displayMatrix(one);

    zeroMatrix(one);
    cout << "Zero'd matrix" << endl;
    displayMatrix(one);

    return 0;
}
