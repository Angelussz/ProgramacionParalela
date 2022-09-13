#include <iostream>
#include <ctime> 
using namespace std;
 
int main() {
	unsigned t0, t1,t2,t3;
	//MAX = 4, 10, 100, 1000, 10000, 30000
	int max = 50000;
	double **A = new double *[max];
	double *x = new double[max];
	double *y = new double[max];

	for(int i=0;i<max;i++){
		A[i] = new double[max];
	}

	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			A[i][j] = j;
		}
		x[i] = i;
		y[i] = 0;
		
	}
	t0=clock();

	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			y[i] += A[i][j] * x[j]; 
		}
		
	}
	t1 = clock();
	double time1 = (double(t1-t0)/CLOCKS_PER_SEC);

	t2 = clock();
	for (int j = 0; j < max; j++)
	{
		for (int i = 0; i < max; i++)
		{
			y[i] += A[i][j] * x[j]; 
		}
		
	}
	t3 = clock();
	double time2 = (double(t3-t2)/CLOCKS_PER_SEC);

	
/*
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
		cout<<"x:"<<x[i]<<endl;
		cout<<"y:"<<y[i]<<endl;
	}
	
*/
	cout << "Execution Time 1: " << time1 << endl;
	cout << "Execution Time 2: " << time2 << endl;
	for (int i = 0; i < max; i++)
	{
		delete[] A[i];
	}
	delete [] A;
	delete [] x;
	delete [] y;
	
	return 0;


}
