#include<iostream>
#include<iomanip>
#include<cmath>
#include<stdlib.h>
#include<time.h>

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )



using namespace std;


int RandomRange(int value01, int value02) {

	if (value01 > value02) {

		int i = value01;
		value01 = value02;
		value02 = i;

	}
	return(rand() % (value02 - value01 + 1) + value01);

}

void ForwardThreeLoops(int matSize, bool autoFill)
{
	//int matSize = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	

	// Augmented Matrix = Matrix + results
	//initialize matrix of n size
	float* x = new float[matSize * sizeof(float)];
	for (int a = 0; a < matSize; a++)
	{
		x[a] = 0;
	}
		
	float** Mat = new float* [matSize * sizeof(float)];

	for (int a = 0; a < matSize; a++)
	{
		*(Mat + a) = new float[(matSize + 1) * sizeof(float)];
	}

	int range = 0;
	if (autoFill)
	{
		
		cout << "\tEnter the range of numbers [-n to n] to fill the matrix with:" << endl;
		cin >> range;
		cout << endl;

	}

	bool ret = false;

	float executionTime = 0;
	

	while (!ret)
	{

		for (int a = 0; a < matSize; a++)
		{
			for (int b = 0; b < matSize + 1; b++)
			{
				Mat[a][b] = 0;
			}

		}
		//End mat init



		if (!autoFill)
		{
			//User inputs the matrix elements by rows
			cout << "Enter Elements of " << matSize << " Rows & " << matSize + 1 << " Columns\n";
			cout << fixed;

			for (i = 0; i < matSize; i++)
			{
				cout << "\tEnter Row  " << i + 1 << " & Press Enter\n";
				for (j = 0; j < matSize + 1; j++)
					cin >> Mat[i][j];
			}

		}
		else
		{
			
			cout << endl;
			//inputs are automatic
			for (i = 0; i < matSize; i++)
			{
				for (j = 0; j < matSize + 1; j++)
					Mat[i][j] = RandomRange(-range, range);
			}
		}

		cout << "\n Matrix is:\n\n";

		for (i = 0; i < matSize; i++)
		{
			for (j = 0; j < matSize + 1; j++)
				cout << setw(8) << setprecision(4) << Mat[i][j];
			cout << endl;
		}

		//find values of x,y,z using back substitution

		

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


		double Init = SDL_GetTicks();

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
		}

		double End = SDL_GetTicks();

		executionTime = (End - Init) * 1000.0f;
		

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

			if (Mat[i][i] != 0)
			{

				x[i] = (Mat[i][matSize] - right[i]) / Mat[i][i];
				ret = true;
			}
			else
			{
				//matrix no valid for processing
				cout << "Error: Trying to divide by 0." << endl;
				ret = false;
				break;
			}


		}
	}


	//print values of x,y,z

	cout << "\n The Solution is:\n";
	for (i = 0; i < matSize; i++)
		cout << "x[" << setw(3) << i + 1 << "]=" << setw(7) << setprecision(4) << x[i] << endl;

	cout << "Triangulation Caltulation time: " << executionTime << endl;

	//delete heap data
	for (size_t a = 0; a < matSize; a++)
	{
		delete[] Mat[a];
	}

	
}

void ThreeLoops_5x5()
{

}

void ForwardTwoLoops(const int matSize, bool autoFill)
{
	//int matSize = 0;
	int i = 0;
	int j = 0;
	int k = 0;



	// Augmented Matrix = Matrix + results
	//initialize matrix of n size
	float* x = new float[matSize * sizeof(float)];
	for (int a = 0; a < matSize; a++)
	{
		x[a] = 0;
	}

	float** Mat = new float* [matSize * sizeof(float)];

	for (int a = 0; a < matSize; a++)
	{
		*(Mat + a) = new float[(matSize + 1) * sizeof(float)];
	}

	int range = 0;
	if (autoFill)
	{

		cout << "\tEnter the range of numbers [-n to n] to fill the matrix with:" << endl;
		cin >> range;
		cout << endl;

	}

	bool ret = false;

	while (!ret)
	{

		for (int a = 0; a < matSize; a++)
		{
			for (int b = 0; b < matSize + 1; b++)
			{
				Mat[a][b] = 0;
			}

		}
		//End mat init



		if (!autoFill)
		{
			//User inputs the matrix elements by rows
			cout << "Enter Elements of " << matSize << " Rows & " << matSize + 1 << " Columns\n";
			cout << fixed;

			for (i = 0; i < matSize; i++)
			{
				cout << "\tEnter Row  " << i + 1 << " & Press Enter\n";
				for (j = 0; j < matSize + 1; j++)
					cin >> Mat[i][j];
			}

		}
		else
		{

			cout << endl;
			//inputs are automatic
			for (i = 0; i < matSize; i++)
			{
				for (j = 0; j < matSize + 1; j++)
					Mat[i][j] = RandomRange(-range, range);
			}
		}

		cout << "\n Matrix is:\n\n";

		for (i = 0; i < matSize; i++)
		{
			for (j = 0; j < matSize + 1; j++)
				cout << setw(8) << setprecision(4) << Mat[i][j];
			cout << endl;
		}
	}

}

int main()
{
	//srand(time(NULL));
	SDL_Init(0);
	
	int matSize;
	int autoFill = false;
	cout << "\tEnter Dimension of the matrix [n x n]\n";
	cin >> matSize;
	cout << endl;

	cout << "\tDo yo want to fill the matrix automatically? [1 = yes, 0 = no]\n";
	cin >> autoFill;
	cout << endl;

	ForwardThreeLoops(matSize, autoFill);

	//ForwardTwoLoops


	return 0;
}



// 1 Loop Algorithm

//for i = 1 to n - 1
//A(i + 1:n, i) = A(i + 1:n, i) / A(i, i)
//A(i + 1:n, i + 1 : n) = A(i + 1:n, i + 1 : n) - A(i + 1:n, i) * A(i, i + 1:n)