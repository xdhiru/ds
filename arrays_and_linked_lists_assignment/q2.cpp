#include <iostream>
using namespace std;

void southEastNorthTraversal(int** matrix, int rows, int cols) {
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row < rows; ++row) {
            cout << matrix[row][col] << " ";
        }

        ++col;

        if (col < cols) {
            for (int row = rows - 1; row >= 0; --row) {
                cout << matrix[row][col] << " ";
            }
        }
    }
}

void spiralTraversal(int** matrix, int rows, int cols) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        for (int col = left; col <= right; ++col) {
            cout << matrix[top][col] << " ";
        }
        ++top;

        for (int row = top; row <= bottom; ++row) {
            cout << matrix[row][right] << " ";
        }
        --right;

        if (top <= bottom) {
            for (int col = right; col >= left; --col) {
                cout << matrix[bottom][col] << " ";
            }
            --bottom;
        }

        if (left <= right) {
            for (int row = bottom; row >= top; --row) {
                cout << matrix[row][left] << " ";
            }
            ++left;
        }
    }
}

int main() {
    int rows = 3;
    int cols = 3;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    int count = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = count++;
        }
    }

    cout << "South-East-North Traversal: ";
    southEastNorthTraversal(matrix, rows, cols);
    cout << endl;

    cout << "Spiral Traversal: ";
    spiralTraversal(matrix, rows, cols);
    cout << endl;

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
