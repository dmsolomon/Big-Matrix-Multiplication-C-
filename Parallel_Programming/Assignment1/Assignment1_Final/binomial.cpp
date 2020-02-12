#include <iostream> 
#include <bits/stdc++.h>
using namespace std;


// Function for binomial coefficients 
double  binomial(int  n, int k) 
{
	if (k==0 | k==n)
		return 1;
	
	double num=1;
	
	if (k > n-k)
		k=n-k;

	for (int i=0; i < k; i++)
	{
		num *= double(n-i)/double(i+1);
	}
	return num;
}


