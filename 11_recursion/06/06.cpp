#include <iostream>
#include <iomanip>

bool can_move(int n, int** board, int x, int y, int dx, int dy)
{
    int new_x = x + dx;
    int new_y = y + dy;

    if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n)
    {
        return false;
    }

    return board[new_x][new_y] == -1;
}

bool knights_tour_rec(int n, int** board, int x, int y, int curr_move)
{
    if (curr_move >= n * n)
    {
        return true;
    }

    int next_move_x[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int next_move_y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    for (int i = 0; i < 8; i++)
    {
        if (can_move(n, board, x, y, next_move_x[i], next_move_y[i]))
        {
            int next_x = x + next_move_x[i];
            int next_y = y + next_move_y[i];

            board[next_x][next_y] = curr_move;

            if (knights_tour_rec(n, board, next_x, next_y, curr_move + 1))
            {
                return true;
            }

            board[next_x][next_y] = -1;
        }
    }

    return false;
}

void knights_tour(int n)
{
    int** board = new int* [n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            board[i][j] = -1;
        }
    }

    board[0][0] = 0;
    if (knights_tour_rec(n, board, 0, 0, 1))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << std::setw(2) << board[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // free memory
    for (int i = 0; i < n; i++)
    {
        delete[] board[i];
    }

    delete[] board;
}

int main()
{
    int n;
    std::cin >> n;

    knights_tour(n);
}
