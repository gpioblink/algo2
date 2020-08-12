/*

author : Kai Yamada
id     : s1260250

*/


#include <stdio.h>
#include <stdlib.h>

#define INFTY 99999

int Floyd(int, int, int);

int main() {
    int i, j, k;

    int **Data, n;
    int **d;

    /* input data (size) */
    printf("Input the number of data: ");
    scanf("%d", &n);

    /* Generate arrays (memory allocation)*/
    Data = (int **)malloc(n * sizeof(int *));
    d = (int **)malloc(n * sizeof(int *));

    for(i = 0; i < n; i++) {
        Data[i] = (int *)malloc(n * sizeof(int));
        d[i] = (int *)malloc(n * sizeof(int));
    }

    // 初期化
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            d[i][j] = INFTY;
        }
    }
    /* input data (matrix)*/
    printf("Input the Adjacency or Distance matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &Data[i][j]);
        }
    }

    /* Main routines */
    /* [ Complete Here!! ( 3-level nested loop) ] */
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                /* Call main routines */
                Data[i][j] = Floyd(Data[i][j], Data[i][k], Data[k][j]); // Floyd's Algorithm
            }
        }
    }
    // end 3-level nested loop

    int mini, minj, maxi, maxj;
    int minv = 99999, maxv = -1; 
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            // printf("%8d", Data[i][j]);
            if(minv > Data[i][j]) {
                minv = Data[i][j];
                mini = i;
                minj = j;
            }
            if(maxv < Data[i][j]) {
                maxv = Data[i][j];
                maxi = i;
                maxj = j;
            }
        }
    }
    printf("min[%d][%d]=%d max[%d][%d]=%d\n", mini, minj, minv, maxi, maxj, maxv);
    /* free allocated memory*/
    for(i = 0; i < n; i++) {
        free(Data[i]);
        free(d[i]);
    }
    free(Data);
    free(d);

    return 0;
}

int Floyd(int D_ij, int D_ik, int D_kj) {
    /* Arguments D_ij, D_ik, D_kj means D^{k-1}[i][j], D^{k-1}[i][k],D^{k-1}[k][j] at the pseudo code. */
    int Dk_ij; /* D^k[i][j] */

    Dk_ij = (D_ij > D_ik + D_kj)? D_ik + D_kj: D_ij;

    return Dk_ij;
}
