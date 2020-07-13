/*

author : your name
id     : your id

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;        //値（i番目の頂点から接続する頂点の番号）
    struct Node *next; //次に接続するノードのアドレス
};
typedef struct Node *NodePointer; //ノード自体のアドレスをNodePointer型として保持（ProgCと同じ定義）

void DFS(int);
NodePointer make_1node(int, NodePointer); //メモリ空間上にノードを１個生成する
NodePointer insert_node(int, int);        //生成したノードを所定のリストの末尾に接続する
void listprint(int);                      //リスト１つ分を全て表示

NodePointer *heads; // N個の連結リストの各先頭ノード(head)
static int n, label, *visited;

int main() {
    int start;
    int i, j, ver;
    NodePointer np;

    printf("Input the number of data: ");
    scanf("%d", &n);

    heads = (NodePointer *)malloc(sizeof(NodePointer) * n);
    visited = (int *)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("Input the Adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        heads[i] = make_1node(-1, NULL);
        for(j = 0; j < n; j++) {
            scanf("%d", &ver);
            if(ver != 0)
                insert_node(j, i);
        }
    }
    for(i = 0; i < n; i++)
        listprint(i);

    printf("Input the initial node: ");
    scanf("%d", &start);

    printf("The edges in the DFS tree with root %d are:\n", start);
    DFS(start - 1);

    free(visited);
    free(heads);
    return 0;
}

NodePointer make_1node(int value, NodePointer dest) {
    NodePointer n;
    if((n = (NodePointer)malloc(sizeof(struct Node))) == NULL) {
        printf("Error in memory allocation\n");
        exit(8);
    }

    n->vertex = value;
    n->next = dest;
    return n;
}

NodePointer insert_node(int value, int source) {
    NodePointer newnode, n;

    for(n = heads[source]; n->next != NULL; n = n->next)
        ;                                 //リスト末尾に接続するためにループ空回し
    newnode = make_1node(value, n->next); //新しいノードを、現在のリストの末尾へ繋ぐ
    n->next = newnode; //現在の末尾の１個前のノードから、今作ったノードへの接続をする

    return newnode;
}

void listprint(int id) {
    NodePointer n;

    printf("V%-2d is adjacent to ", id + 1);
    for(n = heads[id]->next; n != NULL; n = n->next) {
        printf("%-2d ", (n->vertex) + 1); //+1は表示上の数合わせ
    }
    printf("\n");
}

void DFS(int node) {
    NodePointer n;

    visited[node] = ++label;
    for(n = /* Complete Here!! */; n != NULL; n = n->next) {  //何番のリストを見るか？
        if(/* Complete Here!! */) {                           //まだ探索していないか？
            printf("(%2d,%2d)\n", node + 1, (n->vertex) + 1); //表示の都合、+1
            DFS(/* Complete Here!! */);
        }
    }
}
