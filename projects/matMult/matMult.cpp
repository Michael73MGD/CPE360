#include <iostream>
#include <assert.h>
#include <stdlib.h>

#ifndef __TIME_H__
#define __TIME_H__

#include <sys/time.h>
#include <stdlib.h>

double wtime()
{
	double time[2];
	struct timeval time1;
	gettimeofday(&time1, NULL);

	time[0]=time1.tv_sec;
	time[1]=time1.tv_usec;

	return time[0]+time[1]*1.0e-6;
}

#endif

int mat_mult_mat (int **A, int **B, int **res, int dim)
{
    int temp=0;
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            for(int k=0;k<dim;k++){
                temp+=A[i][k]*B[j][k];

            }
            res[i][j]=temp;
            std::cout<<res[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    return 1;
}


int main(int args, char **argv)
{
    std::cout<<"Input: /path/to/exe dim\n";

    assert(args == 2);

    int dim = atoi(argv[1]);
    
    int **A = new int*[dim];
    for(int i = 0; i < dim; i ++)
        A[i] = new int[dim];
        
    int **res = new int*[dim];
    for(int i = 0; i < dim; i ++)
        res[i] = new int[dim];
    
    int **B = new int*[dim];
    for(int i = 0; i < dim; i ++)
        B[i] = new int[dim];
    
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++){
            A[i][j]=rand() % 10;
            B[i][j]=rand() % 10;
            
            //std::cout<<B[i][j]<<"\n";
        }
    }

    

    double time = wtime();
    mat_mult_mat (A, B, res, dim);
    
    time = wtime () - time;

    std::cout<<"It takes " << time <<" seconds to finish the "<<dim<<" by "<<dim<< " matrix multiplication\n";

    return 1;

}