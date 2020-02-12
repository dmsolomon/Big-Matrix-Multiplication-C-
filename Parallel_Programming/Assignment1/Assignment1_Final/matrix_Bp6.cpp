#include <iostream> 
#include <cmath>
#include <iomanip> 
#include "trig_ratio.h"
#include "binomial.h"
#include <ctime>

using namespace std;
// Builds N/2 by N/2 block of matrix B. 

double** matrix_B_P6(int N, int ii)
{	
	double** B= new double*[N/2];
	int count=0;
	int i_new, j_new;
	
	if (ii ==1)
	{
		 i_new=0;
	   	 j_new=0;
	}

	else if (ii==2)
	{
		 i_new=0;
       		 j_new=N/2;
	}

	else if (ii==3)
	{
		 i_new=N/2;
		 j_new=0;
	}

	else 
	{
		 i_new=N/2;
		 j_new=N/2;
	}

	for (int  i=1; i<=N/2; i++)
	{
		B[i-1]=new double[N/2];
		for(int j=1; j<=N/2; j++)
		{
			B[i-1][j-1]= pow(-1,i+j+i_new+j_new) * (i+j+i_new+j_new-1) * 
			    binomial(N+i+i_new-1, N-j-j_new) * binomial(N+j+j_new-1, N-i-i_new) *
			   pow( binomial(i+j+i_new+j_new-2, i+i_new-1), 2);

			if ( abs(B[i-1][j-1]) > pow(10,100) )
			{
				 B[i-1][j-1]= pow(-1, i+j+i_new+j_new) * pow((i+j+i_new+j_new-1),2)*
				     pow(trig_ratio(N+i+i_new-1,N-j-j_new),3)*
				     pow(trig_ratio(N+j+j_new-1,N-i-i_new),4)*
				     pow(trig_ratio(i+j+i_new+j_new-2,i+i_new-1),5);
				 count += 1;
			}
		}
	}
	return B;
}

