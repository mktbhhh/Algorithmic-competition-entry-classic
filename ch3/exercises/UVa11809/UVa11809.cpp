//
// Created by mktb on 11/20/2021.
//

#include <cstdio>
#include <cmath>
#include <cstring>

const double EPS = 1e-6;

int main() {
    char line[256];
    double lg2 = log10(2), A, v;
    int B;
    while (scanf("%s", line) == 1 && strcmp(line, "0e0") != 0) {
        *strchr(line, 'e') = ' ';
        sscanf(line, "%lf%d", &A, &B);
        v = log10(A) + B;
        for (int M = 0; M < 10; M++) {
            int E = round(log10((v + M * lg2 - log10(pow(2, M + 1) - 1)) / lg2 + 2) / lg2);
            if (fabs(((1 << E) - 1) * lg2 + log10(pow(2, M + 1) - 1) - (M + 1) * lg2 - v) <= EPS) {
                printf("%d %d\n", M, E);
                break;
            }
        }
    }

    return 0;
}
