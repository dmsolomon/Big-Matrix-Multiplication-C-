#include <iostream> 
#include <fstream> 
#include <ctime> 
#include <iomanip>
#include <string>
#include <cmath>
#include "matrix_Ap6.h"
#include "matrix_Bp6.h"

using namespace std;

// Use block matrix multiplication to build block of matrix C

double** matrix_C_P6(int N, int ii)
{
	clock_t start, end;
	start=clock();
	double** C= new double*[N/2];

	for (int i=0; i < N; i++)
	{
	    C[i]= new double[N/2];
	}

	// ignore subscripts

		double** A11;
		double** B11;
		double** A12;
		double** B21;

	if (ii==1)
	{
		 A11= matrix_A_P6(N,1);
		 B11= matrix_B_P6(N,1);
		 A12= matrix_A_P6(N,2);
		 B21= matrix_B_P6(N,3);
	}

	else if (ii==2)
	{
		 A11= matrix_A_P6(N,1);
		 B11= matrix_B_P6(N,2);
		 A12= matrix_A_P6(N,2);
		 B21= matrix_B_P6(N,4);
	}

	else if (ii==3)
	{
		 A11= matrix_A_P6(N,3);
	       	 B11= matrix_B_P6(N,1);
	         A12= matrix_A_P6(N,4);
		 B21= matrix_B_P6(N,3);
	}

	else if (ii=4)
	{
		 A11= matrix_A_P6(N,3);
		 B11= matrix_B_P6(N,2);
		 A12= matrix_A_P6(N,4);
		 B21= matrix_B_P6(N,4);
	}
	
	for (int i=0; i < N/2; i++)
	{
		for (int j=0; j < N/2; j++)
		{
		    	C[i][j]=0;	
			for (int k=0; k < N/2; k++)
			{
				C[i][j] += A11[i][k] * B11[k][j] + A12[i][k] * B21[k][j];	
			}
		}
	}
	
	end=clock();
	double time=double(end-start)/double(CLOCKS_PER_SEC);

	return C;
}	


