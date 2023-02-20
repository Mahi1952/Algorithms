#include <bits/stdc++.h>
using namespace std;

bool canPlace(int mat[][9], int row, int col, int no)
{
    for (int cons = 0; cons < 9; cons++)
        if (mat[row][cons] == no or mat[cons][col] == no)
            return false;

    int s1 = (row / 3) * 3;
    int s2 = (col / 3) * 3;
    for (int i = s1; i < s1 + 3; i++)
        for (int j = s2; j < s2 + 3; j++)
            if (mat[i][j] == no)
                return false;
    return true;
}

void print(int mat[][9])
{
    cout<<":::::::::::::::::::::::::::::::::::::::::"<<endl;
    for (int i = 0; i < 9; i++)
    {
        cout << "| ";
        for (int j = 0; j < 9; j++)
            cout << mat[i][j] << " | ";
        cout << endl<<endl;;
    }
    cout <<":::::::::::::::::::::::::::::::::::::::::"<< endl
         << endl;
}

bool solve(int mat[][9], int row = 0, int col = 0)
{
    if (row == 9)
    {
        print(mat);
        return true;
    }
    if (col == 9)
        return solve(mat, row + 1);

    if (mat[row][col])
        return solve(mat, row, col + 1);

    for (int no = 1; no <= 9; no++)
        if (canPlace(mat, row, col, no))
        {
            mat[row][col] = no;
            if ((solve(mat, row, col + 1)))
                return true;
        }
    mat[row][col] = 0;
    return false;
}

int main()
{
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (!solve(grid))
        cout << "No Solution" << endl;
}
