#include <iostream>
#include<limits.h>
#include<ctime>

using namespace std;

const int MatrixSize{ 16 };

void CreateMatrix(int(&matrix)[MatrixSize][MatrixSize]);
void PrintMatrix(int(&matrix)[MatrixSize][MatrixSize]);
void FillMaximalIndexes(int(&matrix)[MatrixSize][MatrixSize], int(&maxIndexElements)[MatrixSize]);
void CalculateMultiplicationAfterMaxElementInRow(int(&matrix)[MatrixSize][MatrixSize], int(&maxIndexElements)[MatrixSize], int(&sumOfRows)[MatrixSize]);
void PrintMultiplicationAfterMaxElementInRow(int(&sumOfRows)[MatrixSize]);
bool CheckingRowsForSymmetry(int matrix[][MatrixSize], const int MatrixSize);
int CalculateSumOfBlackMatrixElements(int matrix[][MatrixSize], const int MatrixSize);

int main() {

	return 0;
}

void CreateMatrix(int (&matrix)[MatrixSize][MatrixSize]) {
    for (int i = 0; i < MatrixSize; i++) {
        for (int j = 0; j < MatrixSize; j++) {
            matrix[i][j] = rand() % 19 + (-9);
        }
    }
}

void PrintMatrix(int(&matrix)[MatrixSize][MatrixSize]) {
    for (int i = 0; i < MatrixSize; i++) {
        for (int j = 0; j < MatrixSize; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}