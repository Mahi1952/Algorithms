#include <bits/stdc++.h>
using namespace std;
class Queen
{
    int n;
    bool *slashCode;
    bool *backslashCode;
    bool **board;
    bool *cols;

public:
    Queen(int n)
    {
        this->n = n;
        cols = new bool[n];
        slashCode = new bool[2 * n - 1];
        backslashCode = new bool[2 * n - 1];
        board = new bool *[n];

        for (int i = 0; i < n; i++)
            board[i] = new bool[n];
        for (int i = 0; i < n; i++)
        {
            cols[i] = false;
            for (int j = 0; j < n; j++)
                board[i][j] = false;
        }

        for (int i = 0; i < (2 * n - 1); i++)
        {
            slashCode[i] = false;
            backslashCode[i] = false;
        }
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d ", board[i][j]);
            cout << endl;
        }
        cout << "---------------------" << endl;
        ;
    }

    void solveUtil(int row = 0)
    {
        if (row == n)
        {
            print();
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (!cols[col] and !slashCode[row + col] and !backslashCode[row - col + n - 1])
            {
                board[row][col] = true;

                cols[col] = true;
                slashCode[row + col] = true;
                backslashCode[row - col + n - 1] = true;

                solveUtil(row + 1);
                // if(row==n-1)
                // break;

                board[row][col] = false;

                cols[col] = false;
                slashCode[row + col] = false;
                backslashCode[row - col + n - 1] = false;
            }
        }
    }
    void place()
    {
        solveUtil();
    }
};

int main()
{
    int n=(cin>>(cout<<"Enter board size  : ",n),n);

    Queen nQueen(n);
    nQueen.place();

    return 0;
}