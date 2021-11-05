#include <cstdio>
#include <cstring>

int main() {
    int T, n, ans[10];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; i++) {
            int now = i;
            while (now) {
                ans[now % 10]++;
                now /= 10;
            }
        }
        for (int i = 0; i < 10; i++) {
            if (i == 0) {
                printf("%d", ans[i]);
            } else {
                printf(" %d", ans[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

