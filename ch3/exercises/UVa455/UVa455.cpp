//
// Created by mktb on 11/1/21.
//

//
// Created by mktb on 11/1/2021.
//
//
//#include <cstdio>
//#include <cstring>

//int main() {
//    int N, ans;
//    char line[128];
//    bool first = true;
//    scanf("%d", &N);
//
//    while (N--) {
//        if (first) {
//            first = false;
//        } else {
//            puts("");
//        }
//        scanf("%s", line);
//        int sz = strlen(line);
//        for (int i = 1; i <= sz; i++) {
//            bool flag = true;
//            ans = sz;
//            if (sz % i) {
//                continue;
//            } else {
//                for (int j = 0; j < sz - i; j++) {
//                    if (line[j] != line[j + i]) {
//                        flag = false;
//                        break;
//                    }
//
//                    if (j == sz - i - 1) {
//                        ans = i;
//                    }
//                }
//            }
//
//            if (flag) {
//                break;
//            }
//        }
//        printf("%d\n", ans);
//    }
//
//    return 0;
//}

#include <cstdio>
#include <cstring>

int main() {
    int N;
    scanf("%d", &N);
    char line[128];
    bool first = true;

    while (N--) {
        if (first) {
            first = false;
        } else {
            printf("\n");
        }
        scanf("%s", line);
        int sz = strlen(line);
        for (int p = 1; p <= sz; p++) {
            if (sz % p) {
                continue;
            }
            bool ans = true;
            for (int i = 0; i < p; ++i) {
                for (int j = i + p; j < sz; j += p) {
                    if (line[j] != line[i]) {
                        ans = false;
                        break;
                    }
                }
                if (!ans) {
                    break;
                }
            }

            if (ans) {
                printf("%d\n", p);
                break;
            }
        }
    }

    return 0;
}
