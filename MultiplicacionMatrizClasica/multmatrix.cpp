#include <iostream>
#include <ctime> 
using namespace std;
 
int main() {
	unsigned t0, t1;
	//MAX = 4, 10, 100, 1000, 10000
	int max = 5000;
	int **A = new int *[max];
	int **B = new int *[max];
    int **C = new int *[max];
    for(int i=0;i<max;i++){
		A[i] = new int[max];
        B[i] = new int[max];
        C[i] = new int[max];
	}
    
    for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			A[i][j] = j;
            B[i][j] = j;
            C[i][j] = 0;
		}		
	}
    t0=clock();
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            for (int inner = 0; inner < max; inner++) {
                C[i][j] += A[i][inner] * B[inner][j];
            }   
        }
    }
    t1 = clock();
	double time1 = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time 1: " << time1 << endl;
/*
    for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			cout<<"A:"<<A[i][j]<<endl;
            cout<<"B:"<<B[i][j]<<endl;
            cout<<"C:"<<C[i][j]<<endl;
		}
		cout<<endl;
	}
*/
    for (int i = 0; i < max; i++)
	{
		delete[] A[i];
        delete[] B[i];
        delete[] C[i];
	}
	delete [] A;
    delete [] B;
    delete [] C;
    
    return 0;   
}