#include <iostream> 
#include <fstream> 
#include "matrix_Ap6.h"
#include "matrix_Bp6.h"
#include <ctime>
#include <iomanip> 
#include "matrix_Cp6.h"
#include <string>

using namespace std;

// Writes N/2 by N/2 block of C to the harddrive
// ii goes from 1-4, clockwis

int main()
{
    	int N, ii;
	clock_t start_comp, end_comp, start_write, end_write;
	cout << "Enter value of N: " << endl;
	cin >> N;
	cout << "Enter value of i: " << endl;
	cin >> ii;
	string filename;

	start_comp=clock();
	double** C=matrix_C_P6(N,ii);
	end_comp=clock();
	start_write=clock();

	if (ii==1)
	{
		 filename="C1_values";
	}

	else if(ii==2)
	{
		filename="C2_values";
	}

	else if(ii==3)
	{
		filename="C3_values";
	}

	else 
	{
		filename="C4_values";
	}

	ofstream output_C(filename);

	for (int i=0; i < N/2; i++)
	{
		for (int j=0; j < N/2; j++)
		{
			output_C << setprecision(15) << C[i][j] << endl;
		}
	}
	
	output_C.close();
	end_write=clock();
	double time_comp=double(end_comp-start_comp)/double(CLOCKS_PER_SEC);
	double time_write=double(end_write-start_write)/double(CLOCKS_PER_SEC);
	cout << "The time taken to compute C for N=" << N << " and i=" << ii <<
	    " is " << time_comp << " seconds" << endl;
	cout << "The time taken to write C for N=" << N << " and i=" << ii << 
	    " is " << time_write << " seconds" << endl;

	return 0;
}
