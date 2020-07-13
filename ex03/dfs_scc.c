/*

author : Kai Yamada
id     : s1260250

*/

#include <stdio.h>
#include <stdlib.h>

void DFS(int, int*);
void reverseA();
void initVariable();
void extractSCC();
int compareVisited();

int n;         // number of vertex ( 'V' of graph G(V,E) )
int label = 0; // the order of vertex visiting
int *visited;  // if vertex_i was visited?
int *visited2;
int *visited3;
int **A;       // Adjacency matrix

int main() {
    int start;
    int i, j;
    /* input number of vertex */
    // printf("Input the number of data: ");
    scanf("%d", &n);

    /* memory allocation and initialization */
    visited = (int *)malloc(sizeof(int) * n);
    visited2 = (int *)malloc(sizeof(int) * n);
    visited3 = (int *)malloc(sizeof(int) * n);
    A = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; i++) {
        A[i] = (int *)malloc(sizeof(int) * n);
        visited[i] = 0;
        visited2[i] = 0;
        visited3[i] = 0;
    }

    // printf("Input the Adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    // printf("Input the initial node: 1 to %d\n", n);
    // scanf("%d", &start);

    // printf("The edges in the DFS tree with root %d are:\n", start);
    // DFS(start - 1);

    extractSCC();

    /* memory free */
    for(i = 0; i < n; i++)
        free(A[i]);
    free(A);
    free(visited);

    return 0;
}

void initVariable() {
    for(int i = 0; i < n; i++) {
        visited2[i] = 0;
    }
}

void extractSCC() {
    int a = 0, count = 0;
    DFS(a, visited); // グラフGをある頂点aからDFSで探索する。(到達した頂点の集合をSとする。)
    reverseA(); // グラフGの辺の向きを全て逆にしたグラフG_rを作る。
    while(a != -1 && count < 10) {
        initVariable();
        printf("Strongly Connected Decomposition (Group %d):\n", 1 + count++);
        DFS(a, visited2);
        a = compareVisited();
    }
}

// 次に行くべきaを返す
int compareVisited() {
    int minReachIndex = -1;
    for(int i=0; i < n; i++) {
        if(visited[i] != 0 && visited2[i] != 0) {
            if(visited3[i] == 0) printf("Vertex. %d\n", i+1);
            visited3[i] = 1;
        }
        if(visited2[i] != 0) visited3[i] = 1;
        if(visited[i] != 0 && visited2[i] == 0) {
            if(visited3[i] == 0 && (minReachIndex == -1 || visited[minReachIndex] > visited[i])) {
                minReachIndex = i;
            }
        }
    }
    return minReachIndex;
}

void reverseA() {
    printf("\n");
    for(int y = 1; y < n; y++) {
        for(int x = 0; x < y; x++) {
            int tmp = A[x][y];
            A[x][y] = A[y][x];
            A[y][x] = tmp;
        }
    }
}

void DFS(int node, int *vismem) {
    int t;
    vismem[node] = ++label;
    for(t = 0; t < n; t++) {
        if(A[node][t] != 0 && vismem[t] == 0) {
            // printf("(%d,%d)\n", node + 1, t + 1);
            DFS(t, vismem); // Recursive call
        }
    }
}
