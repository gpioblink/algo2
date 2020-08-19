/*

author : Kai Yamada
id     : s1260250

*/

#include <stdio.h>
#include <time.h>

#define AM 48271L
#define M 2147483647L
#define Q (M/AM)
#define R (M%AM)

static int A[55];
static int next = 0;
static int x2 = 1;

int next_rnd2(void);
int next_rnd3(void);
void init_rnd(void);

int data[100];

int main() {
    int getrand, i;

    init_rnd();

    for(i = 0; i < 100; i++) {
        getrand = next_rnd3();
        printf("%d: %d\n", i + 1, getrand);
    }

    return 0;
}

void init_rnd(void) {
    int i;
    for(i = 0; i < 55; i++) A[i] = next_rnd3();
}

int next_rnd3(void) {
    int i, j, x;
    i = (next+31)%55;
    x = (A[i]-A[next]);
    if(x<0) {
        x += 2147483647;
        x += 1;
    }
    printf("%d", x);
    A[next] = x;
    next = (next+1) % 55;
    return x;
}

int next_rnd2(void) {
    x2 = AM * (x2%Q) -R * (x2/Q);
    if(x2<0) x2=x2+M;
    return x2;
}
