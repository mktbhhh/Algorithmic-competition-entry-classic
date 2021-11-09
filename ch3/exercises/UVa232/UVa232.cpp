//
// Created by mktb on 11/8/2021.
//
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0): x(x), y(y)  {}
};

typedef Point Vector;

Vector operator+(const Vector &a, const Vector &b) {
    return Vector(a.x + b.x, a.y + b.y);
}

int R, C;
const int MAXC = 16;
char grid[MAXC][MAXC];

inline bool valid(const Point &p) {
    return p.x >= 0 && p.y >= 0 && p.x < R && p.y < C;
}

int main() {
    char buf[MAXC];
    int bufLen;
    const Vector dLeft(0, -1), dUp(-1, 0), dDown(1, 0), dRight(0, 1);
    for (int t = 1; scanf("%d%d", &R, &C) == 2 && R; t++) {
        vector<Point> eligible;
        vector<int> down, cross;

        if (t > 1) {
            printf("\n");
        }
        printf("puzzle #%d:\n", t);
        for (int i = 0; i < R; i++) {
            scanf("%s", grid[i]);
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '*') {
                    continue;
                }
                Point p(i, j), left = p + dLeft, up = p + dUp;
                bool isCross = !valid(left) || grid[left.x][left.y] == '*';
                bool isDown = !valid(up) || grid[up.x][up.y] == '*';
                if (isCross) {
                    cross.push_back(eligible.size());
                }
                if (isDown) {
                    down.push_back(eligible.size());
                }
                if (isCross || isDown) {
                    eligible.push_back(p);
                }
            }
        }

        printf("Across\n");
        for (const auto &n : cross) {
            bufLen = 0, memset(buf, 0, sizeof(buf));
            Point p = eligible[n];
            while (valid(p) && grid[p.x][p.y] != '*') {
                buf[bufLen++] = grid[p.x][p.y];
                p = p + dRight;
            }
            printf("%3d.%s\n", n + 1, buf);
        }

        printf("Down\n");
        for (const auto &n : down) {
            bufLen = 0, memset(buf, 0, sizeof(buf));
            Point p = eligible[n];
            while (valid(p) && grid[p.x][p.y] != '*') {
                buf[bufLen++] = grid[p.x][p.y];
                p = p + dDown;
            }
            printf("%3d.%s\n", n + 1, buf);
        }
    }

    return 0;
}
