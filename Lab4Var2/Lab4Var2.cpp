#include "Header.h"

void startGame() {
    displayBoard(gameBoard);
    while (!gameEnded) {
        if (currentPlayer == AI) {
            executeMove(gameBoard, computeAiMove(), AI);
        }
        else {
            executeMove(gameBoard, getUserInput(), HUMAN);
        }
        if (turnCount == ROWS * COLS) {
            gameEnded = true;
        }
        gameEnded = checkWin(gameBoard, currentPlayer);
        currentPlayer = (currentPlayer == HUMAN) ? AI : HUMAN;
        turnCount++;
        displayBoard(gameBoard);
    }
    cout << "\033[1;33m" << (turnCount == ROWS * COLS ? "НИЧЬЯ!" : (currentPlayer == HUMAN ? "БОТ ПОБЕДИЛ!" : "ИГРОК ПОБЕДИЛ!")) << endl;
}

void executeMove(vector<vector<int>>& board, int col, unsigned int player) {
    for (unsigned int row = 0; row < ROWS; row++) {
        if (board[row][col] == 0) {
            board[row][col] = player;
            break;
        }
    }
}

int getUserInput() {
    int column = -1;
    while (true) {
        cout << "\033[1;36m" << "Введите номер столбца: ";
        cin >> column;
        if (!cin) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            handleErrors(1);
        }
        else if (!(column >= 0 && column < (int)COLS)) {
            handleErrors(2);
        }
        else if (gameBoard[ROWS - 1][column] != 0) {
            handleErrors(3);
        }
        else {
            break;
        }
    }
    return column;
}

int computeAiMove() {
    cout << "\033[1;32m" << "ИИ думает..." << endl;
    return performMinimax(gameBoard, MAX_DEPTH, -INT_MAX, INT_MAX, AI)[1];
}

array<int, 2> performMinimax(vector<vector<int>>& board, unsigned int depth, int alpha, int beta, unsigned int player) {
    if (depth == 0 || depth >= (COLS * ROWS) - turnCount) {
        return { evaluateBoard(board, AI), -1 };
    }
    if (player == AI) {
        array<int, 2> bestMove = { INT_MIN, -1 };
        if (checkWin(board, HUMAN)) return bestMove;
        for (unsigned int col = 0; col < COLS; col++) {
            if (board[ROWS - 1][col] == 0) {
                vector<vector<int>> tempBoard = cloneBoard(board);
                executeMove(tempBoard, col, player);
                int score = performMinimax(tempBoard, depth - 1, alpha, beta, HUMAN)[0];
                if (score > bestMove[0]) {
                    bestMove = { score, (int)col };
                }
                alpha = max(alpha, bestMove[0]);
                if (alpha >= beta) break;
            }
        }
        return bestMove;
    }
    else {
        array<int, 2> bestMove = { INT_MAX, -1 };
        if (checkWin(board, AI)) return bestMove;
        for (unsigned int col = 0; col < COLS; col++) {
            if (board[ROWS - 1][col] == 0) {
                vector<vector<int>> tempBoard = cloneBoard(board);
                executeMove(tempBoard, col, player);
                int score = performMinimax(tempBoard, depth - 1, alpha, beta, AI)[0];
                if (score < bestMove[0]) {
                    bestMove = { score, (int)col };
                }
                beta = min(beta, bestMove[0]);
                if (alpha >= beta) break;
            }
        }
        return bestMove;
    }
}

int evaluateBoard(vector<vector<int>> board, unsigned int player) {
    int score = 0;
    vector<unsigned int> row(COLS);
    vector<unsigned int> col(ROWS);
    vector<unsigned int> set(4);

    for (unsigned int r = 0; r < ROWS; r++) {
        for (unsigned int c = 0; c < COLS; c++) row[c] = board[r][c];
        for (unsigned int c = 0; c < COLS - 3; c++) {
            for (int i = 0; i < 4; i++) set[i] = row[c + i];
            score += calculateScore(set, player);
        }
    }

    for (unsigned int c = 0; c < COLS; c++) {
        for (unsigned int r = 0; r < ROWS; r++) col[r] = board[r][c];
        for (unsigned int r = 0; r < ROWS - 3; r++) {
            for (int i = 0; i < 4; i++) set[i] = col[r + i];
            score += calculateScore(set, player);
        }
    }

    for (unsigned int r = 0; r < ROWS - 3; r++) {
        for (unsigned int c = 0; c < COLS - 3; c++) {
            for (int i = 0; i < 4; i++) set[i] = board[r + i][c + i];
            score += calculateScore(set, player);
        }
    }

    for (unsigned int r = 0; r < ROWS - 3; r++) {
        for (unsigned int c = 0; c < COLS - 3; c++) {
            for (int i = 0; i < 4; i++) set[i] = board[r + 3 - i][c + i];
            score += calculateScore(set, player);
        }
    }

    return score;
}

