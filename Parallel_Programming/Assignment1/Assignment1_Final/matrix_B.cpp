#include <iostream> 
#include <cmath>
#include <iomanip> 
#include "trig_ratio.h"
#include "binomial.h"
#include <ctime>

using namespace std;

// Builds matrix B of size N by N, see write up for math details
// Count is number of times second definition is used

double** matrix_B(int N)
{	
	double** B= new double*[N];
	int count=0;

	for (int  i=1; i<=N; i++)
	{
		B[i-1]=new double[N];
		for(int j=1; j<=N; j++)
		{
			B[i-1][j-1]= pow(-1,i+j) * (i+j-1) * 
			    binomial(N+i-1, N-j) * binomial(N+j-1, N-i) *
			   pow( binomial(i+j-2, i-1), 2);

			if ( abs(B[i-1][j-1]) > pow(10,100) )
			{
				 B[i-1][j-1]= pow(-1, i+j) * pow((i+j-1),2)*
				     pow(trig_ratio(N+i-1,N-j),3)*
				     pow(trig_ratio(N+j-1,N-i),4)*
				     pow(trig_ratio(i+j-2,i-1),5);
				 count += 1;
			}
		}
	}
	cout<< "The count for N=" << N << " is " << count << endl;
	return B;
}


