//
// Created by mktb on 11/19/2021.
//

#include <iostream>
#include <cstring>

char s[100030], t[100030];

int main() {
    while (scanf("%s%s", s, t) == 2) {
        int sLen = strlen(s);
        int tLen = strlen(t);
        int index = 0;
        int now = -1;

        for (int i = 0; i < sLen; i++) {
            for (; index < tLen; index++) {
                if (s[i] == t[index]) {
                    now = i;
                    index++;
                    break;
                }
            }
            if (now != i) {
                break;
            }
        }
        if (now == sLen - 1) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}

/**

#include <cstdio>
#include <cstring>
const int LEN = 100024;
char s[LEN], t[LEN];
int main() {
    while (scanf("%s%s", s, t) == 2) {
        int sLen = strlen(s), tLen = strlen(t);
        bool ok = true;
        for (int i = 0, j = 0; i < sLen; i++, j++) {
            while (j < tLen && t[j] != s[i]) j++;
            if (j == tLen) { ok = false; break; }
        }
        printf("%s\n", ok ? "Yes" : "No" );
    }
    return 0;
}


**/