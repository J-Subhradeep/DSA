#include <bits/stdc++.h>
using namespace std;
bool is_valid(vector<vector<char>> board, int row, int col, char c)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[row][i] == c)
            return false;
        if (board[i][col] == c)
            return false;
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}
bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {

                    if (is_valid(board, i, j, c))
                    {
                        board[i][j] = c;
                        if (solve(board))
                        {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    vector<vector<char>> board{
        {'7', '.', '4', '8', '.', '.', '.', '5', '.'},
        {'.', '6', '1', '.', '.', '.', '.', '8', '3'},
        {'.', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '.', '.', '3', '.', '1', '.', '4'},
        {'.', '5', '6', '2', '4', '8', '7', '.', '9'},
        {'4', '3', '9', '1', '.', '6', '5', '.', '8'},
        {'.', '.', '.', '6', '.', '7', '.', '.', '5'},
        {'.', '7', '.', '.', '.', '.', '.', '4', '.'},
        {'6', '.', '3', '.', '5', '2', '.', '.', '.'},

    };
    solve(board);
    for (auto &&i : board)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
