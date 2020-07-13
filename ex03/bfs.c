/*

author : s1260250
id     : Yamada Kai

*/

#include <stdio.h>
#include <stdlib.h>

void BFS(int);

void queue_init(void);
void enqueue(int);
int dequeue(void);
int ifqueue_empty(void);

int n;         // number of vertex ( 'V' of graph G(V,E) )
int label = 0; // the order of vertex visiting
int *visited;  // if vertex_i was visited?
int **A;       // Adjacency matrix

int *Q;         // Queue
int head, tail; // pointer for queue

int main() {
    int start;
    int i, j;

    /* input number of vertex */
    printf("Input the number of data: ");
    scanf("%d", &n);

    /* memory allocation and initialization */
    visited = (int *)malloc(sizeof(int) * n);
    Q = (int *)malloc(sizeof(int) * n);
    A = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; i++) {
        A[i] = (int *)malloc(sizeof(int) * n);
        visited[i] = 0;
    }

    printf("Input the Adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Input the initial node: 1 to %d\n", n);
    scanf("%d", &start);

    queue_init();
    printf("the edges in the BFS tree with root %d are:\n", start);
    BFS(start - 1);

    /* memory free */
    for(i = 0; i < n; i++)
        free(A[i]);
    free(A);
    free(visited);
    free(Q);

    return 0;
}

void BFS(int node) {
    int k, t;

    enqueue(node); //最初のノードは到達済扱い（到達したノードをキューへ入れる）
    while(!ifqueue_empty()) { //キューは空でない限り（＝全ての頂点をまだ探索していないとき）
        k = dequeue();             //到達した頂点をキューから取り出して
        printf("current node: %d\n", k+1);
        visited[k] = ++label;
        for(t = 0; t < n; t++) { //そこから向かえる頂点を探す
            if(A[k][t] != 0 && visited[t] == 0) {
                printf("(%d,%d)\n", k + 1, t + 1);
                enqueue(t); //頂点があったら到達、キューに入れる
                visited[t] = -1;
            }
        }
    }
}

/* Complete Other functions for Queue
   ※キュー⇒先に入っているものから出ていく

   tail：最後に入ってきた要素が入っている場所を示す
   head：先に入っていた要素が入っている場所を示す

   つまり、push（データ追加）するとtailが進み、pop（データを取り出すと）headが進む。

   キューに何のデータも残っていないとき、tailとheadは（？）になる
*/
void queue_init(void) {
    head = 0;
    tail = 0;
}

void enqueue(int node) {
    Q[tail] = node;
    ++tail; //キューにデータを挿入（キューとしての配列の添字管理）
}

int dequeue(void) {
    ++head; //キューからデータを取り出す（キューとしての配列の添字管理）
    return Q[head-1];       //←あるいはここの添え字を変えても良い
}

int ifqueue_empty(void) {
    if(head == tail)
        return 1; //キューが空ならば…（キューとしての配列の添字管理）
    else
        return 0;
}
