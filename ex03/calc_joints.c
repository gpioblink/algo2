/*

author : s1260250
id     : Yamada Kai

*/

/*
関節点の計算

参考: http://www.dais.is.tohoku.ac.jp/~shioura/teaching/ad09/ad09-13.pdf

深さ優先探索を使って全ての関節点をO(m+n)時間で求める方法を説明する

num[u]：頂点 u が何番目に走査されたかを表す数字
lowpt[u] ＝ min{num[v] | v=u, もしくは 頂点uの子孫wに対し，Tに含まれない枝(v,w)が存在}

定理：
u は関節点ならば、uの子供vが存在して次の条件を満たす
(i) lowpt[v]≧num[u]
(ii)uが根のとき，子供の数が２以上

*/

#include <stdio.h>
#include <stdlib.h>

void DFS(int, int);

int n;         // number of vertex ( 'V' of graph G(V,E) )
int label = 0; // the order of vertex visiting
int *visited;  // if vertex_i was visited?
int **A;       // Adjacency matrix

int *lowpt;

int main() {
    int start;
    int i, j;
    /* input number of vertex */
    printf("Input the number of data: ");
    scanf("%d", &n);

    /* memory allocation and initialization */
    visited = (int *)malloc(sizeof(int) * n);
    A = (int **)malloc(sizeof(int *) * n);
    lowpt = (int *)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++) {
        A[i] = (int *)malloc(sizeof(int) * n);
        visited[i] = 0;
        lowpt[i] = 0;
    }

    printf("Input the Adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Input the initial node: 1 to %d\n", n);
    scanf("%d", &start);

    printf("The edges in the DFS tree with root %d are:\n", start);
    DFS(start - 1, -1);

    for(i = 0; i < n; i++) printf("lowpt[%d]=%d\n", i+1, lowpt[i]);

    /* find lowpt */
    for(i = 0; i < n; i++) {
        int flag = 0; // 条件iを確認
        int count = 0; // 条件iiを確認
        for(int t = 0; t < n; t++) {
            if(A[i][t] != 0) {
                ++count;
                if(lowpt[t] >= visited[i]) {
                    flag = 1;
                }
            }
        }
        if(flag != 0 && count >= 2) {
            printf("%d is arc\n", i+1);
        }
    }

    /* memory free */
    for(i = 0; i < n; i++)
        free(A[i]);
    free(A);
    free(visited);

    return 0;
}

void DFS(int node, int preNode) {
    int t;
    printf("current node: %d\n", node+1);
    visited[node] = lowpt[node] = ++label;

    for(t = 0; t < n; t++) {
        if(A[node][t] != 0 && visited[t] == 0) {
            printf("(%d,%d)\n", node + 1, t + 1);
            DFS(t, node); // Recursive call
            if(lowpt[node] > lowpt[t]) {
                lowpt[node] = lowpt[t];
            }
        } else if(t != preNode && lowpt[node] > visited[t]) {
            lowpt[node] = visited[t];
        }
    }
}
