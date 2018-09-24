#include<iostream>
#include<iomanip>
#include<cmath>
#include "GaussSiedel.h"
#include<time.h>
#include<chrono>
using namespace std;

int GaussSiedel(float* xxt, float *xty, int n,int lda, int ldb)
{
    cout.precision(4);
    cout.setf(ios::fixed);
    int i,j,k,flag=0,count=0;
    double Augmat[n][n+1];          
    double XVec[n];                
    double res,y;
    float maxit = 2*10000*10000;
    for(i=0;i<n;i++){
            for(j=0;j<n+1;j++){
                    if(j==n)
                        Augmat[i][j]=*(xty+i*lda);
                    else
                        Augmat[i][j]=*(xxt+i*lda+j);
            }
    }
    cout<<"\nEnter the initial values of the variables:\n";
    for (i=0;i<n;i++)
        cin>>XVec[i];
    cout<<"\nEnter the accuracy upto which you want the solution:\n";
    cin>>res;
    clock_t t;
    auto start = chrono::high_resolution_clock::now(); 
    do{                           
        for (i=0;i<n;i++){               
            y=XVec[i];
            XVec[i]=Augmat[i][n];
            for (j=0;j<n;j++){
                if (j!=i)
                XVec[i]=XVec[i]-Augmat[i][j]*XVec[j];
            }
            XVec[i]=XVec[i]/Augmat[i][i];
            if (abs(XVec[i]-y)<=res){           
                flag++;
            }
        }
        count++;   
    }while(flag<n && count<=maxit);//If the values of all the variables don't differ from their previious values with error more than res, stop the loop
    auto stop = chrono::high_resolution_clock::now(); 
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start); 
    cout<<"Time taken:"<<duration.count()<<"ns"<<"\n";
    if(flag<n){
        cout<<"Did not converge\n";
    }
    cout<<"Iterations:"<<count<<"\n";
    for (i=0;i<n;i++)
        cout<<"x"<<i<<" = "<<XVec[i]<<endl; 
    return flag;      
}
