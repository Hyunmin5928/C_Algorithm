#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

const int ROWS = 6;
const int COLS = 6;
vector<vector<int>> board;

// 보드 초기화 (랜덤하게 짝 맞추기)
void initBoard() {
    vector<int> tiles;
    for (int i = 1; i <= (ROWS * COLS) / 2; i++) {
        tiles.push_back(i);
        tiles.push_back(i);
    }
    
    random_device rd;
    mt19937 g(rd());
    shuffle(tiles.begin(), tiles.end(), g);

    board.resize(ROWS, vector<int>(COLS, 0));
    int index = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = tiles[index++];
        }
    }
}

// 보드 출력
void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0)
                cout << " . ";
            else
                cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
}

// 모든 타일이 제거되었는지 확인
bool isBoardEmpty() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] != 0) return false;
        }
    }
    return true;
}

// 두 타일이 일직선으로 연결 가능한지 확인
bool isStraightLine(int r1, int c1, int r2, int c2) {
    if (r1 == r2) { // 같은 행
        for (int i = min(c1, c2) + 1; i < max(c1, c2); i++) {
            if (board[r1][i] != 0) return false;
        }
        return true;
    }
    if (c1 == c2) { // 같은 열
        for (int i = min(r1, r2) + 1; i < max(r1, r2); i++) {
            if (board[i][c1] != 0) return false;
        }
        return true;
    }
    return false;
}

// 두 타일이 한 번 꺾여서 연결 가능한지 확인
bool isOneCorner(int r1, int c1, int r2, int c2) {
    if (board[r1][c2] == 0 && isStraightLine(r1, c1, r1, c2) && isStraightLine(r1, c2, r2, c2)) return true;
    if (board[r2][c1] == 0 && isStraightLine(r1, c1, r2, c1) && isStraightLine(r2, c1, r2, c2)) return true;
    return false;
}

// 두 타일이 두 번 꺾여서 연결 가능한지 확인
bool isTwoCorner(int r1, int c1, int r2, int c2) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][c1] == 0 && isOneCorner(r1, c1, i, c1) && isOneCorner(i, c1, r2, c2)) return true;
    }
    for (int j = 0; j < COLS; j++) {
        if (board[r1][j] == 0 && isOneCorner(r1, c1, r1, j) && isOneCorner(r1, j, r2, c2)) return true;
    }
    return false;
}

// 타일 제거 가능 여부 확인
bool canRemove(int r1, int c1, int r2, int c2) {
    if (board[r1][c1] != board[r2][c2] || (r1 == r2 && c1 == c2)) return false;
    if (isStraightLine(r1, c1, r2, c2) || isOneCorner(r1, c1, r2, c2) || isTwoCorner(r1, c1, r2, c2)) return true;
    return false;
}

// 게임 실행
void playGame() {
    int r1, c1, r2, c2;
    while (true) {
        printBoard();
        if (isBoardEmpty()) {
            cout << "Congratulations! You cleared the board!" << endl;
            break;
        }
        cout << "Enter coordinates of first tile (row col): ";
        cin >> r1 >> c1;
        cout << "Enter coordinates of second tile (row col): ";
        cin >> r2 >> c2;
        if (canRemove(r1, c1, r2, c2)) {
            board[r1][c1] = 0;
            board[r2][c2] = 0;
            cout << "Tiles removed!" << endl;
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

int main() {
    initBoard();
    playGame();
    return 0;
}
