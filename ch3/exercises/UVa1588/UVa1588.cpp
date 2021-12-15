//
// Created by mktb on 11/20/2021.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char down[301];
char up[100];

int main() {
    while (scanf("%s%s", &down[100], up) != EOF) {

        int downLen = strlen(&down[100]);
        int upLen = strlen(up);
        int res = downLen + upLen;
        for (int i = 100 - upLen; i < 100 + downLen + upLen; i++) {
            bool flag = true;
            for (int j = 0; j < upLen; j++) {
                if (down[i + j] - '0' + up[j] - '0' > 3) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (max(i + upLen, 100 + downLen) - min(i, 100) < res) {
                    res = max(i + upLen, 100 + downLen) - min(i, 100);
                }
            }
        }
        memset(down, 0, sizeof(down));
        printf("%d\n", res);
    }
    return 0;
}
