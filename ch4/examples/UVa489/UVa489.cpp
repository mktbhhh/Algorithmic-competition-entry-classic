//
// Created by mktb on 11/22/2021.
//

#include <cstdio>
#include <cstring>
const int maxn = 100;
int left, chance;
char s[maxn], g[maxn];
int win, lose;

void guess(char ch) {
    int bad = 1;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ch) {
            left--;
            s[i] = ' ';
            bad = 0;
        }
    }
    if (bad) {
        chance--;
    }
    if (!chance) {
        lose = 1;
    }
    if (!left) {
        win = 1;
    }
}

int main() {
    int rnd;
    while (scanf("%d", &rnd) != EOF && rnd != -1) {
        scanf("%s%s", s, g);
        printf("Round %d\n", rnd);
        win = lose = 0;

        left = strlen(s);
        chance = 7;
        for (int i = 0; i < strlen(g); i++) {
            guess(g[i]);
            if (win || lose) {
                break;
            }
        }

        if (win) {
            printf("You win.\n");
        } else if (lose) {
            printf("You lose.\n");
        } else {
            printf("You chickened out.\n");
        }
    }

    return 0;
}

