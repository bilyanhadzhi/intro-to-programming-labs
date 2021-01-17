#include <iostream>

void apply_to_matrix(int matrix[2][2], const int rows, const int cols, int curr_row,
    int (*f)(int), int (*g)(int))
{
    if (curr_row >= rows)
    {
        return;
    }

    if (curr_row % 2 == 0)
    {
        for (int i = 0; i < cols; i++)
        {
            matrix[curr_row][i] = f(matrix[curr_row][i]);
        }
    }
    else
    {
        for (int i = 0; i < cols; i++)
        {
            matrix[curr_row][i] = g(matrix[curr_row][i]);
        }
    }

    apply_to_matrix(matrix, rows, cols, curr_row + 1, f, g);
}

int multiply_by_two(int x)
{
    return x * 2;
}

int subtract_one(int x)
{
    return x - 1;
}

int main()
{
    const int ROWS = 3;
    const int COLS = 2;

    int matrix[ROWS][COLS] = { {2,3}, {4,5}, {8, 9} };

    apply_to_matrix(matrix, ROWS, COLS, 0, multiply_by_two, subtract_one);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
