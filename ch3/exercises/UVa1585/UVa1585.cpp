#include <stdio.h>
#include <string.h>

int main() {
    int T;
    char str[80] = "";
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        int n = strlen(str);
        int flag = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == 'O') {
                ans += ++flag;
            } else {
                flag = 0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
