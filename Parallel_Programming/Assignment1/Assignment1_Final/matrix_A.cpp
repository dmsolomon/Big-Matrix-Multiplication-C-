#include <iostream>
#include <iomanip>

using namespace std;

// Function to build matrix of size N by N with elements 1/(i+j-1)

double** matrix_A(int N)
{
	double** A= new double*[N];

	for (int  i=1; i<=N; i++)
	{
		A[i-1]=new double[N];

		for(int j=1; j<=N; j++)
		{
			A[i-1][j-1]= 1/double((i+j-1));
		}
	}
	return A;
}




