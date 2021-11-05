#include <cstdio>
#include <cctype>
#include <cstring>
#include <cassert>

int main() {
    int T, num, sz;
    char buf[256], c, s;
    double W[256], ans;
    W['C'] = 12.01, W['H'] = 1.008, W['O'] = 16.00, W['N'] = 14.01;
    scanf("%d\n", &T);
    while (T--) {
        ans = 0;
        num = -1;
        s = 0;
        scanf("%s", buf);
        sz = strlen(buf);

        for (int i = 0; i < sz; i++) {
            c = buf[i];
            if (isupper(c)) {
                if (i) {
                    if (num == -1) {
                        num = 1;
                    }
                    ans += num * W[s];
                }
                s = c;
                num = -1;
            } else {
                assert(isdigit(c));
                if (num == -1) {
                    num = 0;
                }
                num = num * 10 + c - '0';
            }
        }

        if (num == -1) {
            num = 1;
        }
        ans += num * W[s];

        printf("%.3lf\n", ans);
    }
    return 0;
}
