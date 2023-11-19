#include <stdio.h>

const int I_0 = 13;
const int J_0 = 19;
const int L_0 = 14;

struct step {
    int i; int j; int l; int k;
};

int max (int a, int b) {
    if (a > b) { return a; }
    else { return b;}
}

int min (int a, int b) {
    if (a > b) { return b; }
    else { return a; }
}

int sign (int a) {
    if (a > 0) { return 1; }
    if (a == 0) { return 0; }
    else { return -1; }
}

int abs (int a) {
    if (a > 0) { return a; }
    else {return -a; }
}

int main() {
    struct step last = {I_0, J_0, L_0, 0};

    for (int n = 1; n <= 50; ++n) {
        int i_new = sign(last.i + 1) * abs(abs(last.k - last.j) - abs(last.i - last.l));
        int j_new = last.j % 20 + max(last.i % 20, min(last.j - last.k, last.l - last.k)) - 10;
        int l_new = (last.k * (last.i + 1) * (last.j + 2) * (last.l + 3)) % 20;

        struct step current = {i_new, j_new, l_new, last.k + 1};

        printf("k: % 3d i: % 3d, j: %3d, l: % 3d\n", current.k, current.i, current.j, current.l);

        if (((current.i + current.j + 10) < 0) && ((current.i + current.j + 20) > 0)) {
            printf("Stopped on: %d", current.k);
            return 0;
        }

        last = current;
    }
    printf("No point fell within the specified area :(");
    return 0;
}
