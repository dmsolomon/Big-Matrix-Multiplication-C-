#include <iostream> 
#include <fstream> 
#include <ctime> 
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

//Read 4 sub blocks and build all of matrix C of size N by N
int main()
{
    	int N=0;
	clock_t start, end;
	start=clock();
	string s;
	ifstream input_filetemp("C1_values");

	while(!input_filetemp.eof())
	{
		getline(input_filetemp,s);
		N++;
	}

	N=2* int(sqrt(N-1));
	cout << N << endl;
	input_filetemp.close();

	ifstream input_fileC1("C1_values");
	ifstream input_fileC2("C2_values");
	ifstream input_fileC3("C3_values");
	ifstream input_fileC4("C4_values");

	double** C=new double*[N];

	for (int i=0; i < N; i++)
	{
		C[i]=new double[N];
	}

	for (int i=0; i < N/2; i++)
	{
		for (int j=0; j < N/2; j++)
		{
		    	input_fileC1 >> C[i][j]; 
			input_fileC2 >> C[i][j+N/2];
			input_fileC3 >> C[i+N/2][j];
			input_fileC4 >> C[i+N/2][j+N/2];
		}
	}

	input_fileC1.close();
	input_fileC2.close();
	input_fileC3.close();
	input_fileC4.close();

	end=clock();
	double time=double(end-start)/double(CLOCKS_PER_SEC);
	cout << setprecision(8) <<  "C(N/2,N/2) = " <<  C[N/2-1][N/2-1] << endl;
	cout << setprecision(8) << "C(N,N) = " << C[N-1][N-1] << endl;
	cout << "The time taken to read and build matrix for N=" << N << " is " << time << " seconds" << endl;

	return 0;
}	


