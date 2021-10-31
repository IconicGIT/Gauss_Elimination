#include<iostream>
#include<iomanip>
#include<cmath>
#define N 3
using namespace std;


// Cambiar lo de N

float* ForwardThreeLoops(int i, int j, int k, int pivot, int subpivot, float Matrix[N][N + 1]);
//float* ForwardOneLoop(int n, );
int main()
{

	int matSize = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	cout << "Enter Dimension of the matrix [n x n]\n";
	cin >> matSize;

	// Augmented Matrix = Matrix + results
	float* x = new float[matSize * sizeof(float)];

	float** Mat = new float* [matSize * sizeof(float)];

	for (int a = 0; a < matSize; a++)
	{
		*(Mat + a) = new float[(matSize + 1) * sizeof(float)];
	}


	for (int a = 0; a < matSize; a++)
	{
		for (int b = 0; b < matSize + 1; b++)
		{
			Mat[a][b] = 0;
		}

	}

	//recurrent counting variables




	//User inputs the matrix elements by rows
	cout << "Enter Elements of " << matSize << " Rows & " << matSize + 1 << " Columns\n";
	cout << fixed;

	for (i = 0; i < matSize; i++)
	{
		cout << "\tEnter Row  " << i + 1 << " & Press Enter\n";
		for (j = 0; j < matSize + 1; j++)
			cin >> Mat[i][j];
	}

	//Upper triangulation loops

	int pivot = 0;
	int subpivot = 0;

	i = 0;
	j = 0;
	k = 0;

	// 1 LOOP TRIANGULATION TRYAL

	//for (int i = 1; i < N - 1; i++)
		//	{
		//		Matrix(i + 1:N, i) = Matrix(i + 1:N, i) / Matrix(i, i);
		//		Matrix(i + 1:N, i + 1 : N) = Matrix(i + 1:N, i + 1 : N) - Matrix(i + 1:N, i) * Matrix(i, i + 1:N);
		//	}

	// 3 LOOPS TRIANGULATION

	//i counts the COLUMNS that must have zeros
	for (i = 0; i < matSize - 1; i++)
	{
		pivot = Mat[i][i];

		//j counts the ROWS that must have zeros
		for (j = i + 1; j < matSize; j++)
		{
			subpivot = Mat[j][i];

			//k counts the whole ROW that needs to be multiplied
			for (k = i; k < matSize + 1; k++)
			{
				Mat[j][k] = pivot * Mat[j][k] - subpivot * Mat[i][k];
			}
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
		cout << "\n Upper Triangular Mat is:\n";
		for (i = 0; i < matSize; i++)
		{
			for (j = 0; j < matSize + 1; j++)
				cout << setw(8) << setprecision(4) << Mat[i][j];
			cout << endl;
		}

		//find values of x,y,z using back substitution

		cout << "\n ---------------------------------\n";

		//right = accumulation of Matrix[i][j] * x[j]; (delivery 1 page 10)
		float* right = new float[matSize * sizeof(float)];

		for (int a = 0; a < matSize; a++)
		{
			right[a] = 0;
		}


		for (i = matSize - 1; i >= 0; i--)
		{
			for (j = i + 1; j < matSize; j++)
			{
				right[i] += Mat[i][j] * x[j];
			}
			x[i] = (Mat[i][matSize] - right[i]) / Mat[i][i];


		}

		//print values of x,y,z

		cout << "\n The Solution is:\n";
		for (i = 0; i < matSize; i++)
			cout << "x[" << setw(3) << i + 1 << "]=" << setw(7) << setprecision(4) << x[i] << endl;

		//delete heap data
		for (size_t a = 0; a < matSize; a++)
		{
			delete[] Mat[a];
		}


		return 0;
	}
}



// 1 Loop Algorithm

//for i = 1 to n - 1
//A(i + 1:n, i) = A(i + 1:n, i) / A(i, i)
//A(i + 1:n, i + 1 : n) = A(i + 1:n, i + 1 : n) - A(i + 1:n, i) * A(i, i + 1:n)




//float* ForwardThreeLoops(int i, int j, int k, int pivot, int subpivot, float* Matrix)
//{
//	for (i = 0; i < N - 1; i++)
//	{
//		pivot = *Matrix[i][i];
//		cout << " ";
//		//j counts the ROWS that have zeros
//		for (j = i + 1; j < N; j++)
//		{
//			subpivot = Matrix[j][i];
//			cout << " ";
//			//k counts the whole ROW that needs to be multiplied
//			for (k = i; k < N + 1; k++)
//			{
//				Matrix[j][k] = pivot * Matrix[j][k] - subpivot * Matrix[i][k];
//			}
//		}
//		cout << " ";
//	}
//
//	return Matrix;
//}
//
//float ForwardTwoLoops();

//float* ForwardOneLoop(int n,float* Matrix)
//{

//}

