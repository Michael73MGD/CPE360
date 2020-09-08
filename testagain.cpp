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
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            res[i][j]=A[i][0]*B[j][0]+A[i][1]*B[j][1]+A[i][2]*B[j][2];
            //std::cout<<res[i][j]<<"\n";
        }
        std::cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<"\n";
    }
    return 1;
}


int main(int args, char **argv)
{
    std::cout<<"Input: /path/to/exe dim\n";

    assert(args == 2);

    int dim = atoi(argv[1]);

	//int **A;
	//int **B;
	//int **res;

    //Alloc the two dimensional arrays A, B and res;
    int **A = new int*[3];
    for(int i = 0; i < 3; i ++)
        A[i] = new int[3];
        
    int **res = new int*[3];
    for(int i = 0; i < 3; i ++)
        res[i] = new int[3];
    
    int **B = new int*[3];
    for(int i = 0; i < 3; i ++)
        B[i] = new int[3];
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++){
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