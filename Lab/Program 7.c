#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a sparse matrix element
struct Element {
    int row;
    int col;
    int value;
};

// Structure to represent a sparse matrix
struct SparseMatrix {
    int numRows;
    int numCols;
    int numElements;
    struct Element* elements;
};

// Function to read a sparse matrix from user input
void readSparseMatrix(struct SparseMatrix* matrix) {
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &matrix->numRows, &matrix->numCols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &matrix->numElements);

    matrix->elements = (struct Element*)malloc(matrix->numElements * sizeof(struct Element));

    printf("Enter the non-zero elements in the format <row> <column> <value>:\n");
    for (int i = 0; i < matrix->numElements; ++i) {
        scanf("%d %d %d", &matrix->elements[i].row, &matrix->elements[i].col, &matrix->elements[i].value);
    }
}

// Function to print a sparse matrix
void printSparseMatrix(struct SparseMatrix matrix) {
    printf("Sparse Matrix:\n");
    printf("Rows: %d, Columns: %d\n", matrix.numRows, matrix.numCols);
    printf("Non-zero Elements:\n");

    for (int i = 0; i < matrix.numElements; ++i) {
        printf("<%d, %d, %d>\n", matrix.elements[i].row, matrix.elements[i].col, matrix.elements[i].value);
    }
}

// Function to search for an element in the sparse matrix
void searchElement(struct SparseMatrix matrix, int targetRow, int targetCol) {
    for (int i = 0; i < matrix.numElements; ++i) {
        if (matrix.elements[i].row == targetRow && matrix.elements[i].col == targetCol) {
            printf("Element found at position <%d, %d, %d>\n", matrix.elements[i].row, matrix.elements[i].col, matrix.elements[i].value);
            return;
        }
    }

    printf("Element not found in the sparse matrix.\n");
}

int main() {
    struct SparseMatrix matrix;
    int targetRow, targetCol;

    // Read sparse matrix from user input
    readSparseMatrix(&matrix);

    // Print sparse matrix
    printSparseMatrix(matrix);

    // Get user input for element search
    printf("Enter the row and column to search for an element: ");
    scanf("%d %d", &targetRow, &targetCol);

    // Search for the element in the sparse matrix
    searchElement(matrix, targetRow, targetCol);

    // Free dynamically allocated memory
    free(matrix.elements);

    return 0;
}
