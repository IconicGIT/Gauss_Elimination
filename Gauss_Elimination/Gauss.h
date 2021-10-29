#ifndef __GAUSS_H__
#define __GAUSS_H__

#include <math.h>
#include <iostream>
using namespace std;

class Matrix
{
public:
	Matrix()
	{

	}

	~Matrix() 
    {
        
    };

    int** create2DArray(unsigned height, unsigned width)
    {
        int** array2D = 0;
        array2D = new int* [height];

        for (int h = 0; h < height; h++)
        {
            array2D[h] = new int[width];

            for (int w = 0; w < width; w++)
            {
                // fill in some initial values
                // (filling in zeros would be more logic, but this is just for the example)
                array2D[h][w] = w + width * h;
            }
        }

        return array2D;
    }

private:

    int** arr;

};



#endif // __GAUSS_H__
