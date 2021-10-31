#include<iostream>
#include<iomanip>
#include<cmath>
#define N 3
using namespace std;

int main()
{
	// Augmented Matrix = Matrix + results
	float Matrix[N][N + 1], x[N] = { 0 };
	
	//recurrent counting variables
	int i = 0;
	int j = 0;
	int k = 0;

	

	//User inputs the matrix elements by rows

	cout << "Enter Elements of " << N << " Rows & " << N + 1 << " Columns\n";
	cout << fixed;

	for (i = 0; i < N; i++)
	{
		cout << "\tEnter Row  " << i + 1 << " & Press Enter\n";
		for (j = 0; j < N + 1; j++)
			cin >> Matrix[i][j];
	}

	//Upper triangulation loops

	int pivot = 0;
	int subpivot = 0;
	
	i = 0;
	j = 0;
	k = 0;
	
	
	// 3 LOOPS TRIANGULATION

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










	





	//ORIGINAL NOT COPY -> not the code we need.
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

	//for (i = N - 1; i >= 0; i--)
	//{
	//	s = 0;
	//	for (j = i + 1; j < N; j++)
	//		s += Matrix[i][j] * x[j];
	//	x[i] = (Matrix[i][N] - s) / Matrix[i][i];
	//}

	int right[N] = { 0 };

	for (i = N - 1; i >= 0; i--)
	{
		for (j = i + 1; j < N; j++)
		{
			right[i] += Matrix[i][j] * x[j];
		}
		x[i] = (Matrix[i][N] - right[i]) / Matrix[i][i];

		
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