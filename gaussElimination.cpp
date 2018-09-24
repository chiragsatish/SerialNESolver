#include<iostream>
#include<cmath>
#include<chrono>
#include "GaussElimination.h"
using namespace std;

 void GaussElimination(float* xxt, float *xty, int n,int lda, int ldb){
        double Augmat[n][n+1];
        double XVec[n];
        int i,j,k;      
        clock_t start_t, middle_t, end_t, first_t, second_t, total_t; 
        auto start = chrono::high_resolution_clock::now();
        for(i=0;i<n;i++){
                for(j=0;j<n+1;j++){
                        if(j==n)
                            Augmat[i][j]=*(xty+i*lda);
                        else
                            Augmat[i][j]=*(xxt+i*lda+j);
                }
        }
	/*cout<<"AUGMAT\n";
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++)
			cout<<Augmat[i][j]<<" ";
		cout<<"\n";
	}*/
        for (i=0; i<n; i++) {
        // Search for maximum in this column
            double maxelement = abs(Augmat[i][i]);
            int maxRow = i;
            for (k=i+1; k<n; k++) {
                if (abs(Augmat[k][i]) > maxelement) {
                    maxelement = abs(Augmat[k][i]);
                    maxRow = k;
                }
        }
        // Swap maximum row with current row (column by column)
        for (k=i; k<n+1;k++) {
            double tmp = Augmat[maxRow][k];
            Augmat[maxRow][k] = Augmat[i][k];
            Augmat[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (k=i+1; k<n; k++) {
            double c = -Augmat[k][i]/Augmat [i][i];
            for (j=i; j<n+1; j++) {
                if (i==j) {
                    Augmat[k][j] = 0;
                } else {
                    Augmat[k][j] += c * Augmat[i][j];
                }
            }
        }    
    }
    auto backfillstart = chrono::high_resolution_clock::now();
    for (i=n-1; i>=0; i--) {
        XVec[i] = Augmat[i][n]/Augmat[i][i];
        for (k=i-1;k>=0; k--) {
            Augmat[k][n] -= Augmat[k][i] * XVec[i];
        }
    }
    auto backfillend = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start);
    auto backfillduration = chrono::duration_cast<chrono::nanoseconds>(backfillend-backfillstart);
    cout<<"Time taken:"<<duration.count()<<"ns"<<"\n";
    cout<<"Backfill duration:"<<backfillduration.count()<<"ns"<<"\n";
    for (i=0;i<n;i++)
        cout<<"x"<<i<<" = "<<XVec[i]<<endl;
}
