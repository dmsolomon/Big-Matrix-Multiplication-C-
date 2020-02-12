#include <iostream> 
#include <fstream> 
#include "matrix_A.h"
#include "matrix_B.h"
#include <ctime>
#include <iomanip> 

using namespace std;

// Write matrix A and B to the hard drive 

int main()
{
    	int N;
	clock_t start, end;
	cout << "Enter value of N: " << endl;
	cin >> N;

	start=clock();
	double** A=matrix_A(N);
	double** B=matrix_B(N);

	ofstream output_A("A_values");
	ofstream output_B("B_values");

	for (int i=0; i < N; i++)
	{
		for (int j=0; j < N; j++)
		{
			output_A << setprecision(15) << A[i][j] << endl;
			output_B << setprecision(15) << B[i][j] << endl;
		}
	}
	
	output_A.close();
	output_B.close();
	end=clock();
	double time=double(end-start)/double(CLOCKS_PER_SEC);
	cout << "The time taken to write A and B for N= "<< N << " is " << time << " seconds" << endl;
	return 0;
}
