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
	int n_pivot = 0;

	int subpivot = 0;
	int n_subpivot = 0;
	
	i = 0;
	j = 0;
	k = 0;
	
	//j counts the ROWS that have zeros
	//for (j = i + 1; j < N; j++)
	//{
	//	pivot = Matrix[i][i];
	//	
	//
	//	temp = i;
	//	cout << " ";
	//	//i counts the COLUMNS that have zeros
	//	for (i = 0; i < N - 1; i++)
	//	{
	//		//if (j > 0)
	//		//{
	//		//	subpivot = Matrix[j][j];
	//		//	cout << " ";
	//		//}
	//		//else {
	//		//	subpivot = pivot;
	//		//	cout << " ";
	//		//}
	//
	//		subpivot = Matrix[i + 1][i];
	//		cout << " ";
	//		//k counts the whole ROW that needs to be multiplied
	//		for (k = 0; k < N + 1; k++)
	//		{
	//			
	//		}
	//
	//	}
	//	i = temp + 1;
	//	cout << " ";
	//}


	//i counts the COLUMNS that have zeros
	for (i = 0; i < N - 1; i++)
	{
		pivot = Matrix[i][i];
		cout << " ";
		//j counts the ROWS that have zeros
		for (j = i + 1; j < N; j++)
		{
			subpivot = Matrix[j][i];
			cout << " ";
			//k counts the whole ROW that needs to be multiplied
			for (k = i; k < N + 1; k++)
			{
				Matrix[j][k] = pivot * Matrix[j][k] - subpivot * Matrix[i][k];
			}
		}
		cout << " ";
	}










	//for (i = 0; i < N - 1; i++)
	//{
	//	pivot = Matrix[i][j];
	//	n_pivot = Matrix[i][i];
	//	temp = j;
	//	for (j = i + 1; j < N; j++)
	//	{
	//		subpivot = Matrix[i][j];
	//		n_subpivot = Matrix[j][i];
	//
	//		//Matrix[j][i] = subpivot - n_pivot * subpivot / pivot;
	//		cout << "";
	//	}
	//
	//	j = temp + 1;
	//}





	//ORIGINAL NOT COPY
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

// 1 Loop Algorithm

//for i = 1 to n - 1
//A(i + 1:n, i) = A(i + 1:n, i) / A(i, i)
//A(i + 1:n, i + 1 : n) = A(i + 1:n, i + 1 : n) - A(i + 1:n, i) * A(i, i + 1:n)