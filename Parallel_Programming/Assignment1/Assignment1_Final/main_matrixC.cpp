#include <iostream> 
#include <cmath> 
#include "matrix_A.h"
#include "matrix_B.h"
#include <ctime>
#include <iomanip>

using namespace std;
// Builds matrix C of size N by N, product of A and B
// See write up for math details
int main()
{
    	int N;
	clock_t start, end;
	cout << "Enter value of N: " << endl;
	cin >>  N;
	
	start=clock();
	double** B=matrix_B(N);
	double** A=matrix_A(N);
	double** C=new double*[N];
	   
	for (int i=0; i < N; i++)
	{
		C[i]=new double[N];
	}

	for (int i=0; i < N; i++)
	{
		for (int j=0; j < N; j++)
		{
		    	C[i][j]=0;	
			for (int k=0; k < N; k++)
			{
				C[i][j] += A[i][k] * B[k][j];	
			}
		}
	}

	end=clock();
	double time= double(end-start)/double(CLOCKS_PER_SEC);
	cout << "The matrix C for N=" << N << " was computed in " << time << " seconds" << endl;
	cout << setprecision(8) <<  "C(N/2,N/2) = " <<  C[N/2-1][N/2-1] << endl;
	cout << setprecision(8) << "C(N,N) = " << C[N-1][N-1] << endl;

	for (int i=0; i < N; i++)
	{
		delete[] C[i];
	}
	delete[] C;
	
	return 0;
}
