//
// Created by mktb on 11/9/2021.
//

#include <iostream>
#include <map>
using namespace std;

map<int, int> pos;

void solve(int n, int d, string &ans, int &r) {
    ans = ".";
    pos.clear();

    while (true) {
        n *= 10;
        int p = pos[n];
        if (p == 0) {
            pos[n] = ans.size();
        } else {
            r = ans.size() - p;
            if (r > 50) {
                ans.erase(p + 50);
                ans += "...";
            }
            ans.insert(p, "(");
            ans += ")";
            break;
        }

        if (n < d) {
            ans += '0';
            continue;
        }

        int div = n / d;
        int mod = n % d;
        ans += (char) (div + '0');
        n = mod;
        if (n == 0) {
            ans += "(0)";
            r = 1;
            break;
        }
    }
}

int main() {
    int n, d;
    while (scanf("%d%d", &n, &d) == 2) {
        string ans = ".(0)";
        int r = 1;
        if (n % d) {
            solve(n % d, d, ans, r);
        }
        printf("%d/%d = %d%s\n", n, d, n / d, ans.c_str());
        printf("   %d = number of digits in repeating cycle\n\n", r);
    }

    return 0;
}
