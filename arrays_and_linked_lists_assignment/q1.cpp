// Given a square matrix of size 'n'. Find the saddle price of the given matrix and print the saddle price.The saddle price is defined as the least price in the row but the maximum price in the column of the matrix.
#include <iostream>
using namespace std;

int findSaddlePrice(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        int minInRow = matrix[i][0];
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];
            }
        }
        int minIndex = 0;
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == minInRow) {
                minIndex = j;
                break;
            }
        }
        bool isSaddle = true;
        for (int j = 0; j < n; ++j) {
            if (matrix[j][minIndex] > minInRow) {
                isSaddle = false;
                break;
            }
        }
        if (isSaddle) {
            return minInRow;
        }
    }
    return -1; 
}
int** createMatrix(int n){
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout<<"Enter value at ["<<i <<"]["<<j<<"] :"<<endl;
            cin>>matrix[i][j];
        }
    }
    return matrix;
}
int main() {
    int size;
    cout<<"Enter matrix size:\n";
    cin>>size;
    int** a=createMatrix(size);
    int saddlePrice = findSaddlePrice(a, size);
    if (saddlePrice != -1) {
        cout << "The saddle price is: " << saddlePrice << endl;
    } else {
        cout << "No saddle price found." << endl;
    }
    return 0;
}