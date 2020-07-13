/*

author : your name
id     : your id

*/

#include <stdio.h>
#include <stdlib.h>

void Visit(int);
void push(int);
int pop(void);
void stack_init(void);
int ifstack_empty(void);
int top(void);

int n;         // number of vertex ( 'V' of graph G(V,E) )
int label = 0; // the order of vertex visiting
int *visited;  // if vertex_i was visited?
int **A;       // Adjacency matrix

int *stack;  // array for stack
int pointer; // pointer for stack

int main() {
    int start;
    int i, j;

    /* input number of vertex */
    printf("Input the number of data: ");
    scanf("%d", &n);

    /* memory allocation and initialization */
    visited = (int *)malloc(sizeof(int) * n);
    stack = (int *)malloc(sizeof(int) * n);
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

    stack_init(); // stack initialization
    printf("The edges in the DFS tree with root %d are:\n", start);
    Visit(start - 1);

    /* memory free */
    for(i = 0; i < n; i++)
        free(A[i]);
    free(A);
    free(visited);
    free(stack);

    return 0;
}

void Visit(int node) {
    int t;
    visited[node] = ++label;
    push(node);

    while(/* Complete Here!! */) { //スタックの中身がある限り
        node = top();
        for(t = 0; t < n; t++) {
            if(/* Complete Here!! */) { //同じ
                printf("(%d,%d)\n", node + 1, t + 1);
                node = t;
                visited[node] = ++label;
                push(node); // 探索したノードをスタックにpush
                t = 0;
            }
        }

        pop();
    }
}

/*
   Complete Other functions for Stack.
   ※pointerが指すのは、次のデータが挿入される場所である。
   つまり、データは入っていない場所を指す（先頭のデータが知りたいなら pointer-1 ）
*/
void push(int node) {     // push 1 data to the top of
    /* Complete Here!! */ //スタックの先頭（の次）にデータをプッシュ
    pointer++;
}

int pop(void) {
    pointer--;
    return /* Complete Here!! */; //スタックの先頭のデータを取り出す
}

int top(void) {
    return /* Complete Here!! */; //スタックの先頭のデータを調べる
}

void stack_init(void) { //スタック初期化（したことにする）
    pointer = 0;
}

int ifstack_empty(void) { //スタックが空か？（空なら１を返し、空でないなら０を返す）
    if(pointer == -1)
        return /* Complete Here!! */;
    else if(pointer >= 0)
        return /* Complete Here!! */;
}
