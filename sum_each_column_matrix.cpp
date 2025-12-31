#include <iostream>
#include <iomanip> // For setw formatting
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

/*
 * Algorithm Challenge & Problem Solving
 * Level 3 – Challenge #4
 * Sum of Each Column in a 3x3 Matrix
 *
 * This program fills a 3x3 matrix with random numbers, prints the matrix, and calculates the sum of each column.
 *
 * Key concepts reinforced:
 * - Column-wise traversal of a 2D array
 * - Separation of computation from output
 * - Using functions for modularity
 * - Strengthening algorithmic thinking for structured data
 */

using namespace std;

// Generate a random number between From and To (inclusive)
int RandNumb(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Fill 3x3 matrix with random numbers
void FillMatrixRandom(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandNumb(1, 99);
        }
    }
}

// Print 3x3 matrix
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Calculate sum of a specific column
int SumColumn(int arr[3][3], short Rows, short ColIndex)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        Sum += arr[i][ColIndex];
    }
    return Sum;
}

// Print sum of each column
void PrintSumColumns(int arr[3][3], short Rows, short Cols)
{
    cout << "\nThe following are the sum of each column:\n";
    for (short i = 0; i < Cols; i++)
    {
        cout << "Column " << i + 1 << " Sum = "
             << setw(3) << SumColumn(arr, Rows, i) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixRandom(arr, 3, 3);
    cout << "The following is a 3x3 Random Matrix:\n\n";
    PrintMatrix(arr, 3, 3);

    PrintSumColumns(arr, 3, 3);

    return 0;
}
