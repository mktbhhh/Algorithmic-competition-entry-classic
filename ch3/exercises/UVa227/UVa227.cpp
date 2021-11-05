//
// Created by mktb on 11/3/21.
//

//#include <cstdio>
//#include <cstring>
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//char puzzle[6][6];
//int row, col;
//
//bool moveto(char s) {
//    switch (s) {
//        case 'A': {
//            if (row == 0) {
//                return false;
//            } else {
//                puzzle[row][col] = puzzle[row - 1][col];
//                puzzle[row - 1][col] = ' ';
//                row--;
//                return true;
//            }
//        }
//        case 'B': {
//            if (row == 4) {
//                return false;
//            } else {
//                puzzle[row][col] = puzzle[row + 1][col];
//                puzzle[row + 1][col] = ' ';
//                row++;
//                return true;
//            }
//        }
//        case 'L': {
//            if (col == 0) {
//                return false;
//            } else {
//                puzzle[row][col] = puzzle[row][col - 1];
//                puzzle[row][col - 1] = ' ';
//                col--;
//                return true;
//            }
//        }
//        case 'R': {
//            if (col == 4) {
//                return false;
//            } else {
//                puzzle[row][col] = puzzle[row][col + 1];
//                puzzle[row][col + 1] = ' ';
//                col++;
//                return true;
//            }
//        }
//        default: {
//            return false;
//        }
//    }
//}
//
//
//int main() {
//    int n = 1;
//    char con[500];
//    while (cin.getline(puzzle[0], 6, '\n')) {
//        if (strlen(puzzle[0]) == 1 && puzzle[0][0] == 'Z') {
//            break;
//        }
//
//
//        for (int i = 1; i < 5; i++) {
//            cin.getline(puzzle[i], 6, '\n');
//            if (strlen(puzzle[i]) < 5) {
//                puzzle[i][4] = ' ';
//                puzzle[i][6] = 0;
//            }
//        }
//
//        string str;
//        bool flag = true;
//        scanf("%s", con);
//        while (con[strlen(con) - 1] != '0') {
//            str += con;
//            scanf("%s", con);
//        }
//        getchar();
//        str += con;
//
//        for (int i = 0; i < 5; i++) {
//            for (int j = 0; j < 5; j++) {
//                if (puzzle[i][j] == ' ') {
//                    row = i;
//                    col = j;
//                    break;
//                }
//            }
//        }
//
//        for (int i = 0; i < str.length() - 1; i++) {
//            if (!moveto(str.at(i))) {
//                flag = false;
//                break;
//            }
//        }
//
//        if (n == 1) {
//            printf("Puzzle #%d:\n", n++);
//        } else {
//            printf("\nPuzzle #%d:\n", n++);
//        }
//
//        if (flag) {
//            for (int i = 0; i < 5; i++) {
//                for (int j = 0; j < 5; j++) {
//                    if (j == 0) {
//                        printf("%c", puzzle[i][j]);
//                    } else {
//                        printf(" %c", puzzle[i][j]);
//                    }
//                }
//                printf("\n");
//            }
//        } else {
//            printf("This puzzle has no final configuration.\n");
//        }
//    }
//
//    return 0;
//}

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator+(const Vector &A, const Vector &B) {
    return Vector(A.x + B.x, A.y + B.y);
}

Vector operator-(const Vector &A, const Vector &B) {
    return Vector(A.x - B.x, A.y - B.y);
}

Vector operator*(const Vector &A, int p) {
    return Vector(A.x * p, A.y * p);
}

Vector operator/(const Vector &A, int p) {
    return Vector(A.x / p, A.y / p);
}

bool operator==(const Vector &a, const Vector &b) {
    return a.x == b.x && a.y == b.y;
}

bool operator<(const Vector &a, const Vector &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

const int GSize = 5;
vector<string> grid;
Point ePos;
map<char, Vector> DIRS = {
        {'A', Vector(-1, 0)}, {'B', Vector(1, 0)}, {'L', Vector(0, -1)}, {'R', Vector(0, 1)}
};

bool valid(const Point &p) {
    return p.x >= 0 && p.x < GSize && p.x >= 0 && p.y < GSize;
}

void printGrid() {
    for (int i = 0; i < GSize; i++) {
        for (int j = 0; j < GSize; j++) {
            if (j) cout << ' ';
            cout << grid[i][j];
        }
        cout << endl;
    }
}

bool tryMove(char cmd) {
    if (!DIRS.count(cmd)) {
        return false;
    }
    Point p = ePos + DIRS[cmd];
    if (!valid(p)) {
        return false;
    }
    swap(grid[p.x][p.y], grid[ePos.x][ePos.y]);
    ePos = p;

    return true;
}

int main() {
    int t = 1;
    string line;
    while (true) {
        grid.clear();
        ePos.x = -1, ePos.y = -1;
        for (int i = 0; i < GSize; i++) {
            getline(cin, line);
            if (line == "Z") {
                return 0;
            }
            for (int j = 0; j < GSize; j++) {
                if (line[j] != ' ') {
                    continue;
                } else {
                    ePos.x = i;
                    ePos.y = j;
                }
            }
            grid.push_back(line);
        }

        string moves;
        while (true) {
            getline(cin, line);
            bool end = *line.rbegin() == '0';
            if (!end) {
                moves.append(line);
            } else {
                moves.append(line, 0, line.size() - 1);
                break;
            }
        }

        bool legal = true;

        for (int i = 0; i < moves.size(); i++) {
            if (!tryMove(moves[i])) {
                legal = false;
                break;
            }
        }

        if (t > 1) {
            cout << endl;
        }
        cout << "Puzzle #" << t++ << ":" << endl;
        if (legal) {
            printGrid();
        } else {
            cout << "This puzzle has no final configuration." << endl;
        }
    }
}

