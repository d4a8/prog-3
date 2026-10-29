#include <iostream>
#include <cstdint>
#include <vector>
#include <chrono>

using namespace std;

bool IsSafe(vector<vector<int>>& board, int x, int y, int size)
{
    for (int i = x-1; i > -1; --i) {if (board[i][y]) return false;}
    for (int i = x-1, j = y-1; i > -1 && j > -1; --i, --j) {if (board[i][j]) return false;}
    for (int i = x-1, j = y+1; i > -1 && j < size; --i, j++) {if (board[i][j]) return false;}

    return true;
}

void InsertQueen(vector<vector<int>>& board, int x, int size, uint64_t& solutions)
{
    if (x == size)
    {
        solutions++;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (IsSafe(board, x, i, size))
        {
            board[x][i] = 1;
            InsertQueen(board, x+1, size, solutions);
            board[x][i] = 0;
        }
    }
}

int main()
{
    int n;
    cout << "Insert the size of the board (positive integer): ";
    cin >> n;

    vector<vector<int>> board(n, vector <int> (n, 0));
    uint64_t solutions = 0;

    auto start = chrono::high_resolution_clock::now();

    InsertQueen(board, 0, n, solutions);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, micro> duration = end - start;

    cout << "Number of solutions: " << solutions << '\n';
    cout << "Execution time: " << duration.count() << " microseconds";
}