#include<iostream>
#include<iomanip>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

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
	long* x = new long[matSize * sizeof(long)];
	for (int a = 0; a < matSize; a++)
	{
		x[a] = 0;
	}
		
	long** Mat = new long* [matSize * sizeof(long)];

	for (int a = 0; a < matSize; a++)
	{
		*(Mat + a) = new long[(matSize + 1) * sizeof(long)];
	}

	float range = 0;
	if (autoFill)
	{
		
		cout << "\tEnter the range of numbers [-n to n] to fill the matrix with:" << endl;
		cin >> range;
		cout << endl;

	}

	bool ret = false;

	double executionTime;
	

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
				{
					float n = RandomRange(-range, range);
					Mat[i][j] = n;
				}
					
			}
		}

		cout << "\n Matrix is:\n\n";

		for (i = 0; i < matSize; i++)
		{
			for (j = 0; j < matSize + 1; j++)
				cout << setw(3) << setprecision(4) << Mat[i][j];
			cout << endl;
		}

		//Upper triangulation loops

		int pivot = 0;
		int subpivot = 0;

		i = 0;
		j = 0;
		k = 0;

		//start time stamp
		auto Init = Clock::now();



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
		
		//end time stamp
		auto End = Clock::now();
		
		//total triangulation time
		executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Init).count();

		//print the Upper Triangular matrix

		cout << "\n ---------------------------------\n";
		cout << "\n Upper Triangular Mat is:\n";
		for (i = 0; i < matSize; i++)
		{
			for (j = 0; j < matSize + 1; j++)
				cout << setw(10) << setprecision(4) << Mat[i][j];
			cout << endl;
		}

		//find values of x,y,z using back substitution

		cout << "\n ---------------------------------\n";
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
				delete right;
				break;
			}


		}
	}


	//print values of x,y,z

	cout << "\n The Solution is:\n";
	for (i = 0; i < matSize; i++)
		cout << "x[" << setw(3) << i + 1 << "]=" << setw(7) << setprecision(4) << x[i] << endl;

	//print tirangulation time
	cout << "Triangulation Caltulation time: " << executionTime <<" nanoseconds." << endl;

	//delete heap data
	for (size_t a = 0; a < matSize; a++)
	{
		delete[] Mat[a];
	}

	
}


int main(int argc, char* argv[])
{
	srand(time(0));
	

	int matSize;
	int autoFill = false;
	bool repeat = true;
	while (repeat)
	{
		cout << "\tEnter Dimension of the matrix [n x n]\n";
		cin >> matSize;
		cout << endl;

		cout << "\tDo yo want to fill the matrix automatically? [1 = yes, 0 = no]\n";
		cin >> autoFill;
		cout << endl;

		ForwardThreeLoops(matSize, autoFill);
		cout << "End." << endl;
		cout << endl;
		cout << endl;

		cout << "Do yo want to start again? [1] = yes, [0] = no." << endl;
		cout << endl;

		cin >> repeat;
		cout << endl;
		cout << endl;
	}


	return 0;
}