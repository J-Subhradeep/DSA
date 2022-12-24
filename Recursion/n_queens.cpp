#include <bits/stdc++.h>
using namespace std;
bool is_valid(int row, int col, vector<vector<int>> board)
{
    int c = 0;
    for (int i = row; i >= 0; i--)
    {

        if (board[i][col])
        {
            return false;
        }
        if ((col + c) < board.size() && board[i][col + c])
        {
            return false;
        }
        if ((col - c) >= 0 && board[i][col - c])
        {
            return false;
        }
        c++;
    }
    return true;
}
void solve(vector<vector<int>> &board, int row)
{
    if (row >= board.size())
    {
        for (auto &&i : board)
        {
            for (auto &&j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < board.size(); i++)
    {
        if (is_valid(row, i, board))
        {
            board[row][i] = 1;
            solve(board, row + 1);

            board[row][i] = 0;
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> board{
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    // cout << is_valid(0, 0, board);
    solve(board, 0);
    return 0;
}
