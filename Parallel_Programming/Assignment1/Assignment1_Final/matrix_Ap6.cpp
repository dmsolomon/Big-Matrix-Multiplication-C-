#include <iostream>
#include <iomanip>

using namespace std;

// Function to build block  of matrix A with elements 1/(i+j-1)
// Size is N/2 by N/2 ie) A is partitioned into 4 matrices denoted
// 1-4 clockwise. I did this before matrix B and implemented better
// method for matrix B. 

double** matrix_A_P6(int N, int ii)
{
    	double** A = new double*[N/2];

	if (ii==1)
	{
		for (int  i=1; i<=N/2; i++)
		{
			A[i-1]=new double[N/2];
			for(int j=1; j<=N/2; j++)
			{
				A[i-1][j-1]= 1/double((i+j-1));
			}
		}
	}

	else if (ii==2 | ii==3)
	{
		for (int  i=1; i<=N/2; i++)
		{
			A[i-1]=new double[N/2];
			for(int j=1; j<=N/2; j++)
			{
				A[i-1][j-1]= 1/double((i+j+N/2-1));
			}
		}
	}

	else 
	{
		for (int  i=1; i<=N/2; i++)
		{
			A[i-1]=new double[N/2];
			for(int j=1; j<=N/2; j++)
			{
				A[i-1][j-1]= 1/double((i+j+N/2-1));
			}
		}
	}

	 return A;
}




