#include <iostream>
#include <memory>
#include <cmath>
#include <ctime>
#include <iomanip>

// ������.
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

using namespace std;
using sharedDptr = shared_ptr<shared_ptr<int[]>[]>;

sharedDptr createBoard(int& row, int& col);
void printOriginBoard(sharedDptr& board, const int& row, const int& col);
void printBoard(sharedDptr& board, const int& row, const int& col);
void inputBoard(sharedDptr& board, const int& row, const int& col, int& count);
void deleteBoard(int**& board, const int& row, const int& col);

int main(void) {
    // ������.
    // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    cout << "202112711 ������" << endl;

    srand((unsigned)time(NULL));
    int row = 0, col = 0;
    int count = 0;
    sharedDptr board = createBoard(row, col);

    // printOriginBoard(board, row, col);
    // cout << "========" << endl;
    inputBoard(board, row, col, count);

    return 0;
}

sharedDptr createBoard(int& row, int& col) {
    int size;

    while (true) {
        cout << "���ӿ� ����� ī���� ������ �Է����ּ���. �ݵ�� ¦������ �մϴ�.(��: 4): ";
        cin >> size;

        if (cin.fail()) {
            cout << "�߸� �ԷµǾ����ϴ�. ¦���� �Է����ּ���." << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        } else if (size <= 0) {
            cout << "¦���� �Է��� �ּ���." << endl;
            continue;
        } else if (size % 2 == 1) {
            cout << "¦���� �Է��� �ּ���." << endl;
            continue;
        }

        // 10 �Է� => 1,2,3,4,5 �� ���� 2���� ������.
        row = static_cast<int>(sqrt(size));
        while (size % row != 0) {
            row++;
        }
        col = size / row;
        break;
    }

    sharedDptr board = make_shared<shared_ptr<int[]>[]>(row);
    for (size_t i = 0; i < row; i++) {
        board[i] = make_shared<int[]>(col);
        for (size_t j = 0; j < col; j++) {
            board[i][j] = 0;
        }
    }

    for (int i = 1; i <= size / 2; i++) {
        for (int j = 0; j < 2; j++) {
            while (true) {
                int r = rand() % row;
                int c = rand() % col;

                if (board[r][c] == 0) {
                    board[r][c] = i;
                    break;
                }
            }
        }
    }

    return board;
}

void printOriginBoard(sharedDptr& board, const int& row, const int& col) {
    cout << "    ";
    for (size_t i = 0; i < col; i++) {
        cout << left << setw(3) << i;
    }
    cout << endl << "   ";
    for (size_t i = 0; i < col; i++) {
        cout << left << setw(3) << "---";
    }
    cout << endl;
    for (size_t i = 0; i < row; i++) {
        cout << i << " | ";
        for (size_t j = 0; j < col; j++) {
            cout << left << setw(3) << board[i][j];
        }
        cout << endl;
    }
}

void printBoard(sharedDptr& board, const int& row, const int& col) {
    cout << "    ";
    for (size_t i = 0; i < col; i++) {
        cout << left << setw(3) << i;
    }
    cout << endl << "   ";
    for (size_t i = 0; i < col; i++) {
        cout << left << setw(3) << "---";
    }
    cout << endl;
    for (size_t i = 0; i < row; i++) {
        cout << i << " | ";
        for (size_t j = 0; j < col; j++) {
            if (board[i][j] < 0) {
                cout << left << setw(3) << -board[i][j];
            }
            else {
                cout << left << setw(3) << "X";
            }
        }
        cout << endl;
    }
}

void inputBoard(sharedDptr& board, const int& row, const int& col, int& count) {
    int r1, r2, c1, c2;
    // printBoard(board, row, col);
    while (true) {
        printBoard(board, row, col);
        while (true) {
            cout << "��� �� �Է�(��: 3 4): ";
            cin >> r1 >> c1;
            if (cin.fail()) {
                cout << "�߸� �ԷµǾ����ϴ�." << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            else if (r1 >= row || r1 < 0 || c1 >= col || c1 < 0) {
                cout << "������ �߸��Ǿ����ϴ�." << endl;
                continue;
            }
            else if (board[r1][c1] < 0) {
                cout << "�̹� ���� ī���Դϴ�." << endl;
                continue;
            }
            board[r1][c1] = -board[r1][c1];
            printBoard(board, row, col);
            break;
        }

        while (true) {
            cout << "�� ��° ��� �� �Է�(��: 3 4): ";
            cin >> r2 >> c2;
            if (cin.fail()) {
                cout << "�߸� �ԷµǾ����ϴ�." << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            else if (r2 >= row || r2 < 0 || c2 >= col || c2 < 0) {
                cout << "������ �߸��Ǿ����ϴ�." << endl;
                continue;
            }
            else if (board[r2][c2] < 0) {
                cout << "�̹� ������ ī���Դϴ�." << endl;
                continue;
            }
            board[r2][c2] = -board[r2][c2];
            printBoard(board, row, col);
            break;
        }

        if (board[r1][c1] == board[r2][c2]) {
            cout << "������ϴ�! " << endl;
            count += 2;
            // printBoard(board, row, col);
        }
        else {
            cout << "����ġ..." << endl;
            board[r1][c1] = -board[r1][c1];
            board[r2][c2] = -board[r2][c2];
            // printBoard(board, row, col);
        }

        if (count == row * col) {
            cout << "��� ī�带 ������ϴ�. ���� ����" << endl;
            return;
        }
        system("pause"); // window
        // system("read -n 1 -s -p \"Press any key to continue...\""); // ��
        system("cls"); // ������
        // system("clear"); // ��
    }
}

void deleteBoard(int**& board, const int& row, const int& col) {
    for (size_t i = 0; i < row; i++) {
        delete[] board[i];
    }
    delete[] board;
    board = nullptr;
}