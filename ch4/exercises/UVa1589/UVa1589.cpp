//
// Created by mktb on 12/15/2021.
//

#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>

using namespace std;

struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator+(const Vector &a, const Vector &b) {
    return Vector(a.x + b.x, a.y + b.y);
}

Vector operator-(const Vector &a, const Vector &b) {
    return Vector(a.x - b.x, a.y - b.y);
}

Vector operator*(const Vector &a, const int p) {
    return Vector(a.x * p, a.y * p);
}

Vector operator/(const Vector &a, const int p) {
    return Vector(a.x / p, a.y / p);
}

bool operator==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

bool operator<(const Point &a, const Point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

// x in [left, right]
bool inRange(int x, int left, int right) {
    if (left > right) {
        return inRange(x, right, left);
    }
    return left <= x && x <= right;
}

// 双方将帅
Point blackG, redG;
char board[16][16];
vector<Point> DIRS = {{1,  0},
                      {0,  1},
                      {-1, 0},
                      {0,  -1}},
        HDIRS = {{2,  1},
                 {1,  2},
                 {-1, 2},
                 {-2, 1},
                 {-2, -1},
                 {-1, -2},
                 {1,  -2},
                 {2,  -1}},
        redPieces;

bool inBPalace(const Point &bPos) {
    return inRange(bPos.x, 1, 3) && inRange(bPos.y, 4, 6);
}

bool canFly(const Point &p1, const Point &p2, int sz = 0) {
    bool v = (p1.x == p2.x), h = (p1.y == p2.y);
    assert(v || h);
    assert(!(v && h));
    int lx = min(p1.x, p2.x), ux = max(p1.x, p2.x),
            ly = min(p1.y, p2.y), uy = max(p1.y, p2.y),
            cnt = 0;
    if (v) {
        for (int y = ly + 1; y < uy; y++) {
            if (board[p1.x][y] && ++cnt > sz) {
                return false;
            }
        }
        return cnt == sz;
    }

    for (int x = lx + 1; x < ux; x++) {
        if (board[x][p1.y] && ++cnt > sz) {
            return false;
        }
    }
    return cnt == sz;
}

bool checkmate(const Point &r, const Point &b) {
    bool ans = true;
    switch (board[r.x][r.y]) {
        case 'G': {
            return r.y == b.y && canFly(r, b);
        }
        case 'R': {
            return (r.x == b.x || r.y == b.y) && canFly(r, b);
        }
        case 'H': {
            for (const auto &HD: HDIRS) {
                Point hPos = r + HD, legPos = r + HD / 2;
                if (hPos == b && board[legPos.x][legPos.y] == 0) {
                    return true;
                }
            }
        }
        case 'C': {
            return (r.x == b.x || r.y == b.y) && canFly(r, b, 1);
        }
        default: {
            assert(false);
            break;
        }
    }
}

bool canWin() {
    assert(inBPalace(blackG));
    if (blackG.y == redG.y && canFly(blackG, redG)) {
        return false;
    }

    for (const auto &D: DIRS) {
        Point bp = blackG + D;
        if (!inBPalace(bp)) {
            continue;
        }

        char back = board[bp.x][bp.y];
        board[bp.x][bp.y] = 0;

        bool live = true;
        for (const auto &r: redPieces) {
            if (board[r.x][r.y] && checkmate(r, bp)) {
                live = false;
                break;
            }
        }

        board[bp.x][bp.y] = back;
        if (live) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    while (scanf("%d%d%d", &N, &(blackG.x), &(blackG.y)) == 3 && N) {
        redPieces.clear();
        memset(board, 0, sizeof(board));
        for (int i = 0; i < N; i++) {
            char type;
            Point p;
            scanf(" %c%d%d", &type, &(p.x), &(p.y));
            redPieces.push_back(p);
            board[p.x][p.y] = type;
            if (type == 'G') {
                redG = p;
            }
        }

        puts(canWin() ? "YES" : "NO");
    }

    return 0;
}
