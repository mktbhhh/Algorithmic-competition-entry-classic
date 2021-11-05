#include <stdio.h>
#include <string.h>

const int maxn = 1000005;
int ans[maxn];

int main() {
    memset(ans, 0, sizeof(ans));
    for (int m = 1; m < 100005; m++) {
        int x = m, y = m;
        while (x > 0) {
            y += x % 10;
            x /= 10;
        }
        if (ans[y] == 0) {
            ans[y] = m;
        }
    }

    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}
