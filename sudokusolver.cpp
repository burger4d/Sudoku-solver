#include <iostream>
#include <vector>

std::vector<std::vector<int>> board = {
    
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 1, 0, 0, 8, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 6, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0}

};

bool solve();
bool no_more_cells(std::vector<std::vector<int>> board);
bool findEmpty(int &x0, int &y0);
void show(std::vector<std::vector<int>> board);

int main()
{
    show(board);
    std::cout << "\n";
    std::cout << solve() << " ";
    std::cout << "\n";
    show(board);
}

bool isValid(int num, int x, int y) {
    for (int x2 = 0; x2 < 9; x2++) {
        if (board[y][x2] == num) {
            return false;
        }
    }
    for (int y2 = 0; y2 < 9; y2++) {
        if (board[y2][x] == num) {
            return false;
        }
    }
    int X = x - x % 3;
    int Y = y - y % 3;
    for (int col = 0; col < 3; col++) {
        for (int row = 0; row < 3; row++) {
            if (board[Y + col][X + row] == num) {
                return false;
            }
        }
    }
    return true;
}

bool no_more_cells(){
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (board[y][x] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool findEmpty(int &x, int &y) {
    for (int y0 = 0; y0 < 9; y0++) {
        for (int x0 = 0; x0 < 9; x0++) {
            if (board[y0][x0] == 0) {
                x = x0;
                y = y0;
                return true;
            }
        }
    }
}
bool solve() {
    int x0 = 0;
    int y0 = 0;
    if (no_more_cells()) {
        return true;  
    }
    findEmpty(x0, y0);
    for (int i = 1; i < 10; i++) {
        if (isValid(i, x0, y0)){
            board[y0][x0] = i;
            if (solve()) {
                            return true;
                        }
                    }
                    board[y0][x0] = 0;
                }
    return false;
}

void show(std::vector<std::vector<int>> board) {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            std::cout << board[y][x];
        }
        std::cout << "\n";
    }
}
/*
3 1 6 | 5 7 8 | 4 9 2
5 2 9 | 1 3 4 | 7 6 8
4 8 7 | 6 2 9 | 5 3 1
-------------------------- -
2 6 3 | 4 1 5 | 9 8 7
9 7 4 | 8 6 3 | 1 2 5
8 5 1 | 7 9 2 | 6 4 3
-------------------------- -
1 3 8 | 9 4 7 | 2 5 6
6 9 2 | 3 5 1 | 8 7 4
7 4 5 | 2 8 6 | 3 1 9
*/
