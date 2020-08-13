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
int payment, account = 0, used_count = 0, n;
int *table;

int print_table(int *table, int step) {
    printf("[%d step]\n");
    for(int i = 0; i <= payment; i++) {
        printf("%4d", i);
    }
    printf("\n");
    for(int i = 0; i <= payment; i++) {
        if(table[i] != -1) printf("%4d", table[i]);
        else printf("  __");
    }
    printf("\n");
}

int calc_breakdown(int *table, int price) {
    int amounts[MAX_TYPES] = {};
    printf("total: %dcoins for %dyen\n", table[price], price);
    while(price > 0) {
        for(int i = 0; i < n; i++) {
            if(table[price] == table[price - values[i]] + 1) {
                price -= values[i];
                amounts[i] += 1;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%dyen x %dcoins = %d\n", values[i], amounts[i], values[i]*amounts[i]);
    }
}

int main() {

    printf("How many type of coins you want to consider?\n->");
    scanf("%d", &n);

    printf("Input what type of coins is exsisted in ascending order. (e.g. '1 5 10 17 25')\n->");
    for(int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Input how many cents should you pay?\n->");
    scanf("%d", &payment);

    // テーブルの作成
    table = (int *)malloc((payment+1) * sizeof(int));

    // 初期化
    for(int i = 0; i <= payment; i++) {
        table[i] = -1;
    }
    table[0] = 0;

    for(int i = 0; i <= payment; i++) {
        if(table[i] != -1) {
            for(int j = 0; j < n; j++) {
                if(table[i + values[j]] == -1 || table[i + values[j]] > table[i] + 1) {
                    table[i + values[j]] = table[i] + 1;
                }
            }
        }
        print_table(table, i);
    }
    calc_breakdown(table, payment);
}