int calculateScore(vector<unsigned int> row, unsigned int player) {
    unsigned int good = 0, bad = 0, empty = 0;
    for (unsigned int i = 0; i < row.size(); i++) {
        good += (row[i] == player) ? 1 : 0;
        bad += (row[i] == HUMAN || row[i] == AI) ? 1 : 0;
        empty += (row[i] == 0) ? 1 : 0;
    }
    bad -= good;
    return heuristicEvaluation(good, bad, empty);
}

int heuristicEvaluation(unsigned int good, unsigned int bad, unsigned int empty) {
    int score = 0;
    if (good == 4) score += 500001;
    else if (good == 3 && empty == 1) score += 5000;
    else if (good == 2 && empty == 2) score += 500;
    else if (bad == 2 && empty == 2) score -= 501;
    else if (bad == 3 && empty == 1) score -= 5001;
    else if (bad == 4) score -= 500000;
    return score;
}

bool checkWin(vector<vector<int>>& board, unsigned int player) {
    unsigned int winSequence = 0;
    for (unsigned int c = 0; c < COLS - 3; c++) {
        for (unsigned int r = 0; r < ROWS; r++) {
            for (int i = 0; i < 4; i++) {
                if (board[r][c + i] == (int)player) winSequence++;
                if (winSequence == 4) return true;
            }
            winSequence = 0;
        }
    }

    for (unsigned int c = 0; c < COLS; c++) {
        for (unsigned int r = 0; r < ROWS - 3; r++) {
            for (int i = 0; i < 4; i++) {
                if (board[r + i][c] == (int)player) winSequence++;
                if (winSequence == 4) return true;
            }
            winSequence = 0;
        }
    }

    for (unsigned int c = 0; c < COLS - 3; c++) {
        for (unsigned int r = 3; r < ROWS; r++) {
            for (int i = 0; i < 4; i++) {
                if (board[r - i][c + i] == (int)player) winSequence++;
                if (winSequence == 4) return true;
            }
            winSequence = 0;
        }
    }

    for (unsigned int c = 0; c < COLS - 3; c++) {
        for (unsigned int r = 0; r < ROWS - 3; r++) {
            for (int i = 0; i < 4; i++) {
                if (board[r + i][c + i] == (int)player) winSequence++;
                if (winSequence == 4) return true;
            }
            winSequence = 0;
        }
    }
    return false;
}

vector<vector<int>> cloneBoard(vector<vector<int>> board) {
    vector<vector<int>> newBoard(ROWS, vector<int>(COLS));
    for (unsigned int r = 0; r < ROWS; r++) {
        for (unsigned int c = 0; c < COLS; c++) {
            newBoard[r][c] = board[r][c];
        }
    }
    return newBoard;
}

void displayBoard(vector<vector<int>>& board) {
    stringstream buffer;
    cout << "\033[1;36m" << "\n 0 1 2 3 4 5 6 \n" << "\033[1;0m" << "\033[1;34m";
    for (int r = ROWS - 1; r >= 0; r--) {
        buffer << "|";
        for (unsigned int c = 0; c < COLS; c++) {
            buffer << "\033[1;33m" << (board[r][c] == 0 ? ' ' : (board[r][c] == HUMAN ? 'O' : 'X')) << "\033[1;34m|";
        }
        buffer << endl;
    }
    buffer << "\033[1;0m" << "---------------\n";
    cout << buffer.str();
}

void handleErrors(int errorCode) {
    cout << "\033[1;31m";
    switch (errorCode) {
    case 1:
        cout << "Пожалуйста, введите корректный символ.\n";
        break;
    case 2:
        cout << "Пожалуйста, введите цифру от 0 до 6\n";
        break;
    case 3:
        cout << "Столбец полон, пожалуйста, введите номер иного столбца.\n";
        break;
    }
    cout << "\033[1;0m";
}

int main() {
    setlocale(0, "");
    startGame();
}
