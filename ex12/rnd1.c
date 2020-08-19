/*

author : Kai Yamada
id     : s1260250

*/

#include <stdio.h>
#include <stdlib.h>

static long x = 53402397;

int next_rnd1(void);

int data[100];

int main() {
    int getrand, i;

    for(i = 0; i < 100; i++) {
        getrand = next_rnd1();
        printf("%d: %d\n", i + 1, getrand);
    }

    // for(i=0;i<20;i++) printf("%d ",data[i]); // sample for listing outputs
    printf("\n");
    return 0;
}

int next_rnd1(void) {
    x = x * 65539 + 125654;
    if (x < 0) {
        x += 2147483647;
        x += 1;
    }
    return x;
}
