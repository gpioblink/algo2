/*

author : Kai Yamada
id     : s1260250

*/

#include <stdio.h>
# define COIN_TYPES 4
int coins[COIN_TYPES] = {};
int coins_used[COIN_TYPES] = {};
int values[COIN_TYPES] = {25, 10, 5, 1};
int payment, account = 0, used_count = 0;


int main() {

    printf("Input numbers of each cent(coin).\n->");
    for(int i = 0; i < COIN_TYPES; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Input how many cents should you pay?\n->");
    scanf("%d", &payment);

    for(int i = 0; i < COIN_TYPES; i++) {
        while(coins[i] > 0 && payment > account && payment >= account + values[i]) {
            coins[i] -= 1;
            coins_used[i] += 1;
            account += values[i];
            used_count += 1;
        }
    }

    if(payment == account) {
        for(int i = 0; i < COIN_TYPES; i++) {
            printf("[%dcent] %d used.\n", values[i], coins_used[i]);
        }
        printf("Totally, you used %d coins for %d cents.", used_count, account);
    } else {
            printf("Error: you cannot pay for this value.");
    }
    
    printf("\n");
}