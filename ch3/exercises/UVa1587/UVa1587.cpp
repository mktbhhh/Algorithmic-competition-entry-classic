//
// Created by mktb on 11/19/2021.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

bool operator==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Point &a, const Point &b) {
    return !(a == b);
}

bool operator<(const Point &a, const Point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

istream &operator>>(istream &is, Point &p) {
    return is >> p.x >> p.y;
}

ostream &operator<<(ostream &os, const Point &p) {
    return os << "[" << p.x << ", " << p.y << "]";
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << " ";
    }
    return os;
}

typedef Point Rect;
vector<Rect> rects;

bool solve() {
    sort(rects.begin(), rects.end());
    for (int i = 0; i < 3; i++) {
        if (rects[2 * i] != rects[2 * i + 1]) {
            return false;
        }
    }
    const Rect &r1 = rects[1], &r2 = rects[3], &r3 = rects[5];
    return r1.x == r2.x && r1.y == r3.x && r2.y == r3.y;
}

int main() {
    Rect r;
    while (true) {
        rects.clear();
        for (int i = 0; i < 6; i++) {
            if (!(cin >> r)) {
                return 0;
            }
            if (r.x > r.y) {
                swap(r.x, r.y);
            }
            rects.push_back(r);
        }
        if (solve()) {
            cout << "POSSIBLE" << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}
