#include <iostream> 
#include <fstream> 
#include <ctime> 
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// Read matrices A and B from hard drive then compute C

int main()
{
    	int N=0;
	clock_t start, end;
	start=clock();
	string temp_str;
	ifstream input_fileA("A_values");
	ifstream input_fileB("B_values");
	
	while(!input_fileA.eof())
	{
		getline(input_fileA,temp_str);
		N++;
	}
	N= int(sqrt(N-1));

	input_fileA.close();
	// Cpp gets weird with opening same file twice
	ifstream input_fileA2("A_values");

	double** A=new double*[N];
	double** B=new double*[N];
	double** C=new double*[N];

	for (int i=0; i < N; i++)
	{
	    	A[i]=new double[N];
		B[i]=new double[N];
		C[i]=new double[N];
	}

	for (int i=0; i < N; i++)
	{
		for (int j=0; j < N; j++)
		{
		    	input_fileA2 >> A[i][j]; 
			input_fileB >> B[i][j];
		}
	}

	input_fileA2.close();
	input_fileB.close();

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
	double time=double(end-start)/double(CLOCKS_PER_SEC);
	cout << setprecision(8) <<  "C(N/2,N/2) = " <<  C[N/2-1][N/2-1] << endl;
	cout << setprecision(8) << "C(N,N) = " << C[N-1][N-1] << endl;
	cout << "The time taken to read A/B for N=" << N << " and compute C is " << time << endl;

	for (int i=0; i < N; i++)
	{
	    	delete[] A[i];
		delete[] B[i];
		delete[] C[i];
	}
	delete[] A;
	delete[] B;
	delete[] C;

	return 0;
}	


