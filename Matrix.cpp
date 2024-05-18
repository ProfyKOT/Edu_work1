#include <iostream>

using namespace std;

class Matrix {
    public:
        int** getMatrix() {
            return matrixElements;
        }
        int getMatrixSize() {
            return matrixCount;
        }

        Matrix(int** inputArray,int count) {
            matrixCount = count;

            matrixElements = new int* [3];

            for (int i = 0; i < matrixCount; i++) {
                matrixElements[i] = new int[matrixCount];
            }
            tempMatrixElements = new int* [3];

            for (int i = 0; i < matrixCount; i++) {
                tempMatrixElements[i] = new int[matrixCount];
            }
            for (int i = 0; i < matrixCount; i++)
            {
                for (int j = 0; j < matrixCount; j++)
                {
                    matrixElements[i][j] = inputArray[i][j];
                }
            }

        }
        Matrix operator + (Matrix otherMatrix)
        {
            for (int i = 0; i < matrixCount; i++)
            {
                for (int j = 0; j < matrixCount; j++)
                {
                    tempMatrixElements[i][j] = matrixElements[i][j] + otherMatrix.getMatrix()[i][j];
                }
            }
            return Matrix{ tempMatrixElements,matrixCount };
        }
        Matrix operator += (Matrix otherMatrix)
        {
            for (int i = 0; i < matrixCount; i++)
            {
                for (int j = 0; j < matrixCount; j++)
                {
                    matrixElements[i][j] = matrixElements[i][j] + otherMatrix.getMatrix()[i][j];
                }
            }
            return Matrix{ matrixElements,matrixCount };
        }
        Matrix operator - (Matrix otherMatrix)
        {
            for (int i = 0; i < matrixCount; i++)
            {
                for (int j = 0; j < matrixCount; j++)
                {
                    tempMatrixElements[i][j] = matrixElements[i][j] - otherMatrix.getMatrix()[i][j];
                }
            }
            return Matrix{ tempMatrixElements,matrixCount };
        }
        Matrix operator -= (Matrix otherMatrix)
        {
            for (int i = 0; i < matrixCount; i++)
            {
                for (int j = 0; j < matrixCount; j++)
                {
                    matrixElements[i][j] = matrixElements[i][j] - otherMatrix.getMatrix()[i][j];
                }
            }
            return Matrix{ matrixElements,matrixCount };
        }
    private:
        int** matrixElements;
        int** tempMatrixElements;
        int matrixCount;
};

istream& operator >> (istream& input, Matrix &otherMatrix) //Ввод
{
    for (int i = 0; i < otherMatrix.getMatrixSize(); i++) {
        for (int j = 0; j < otherMatrix.getMatrixSize(); j++) {
            input >> otherMatrix.getMatrix()[i][j];
        }
    }
    return input;
}
ostream& operator << (ostream& out, Matrix otherMatrix) //Вывод
{
    for (int i = 0; i < otherMatrix.getMatrixSize(); i++) {
        for (int j = 0; j < otherMatrix.getMatrixSize(); j++) {
            out << otherMatrix.getMatrix()[i][j] << "\t";
        }
        out << "\n";
    }
    return out;
}
