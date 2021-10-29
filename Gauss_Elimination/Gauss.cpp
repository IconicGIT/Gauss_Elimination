/*


#include <stdio.h>
#include<iostream>
#include "Gauss.h"
using namespace std;


void Print2DArray(int arr[][3], int sizeX, int sizeY)
{
    for (size_t i = 0; i < sizeY; i++)
    {

        for (size_t j = 0; j < sizeX; j++)
        {
            cout << arr[i][j] << ", ";
        }

        cout << endl;
    }
}



int main()
{


    printf("Creating a 2D array2D\n");
    printf("\n");

    Matrix mat;



    int height = 3;
    int width = 3;
    int** my2DArray = mat.create2DArray(height, width);
    printf("Array sized [%i,%i] created.\n\n", height, width);

    // print contents of the array2D
    printf("Array contents: \n");

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            printf("%i,", my2DArray[h][w]);
        }
        printf("\n");
    }

    // important: clean up memory
    printf("\n");
    printf("Cleaning up memory...\n");
    for (int h = 0; h < height; h++) // loop variable wasn't declared
    {
        delete[] my2DArray[h];
    }
    delete[] my2DArray;
    my2DArray = 0;
    printf("Ready.\n");

    int mat1[3][3] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };



    Print2DArray(mat1, 3, 3);







    return 0;
}
*/

//Gauss Elimination Method C++ code
//wikkihut.com

#include<iostream>
#include<iomanip>
#include<cmath>
#define N 3
using namespace std;

int main()
{
	float Matrix[N][N + 1], x[N];
	// Matrix = Augumented Matrix [Ad]
	float temp, s;

	//variables for loops
	int i, //n. columns
		j, //n. rows
		k;

	//Scan values of Matrix.

	cout << "Enter Elements of " << N << " Rows & " << N + 1 << " Columns\n";
	cout << fixed;

	for (i = 0; i < N; i++)
	{
		cout << "\tEnter Row  " << i + 1 << " & Press Enter\n";
		for (j = 0; j < N + 1; j++)
			cin >> Matrix[i][j];
	}

	//make above matrix upper triangular Matrix

	int pivot = 0;
	int subpivot = 0;

	


	//for (j = 0; j < N - 1; j++)
	//{
	//	for (i = j + 1; i < N; i++)
	//	{
	//		temp = Matrix[i][j] / Matrix[j][j];
	//
	//		for (k = 0; k < N + 1; k++)
	//			Matrix[i][k] -= Matrix[j][k] * temp;
	//	}
	//}

	//print the Upper Triangular matrix

	cout << "\n ---------------------------------\n";
	cout << "\n Upper Triangular Matrix is:\n";
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N + 1; j++)
			cout << setw(8) << setprecision(4) << Matrix[i][j];
		cout << endl;
	}

	//find values of x,y,z using back substitution

	cout << "\n ---------------------------------\n";

	for (i = N - 1; i >= 0; i--)
	{
		s = 0;
		for (j = i + 1; j < N; j++)
			s += Matrix[i][j] * x[j];
		x[i] = (Matrix[i][N] - s) / Matrix[i][i];
	}

	//print values of x,y,z

	cout << "\n The Solution is:\n";
	for (i = 0; i < N; i++)
		cout << "x[" << setw(3) << i + 1 << "]=" << setw(7) << setprecision(4) << x[i] << endl;


	return 0;
	//wikkihut.com
}