#include <iostream>
#include <ctime> 
using namespace std;
 
int main() {
	unsigned t0, t1;
	//MAX = 4, 10,50, 100, 500,700,1000,2000,3000,5000
    int max;
    cout<<"tamanio matriz: ";
	cin>>max;
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

    int smax;
    cout<<"submatrix: ";
    cin>>smax;
    t0=clock();
    for (int ih = 0; ih < max; ih+=smax)
    {
        for (int jh = 0; jh < max; jh+=smax)
        {
            for (int kh = 0; kh < max; kh+=smax)
            {
                for (int il = 0; il < smax; il++)
                {
                    for (int kl = 0; kl < smax; kl++)
                    {
                        for (int jl = 0; jl < smax; jl++)
                        {
                            C[ih+il] += A[ih+il][kh+kl] * B[kh+kl][jh+jl];
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    t1 = clock();
    double time1 = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time 1: " << time1 << endl;
    /*
    for (int i = 0; i < max; i++)
	{
		delete[] A[i];
        delete[] B[i];
        delete[] C[i];
	}
	delete [] A;
    delete [] B;
    delete [] C;
    */
    return 0;
}
