/*

author : your name
id     : your id

*/


#include <stdio.h>
#include <stdlib.h>
#define INFTY 99999

int Maggs_Plotkin(int, int, int);
void MST_view(int **D0, int **, int);

int main() {
    int i, j, k;
    int **Data, n;

    /* input data (size) */
    printf("Input the number of data: ");
    scanf("%d", &n);
    /* Generate arrays (memory allocation)*/
    Data = (int **)malloc(n * sizeof(int *));

    for(i = 0; i < n; i++) {
        Data[i] = (int *)malloc(n * sizeof(int));
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
    /* Call main routines */
    Data[i][j] = Maggs_Plotkin(Data[i][j], Data[i][k], Data[k][j]);
    // end 3-level nested loop


    /* free allocated memory*/
    for(i = 0; i < n; i++) {
        free(Data[i]);
    }
    free(Data);

    return 0;
}

int Maggs_Plotkin(int D_ij, int D_ik, int D_kj) {
    int Dk_ij;

    Dk_ij = /* [ Complete Here!! ] */;

    return Dk_ij;
}

// D0[][] -> 元の2次元配列。つまり隣接行列A
// dn[][] -> アルゴリズムで処理された2次元配列。つまりA^k
// n -> グラフの頂点数|V|
void MST_view(int **D0, int **dn, int n) {
    int i, j;
    int costs = 0;

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) { // A上で辺があったところが、A^kの全域木に採用されているなら重みを加える
            if(D0[i][j] == dn[i][j] && D0[i][j] != INFTY) {
                costs += dn[i][j];
                printf("%d\n", dn[i][j]);
            }
        }
    }

    printf("MST total weights:%d\n", costs);
}
