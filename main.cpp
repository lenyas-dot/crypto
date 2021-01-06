#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
#define charLen 1000






int main()
{
    //только для английских букв
    srand(time(NULL));
    char* inputStr = new char[charLen];
    cout << "Введите сообщение" << endl;
    cin.getline(inputStr, charLen);
    int lenInput = strlen(inputStr);
    int col;
    cout << "Введите столбцы" << endl;
    cin >> col;
    int row = lenInput / col;
     lenInput % col != 0 ? row += 1 : row;
    char mattrix[row][col];
    int count = 0;
    int k = 1;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
           if (count < lenInput)
           {
               mattrix[i][j] = inputStr[count];
               count++;
           }
           else
           {
                mattrix[i][j] = k + '0';
                k++;
           }
        }
    }
    cout << "Исходное сообщение в виде матрицы:" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << mattrix[i][j];
        }
        cout << endl;
    }

    vector<int> colKey(col);
    for (int i = 0; i < col; ++i)
    {
        colKey[i] = i;
    }
    random_shuffle(colKey.begin(), colKey.end());
    cout << "Ключ для столбцов:" << endl;
    for (int i = 0; i < col; ++i) {
        cout << colKey[i];
    }
    cout << endl << "Ключ для строк:" << endl;
    vector<int> rowKey(row);
    for (int i = 0; i < row; ++i) {
        rowKey[i] = i;
    }
    random_shuffle(rowKey.begin(), rowKey.end());
    for (int i = 0; i < row; ++i) {
        cout << rowKey[i];
    }
    int vectorCount = 0;
    count = 0;
    char newMat[row][col];


#pragma region шифрование
    cout << endl << "Зашифрованная матрица" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            newMat[i][j] = mattrix[i][colKey[count]];
            count++;
        }
        count = 0;
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            mattrix[i][j] = newMat[i][j];
        }
    }

    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            newMat[j][i] = mattrix[rowKey[count]][i];
            count++;
        }
        count = 0;
    }


    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << newMat[i][j];
        }
        cout << endl;
    }
#pragma endregion

#pragma region дешифровка
    cout << endl << "Расшифрованная матрица:";
    count = 0;
    char decryp[row][col];
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            decryp[rowKey[count]][i] = newMat[j][i];
            count++;
        }
        count = 0;
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            newMat[i][j] = decryp[i][j];
        }
    }


    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            decryp[i][colKey[count]] = newMat[i][j];
            count++;
        }
        count = 0;
    }

    cout << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << decryp[i][j];
        }
        cout << endl;
    }


#pragma endregion

    return 0;
}