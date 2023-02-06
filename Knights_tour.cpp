
#include <bits/stdc++.h>
using namespace std;

class KnightsTour
{
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int **sol;
    int n;

public:
    KnightsTour(int n)
    {
        this->n = n;
        sol = new int*[n];
        for (int i = 0; i < n; i++)
            sol[i] = new int[n];
    }
    int isSafe(int x, int y)
    {
        return (x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1);
    }

    void printSolution()
    {
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
                cout << " " << setw(2) << sol[x][y] << " ";
            cout << endl;
        }
    }

    int solveKTUtil(int x, int y, int movei)
    {
        int k, next_x, next_y;
        if (movei == n*n)
            return 1;

        for (k = 0; k < 8; k++)
        {
            next_x = x + xMove[k];
            next_y = y + yMove[k];
            if (isSafe(next_x, next_y))
            {
                sol[next_x][next_y] = movei;
                if (solveKTUtil(next_x, next_y, movei + 1) == 1)
                    return 1;
                else

                    sol[next_x][next_y] = -1;
            }
        }
        return 0;
    }
    int solveKT()
    {
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
                sol[x][y] = -1;

        sol[0][0] = 0;

        if (solveKTUtil(0, 0, 1) == 0)
        {
            cout << "Solution does not exist";
            return 0;
        }
        else
            printSolution();

        return 1;
    }
};

int main()
{
    KnightsTour k(8);

    k.solveKT();
    return 0;
}
