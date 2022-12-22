#include <iostream>
using namespace std;

int main()
{
    // sizes for the 2D array
    int rows, columns;
    cout << "rows, cols: ";
    cin >> rows >> columns;

    // pointer the to the pointer of the inner array pointer
    int **table = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        table[i] = new int[columns]; // creating array for every row
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "enter element for table[" << i << "][" << j << "]"; // getting element for every index
            cin >> table[i][j];
        }
        cout << endl;
    }
    //print the 2D dynamic array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << table[i][j] << "   ";
        }
        cout << endl;
    }
    // clearing the dynamic array as we completed our work
    for (int i = 0; i < rows; i++)
    {
        //deleting the inner array first
        delete[] table[i];
    }
    //deleting the outer pointer to the array
    delete[] table;
    table = NULL;
}