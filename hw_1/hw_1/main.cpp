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
    int matrix[MatrixSize][MatrixSize]{ {100, 100, 100, 1},{100, 100, 1, 1}, {100, 1, 1, 1}, {1, 1, 1, 1} };

    setlocale(LC_ALL, "ru");

    // а

    srand(time(NULL));

    CreateMatrix(matrix);

    PrintMatrix(matrix);
    cout << '\n';

    int maxIndexElementsInRow[MatrixSize] = { 0 };

    FillMaximalIndexes(matrix, maxIndexElementsInRow);

    int multiplicationAfterMaxElementInRow[MatrixSize] = { 0 };

    CalculateMultiplicationAfterMaxElementInRow(matrix, maxIndexElementsInRow, multiplicationAfterMaxElementInRow);

    PrintMultiplicationAfterMaxElementInRow(multiplicationAfterMaxElementInRow);
    cout << '\n';

    // б
    bool rowsAreSymmetrical = CheckingRowsForSymmetry(matrix, MatrixSize);
    if (rowsAreSymmetrical) {
        cout << "Все строки симметричны относительно среднего элемента.";
    }
    else {
        cout << "Cтроки не симметричны относительно среднего элемента.";
    }
    cout << '\n';

    // в
    cout << "Сумма элементов матрицы, выделенных чёрным цветом равна " << CalculateSumOfBlackMatrixElements(matrix, MatrixSize) << ".\n" << endl;

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

void FillMaximalIndexes(int (&matrix)[MatrixSize][MatrixSize], int (&maxIndexElementsInRow)[MatrixSize]) {
    for (int i = 0; i < MatrixSize; i++) {
        int valueMaxElementInRow = INT_MIN;
        int indexMaxElementInRow = 0;
        for (int j = 0; j < MatrixSize; j++) {
            if (matrix[i][j] > valueMaxElementInRow) {
                valueMaxElementInRow = matrix[i][j];
                indexMaxElementInRow = j;
            }
        }
        maxIndexElementsInRow[i] = indexMaxElementInRow;
    }
}

void CalculateMultiplicationAfterMaxElementInRow(int(&matrix)[MatrixSize][MatrixSize], int(&maxIndexElementsInRow)[MatrixSize], int(&multiplicationAfterMaxElementInRow)[MatrixSize]) {
    for (int i = 0; i < MatrixSize; i++) {
        int tempMultiplicationAfterMaxElementInRow = 1;

        for (int j = maxIndexElementsInRow[i]; j < 16; j++) {
            if (j == maxIndexElementsInRow[i]) {
                continue;
            }
            tempMultiplicationAfterMaxElementInRow *= matrix[i][j];
        }
        multiplicationAfterMaxElementInRow[i] = tempMultiplicationAfterMaxElementInRow;
    }
}

void PrintMultiplicationAfterMaxElementInRow(int (&multiplicationAfterMaxElementInRow)[MatrixSize]) {
    for (int i = 0; i < MatrixSize; i++) {
        cout << "Строка номер " << i << ", проиведение чисел после максимального элемента в строке равно " << multiplicationAfterMaxElementInRow[i] << endl;
    } 
}

bool CheckingRowsForSymmetry(int matrix[][MatrixSize], const int MatrixSize) {
	bool rowAreSymmetrical = true;

	for (size_t i = 0; i < MatrixSize / 2; i++) {
		for (size_t j = 0; j < MatrixSize; j++) {
			if (matrix[i][j] != matrix[MatrixSize - 1 - i][j]) {
				rowAreSymmetrical = false;
				break;
			}
		}

		if (!rowAreSymmetrical) {
			break;
		}
	}

	return rowAreSymmetrical;
}

int CalculateSumOfBlackMatrixElements(int matrix[][MatrixSize], const int MatrixSize) {
    int sumOfBlackMatrixElements{};

    for (size_t i = 0; i < MatrixSize; i++) {
        for (size_t j = i; j < MatrixSize; j++) {
            sumOfBlackMatrixElements += matrix[MatrixSize - 1 - i][j];
        }
    }

    return sumOfBlackMatrixElements;
}