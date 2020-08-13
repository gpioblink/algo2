/*

author : Kai Yamada
id     : s1260250

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_TYPES 100
int coins[MAX_TYPES] = {};
int coins_used[MAX_TYPES] = {};
int values[MAX_TYPES] = {};
int sorted_values[MAX_TYPES] = {};
int payment, account = 0, used_count = 0, n;
int **table, *reached;

// #define DEBUG

void downheap(int *A, int k,
              int n) { // downheapによってヒープチェック・メンテナンスを行う関数
    int j;
    int v; //一時退避用の変数。使い方はupheapと同様に

    v = A[k];
    while(k <= n / 2) {
        /* Complelte Here!! */ //子ノードへ移る
        j = k+k;

        if(j < n && A[j]>A[j+1])
            j++; //２つの子ノードのうち、どちらと比較すればいいか
        if(v <= A[j])
            break;

        A[k] = A[j];
        k = j;
    }
    A[k] = v;
}

void construct_2(int *A, int n) { // downheapで構築
    int i, j;
    for(i = n/2; i >= 1; i--) {
        downheap(A, i, n);
    }
}

int delete_root(int *A,
                int *n) { //根の値の削除（引数：　ヒープの配列、削除前のデータ数…を保持する「アドレス」）
                          //アドレス渡し化 …
    //ヒープ操作の全ての機能をハンドアウト通りに実装したときに、起こりうる不整合を防ぐため　
    int v = A[1];

    /* Complelte Here!! */
    A[1] = A[*n];
    (*n)--;
    downheap(A, 1, *n);
    /* Complelte Here!! ＜upheap？ downheap？ なぜ？＞*/

    return v; //戻り値：ヒープから削除された値
}

void print_table(int *table, int step) {
    printf("[%d step]\n");
    for(int i = 0; i <= payment; i++) {
        printf("%4d", i);
    }
    printf("\n");
    for(int i = 0; i <= payment; i++) {
        if(table[i] != -1) {
            printf("%4d", table[i]);
        }
        else printf("  __");
    }
    printf("\n");
}

// 今までにその値を使っていないか確認
int calc_breakdown(int *table, int price, int check) {
    int amounts[MAX_TYPES] = {}, moved = 1, original_price = price;

    while(price > 0 && moved == 1) {
        moved = 0;
        for(int i = 0; i < n; i++) {
            if(table[price] == table[price - sorted_values[i]] + 1 && amounts[i] == 0) {
                price -= sorted_values[i];
                amounts[i] += 1;
                moved = 1;
                break;
            }
        }
    }

    if(check != -1) {
        #ifdef DEBUG
            for(int i = 0; i < n; i++) {
                printf("%d:%d ", sorted_values[i], amounts[i]);
            }
            printf("\n");
            if(amounts[check] == 0) {
                printf("%dyen is available\n", check);
            }
        #endif

        if(amounts[check] == 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        #ifdef DEBUG
        printf("total: %dcoins, price: %dyen, remaining: %dyen\n", table[original_price], original_price, price);
        #endif
        if(price == 0) {
            printf("YES\n");
            for(int i = 0; i < n; i++) {
                if(amounts[i]) {
                    printf("%d ", sorted_values[i]);
                }
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
    }
    
}

int main() {

    printf("How many type of coins you want to consider?\n->");
    scanf("%d", &n);

    printf("Input how coins should you pay?\n->");
    scanf("%d", &payment);

    printf("Input what type of coins is exsisted. (e.g. '1 5 10 17 25')\n->");
    for(int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    construct_2(values, n);

    int ni = n;
    for(int i = 0; i < n; i++) {
        int v = delete_root(values, &ni);
        sorted_values[i] = v;
        printf("%d\n", v);
    }

    // テーブルの作成
    reached = (int *)malloc((payment+1) * sizeof(int));

    // 初期化
    for(int i = 0; i <= payment; i++) {
        reached[i] = -1;
    }
    
    reached[0] = 0;

    for(int i = 0; i <= payment; i++) {
        if(reached[i] != -1) {
            for(int j = 0; j < n; j++) {
                if(reached[i + sorted_values[j]] == -1 || reached[i + sorted_values[j]] > reached[i] + 1) {
                    if(calc_breakdown(reached, i, j)) { // その券種を2度以上使おうとしていないか確認。OKならQ1と同様
                        reached[i + sorted_values[j]] = reached[i] + 1;
                    }
                }
            }
        }
        #ifdef DEBUG
            print_table(reached, i);
        #endif
    }

    calc_breakdown(reached, payment, -1);
}