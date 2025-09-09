#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 10; // Maximum size of the matrix

// Function to read matrix size from file
int readMatrixSize(ifstream& file) {
    int size;
    if (!(file >> size)) {
        cout << "Error reading matrix size from file." << endl;
        exit(1);
    }
    if (size <= 0 || size > MAX_SIZE) {
        cout << "Invalid matrix size." << endl;
        exit(1);
    }
    return size;
}

// Function to read matrix data from file
void readMatrix(int matrix[][MAX_SIZE], int size, ifstream& file) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (!(file >> matrix[i][j])) {
                cout << "Error reading matrix element from file." << endl;
                exit(1);
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to add two matrices
void addMatrices(int result[][MAX_SIZE], int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int result[][MAX_SIZE], int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to subtract one matrix from another
void subtractMatrices(int result[MAX_SIZE][MAX_SIZE], int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to update an element of the first matrix
void updateElement(int matrix[MAX_SIZE][MAX_SIZE], int size, int row, int col, int newValue) {
    if (row < 0 || row >= size || col < 0 || col >= size) {
        cerr << "Invalid row or column index." << endl;
        return;
    }
    matrix[row][col] = newValue;
}

// Function to find the maximum value in the matrix
int getMaxValue(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// Function to transpose a matrix
void transposeMatrix(int matrix[][MAX_SIZE], int size) {
    int temp;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int size;
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    ifstream inputFile;
    inputFile.open("matrix_input.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    // Read matrix size
    size = readMatrixSize(inputFile);

    // Read first matrix
    readMatrix(matrix1, size, inputFile);

    // Read second matrix
    readMatrix(matrix2, size, inputFile);

    inputFile.close();

    // Print matrices
    cout << "Matrix 1:" << endl;
    printMatrix(matrix1, size);
    cout << "\nMatrix 2:" << endl;
    printMatrix(matrix2, size);

    // Perform matrix addition
    addMatrices(result, matrix1, matrix2, size);
    cout << "\nMatrix Addition:" << endl;
    printMatrix(result, size);

    // Perform matrix multiplication
    multiplyMatrices(result, matrix1, matrix2, size);
    cout << "\nMatrix Multiplication:" << endl;
    printMatrix(result, size);

    // Perform matrix subtraction
    subtractMatrices(result, matrix1, matrix2, size);
    cout << "\nMatrix Subtraction:" << endl;
    printMatrix(result, size);

    // Update an element of the first matrix
    updateElement(matrix1, size, 1, 2, 67); // Update element at row 1, column 1 with value 99
    cout << "\nUpdated Matrix 1:" << endl;
    printMatrix(matrix1, size);

    // Get the max value of the first matrix
    cout << "\nMax Value of Matrix 1: " << getMaxValue(matrix1, size) << endl;

    // Transpose the first matrix
    transposeMatrix(matrix1, size);
    cout << "\nTransposed Matrix 1:" << endl;
    printMatrix(matrix1, size);


    return 0;
}

   
