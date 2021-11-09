//
// Created by mktb on 11/9/2021.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct ChCnt {
    char ch;
    int cnt;

    void init(char c) {
        ch = c;
        cnt = 0;
    }

    bool operator<(const ChCnt &cc2) const {
        return cnt > cc2.cnt || (cnt == cc2.cnt) && ch < cc2.ch;
    }
};



int main() {
    int T, m, n;
    scanf("%d", &T);
    string line;
    vector<string> seqs;
    char IDX[256] = {0};
    IDX['A'] = 0;
    IDX['C'] = 1;
    IDX['G'] = 2;
    IDX['T'] = 3;
    while (T--) {
        seqs.clear();
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; ++i) {
            cin >> line;
            seqs.push_back(line);
        }
        string ansString;
        int ans = 0;
        vector<ChCnt> ccs(4);
        for (int i = 0; i < n; i++) {
            ccs[IDX['A']].init('A');
            ccs[IDX['C']].init('C');
            ccs[IDX['G']].init('G');
            ccs[IDX['T']].init('T');
            for (int j = 0; j < m; j++) {
                ccs[IDX[seqs[j][i]]].cnt++;
            }
            sort(ccs.begin(), ccs.end());
            ansString += ccs.front().ch;
            ans += (m - ccs.front().cnt);
        }

        printf("%s\n%d\n", ansString.c_str(), ans);
    }

    return 0;
}
