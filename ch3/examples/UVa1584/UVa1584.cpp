#include <stdio.h>
#include <string.h>

const int maxn = 105;

bool less(const char *s, int p, int q) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[(p + i) % n] != s[(q + i) % n]) {
            return s[(p + i) % n] < s[(q + i) % n];
        }
    }
    return 0;
}

int main() {
    int T;
    char s[maxn];
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int len = strlen(s);
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (less(s, i, ans)) {
                ans = i;
            }
        }
        for (int i = 0; i < len; i++) {
            printf("%c", s[(ans + i) % len]);
        }
        printf("\n");
    }
    return 0;
}
