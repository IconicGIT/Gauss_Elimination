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
	double temp = 0;

	

	// Augmented Matrix = Matrix + results
	//initialize matrix of n size
	double* x = new double[matSize * sizeof(double)];
	for (int a = 0; a < matSize; a++)
	{
		x[a] = 0;
	}
		
	double** Mat = new double* [matSize * sizeof(double)];

	for (int a = 0; a < matSize; a++)
	{
		*(Mat + a) = new double[(matSize + 1) * sizeof(double)];
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
		cout << endl;

		cout << "\n Matrix is:\n\n";

		for (i = 0; i < matSize; i++)
		{
			for (j = 0; j < matSize + 1; j++)
				cout << setw(10) << setprecision(4) << Mat[i][j];
			cout << endl;
		}

		//Upper triangulation loops

		int pivot = 0;
		int subpivot = 0;

		i = 0;
		j = 0;
		k = 0;

		
		//Swap row with highest first element with the first row

		double* tempLine = new double[sizeof(double) * (matSize + 1)];
		bool tempFull = false;

		for (size_t i = 0; i < matSize + 1; i++)
		{
			tempLine[i] = 0;
		}
		int maxPos = 0;

		for (i = 1; i < matSize; ++i)
		{
			// Change < to > if you want to find the smallest element
			if (Mat[0][0] < Mat[i][0])
			{
				for (int a = 0; a < matSize + i; a++)
				{
					tempFull = true;
					tempLine[a] = Mat[0][a];
					maxPos = i;
				}
			}
		}

		if (tempFull)
			for (int a = 0; a < matSize + i; a++)
			{
				Mat[0][a] = Mat[maxPos][a];
				Mat[maxPos][a] = tempLine[a];
			}

		
		
		cout << endl;
		cout << "Swap row with highest first element with the first row:" << endl;
		cout << endl;

		for (i = 0; i < matSize; i++)
		{
			for (j = 0; j < matSize + 1; j++)
				cout << setw(10) << setprecision(4) << Mat[i][j];
			cout << endl;
		}

		float warningPivot = 0.000000001f;
		double pivotTemp = 0;
		cout << endl;

		cout << "		Start triangulation:" << endl;
		cout << endl;

		//start time stamp
		auto Init = Clock::now();
		for (j = 0; j < matSize - 1; j++)
		{
			pivot = (double)Mat[j][j];
			for (i = j + 1; i < matSize; i++)
			{
				if (Mat[j][j] == 0)
				{
					cout << "Error: Trying to divide by 0. Matrix is incompatible or indeterminated." << endl;
					ret = false;
					break;
				}
				
				pivotTemp = (double)Mat[i][j] / (double)Mat[j][j];
				

				cout << "Matrix current state: " << endl;
				for (int a = 0; a < matSize; a++)
				{
					for (int b = 0; b < matSize + 1; b++)
						cout << setw(10) << setprecision(4) << Mat[a][b];
					cout << endl;
				}
				cout << "---------------------" << endl;
				cout << "Matrix element [" << Mat[i][j] << "] at " << i << ", " << j << "." << endl;
				cout << "Current pivot: [" << Mat[j][j] << "] at " << j << ", " << j << "." << endl;
				cout << "Result of element / pivot: " << pivotTemp << endl;
				cout << "Result of element - previous result * pivot: " << Mat[i][j] - Mat[j][j] * pivotTemp << endl;
				cout << "---------------------" << endl;

				cout << endl;

				if (warningPivot > abs(pivotTemp) && pivotTemp != 0)
				{
					cout << endl;
					cout << "pivot division dangerously low: [" << pivotTemp <<"]. Results may be affected." << endl;
					cout << endl;
				}
				
				cout << "		Next Iteration: " << endl;
				cout << endl;
				for (k = 0; k < matSize + 1; k++)
					Mat[i][k] -= Mat[j][k] * pivotTemp;
			}
		}


		////i counts the COLUMNS that must have zeros
		//for (i = 0; i < matSize - 1; i++)
		//{
		//	pivot = Mat[i][i];
		//
		//	//j counts the ROWS that must have zeros
		//	for (j = i + 1; j < matSize; j++)
		//	{
		//		subpivot = Mat[j][i];
		//
		//		//k counts the whole ROW that needs to be multiplied
		//		for (k = i; k < matSize + 1; k++)
		//		{
		//			Mat[j][k] = pivot * Mat[j][k] - subpivot * Mat[i][k];
		//		}
		//	}
		//}
		
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

		cout << "\n =================================\n";


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

		bool indeterminated;
		for (size_t a = 0; a < matSize; a++)
		{
			indeterminated = true;
			for (size_t b = 0; b < matSize + 1; b++)
			{
				double c = abs(Mat[a][b]);
				float d = 0.000001f;

				if (c != 0 && c > d)
				{
					indeterminated = false;
				}


			}
			if (indeterminated) break;

		}

		if (indeterminated)
		{
			cout << "The system is indeterminated!, result may not be correct." << endl;
			cout << endl;
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