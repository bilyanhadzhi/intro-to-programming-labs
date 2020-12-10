#include <iostream>

const int DIM = 3;

bool is_magic_square(int square[DIM][DIM])
{
    int diag_1_sum = 0;
    int diag_2_sum = 0;

    for (int i = 0; i < DIM; i++)
    {
        diag_1_sum += square[i][i];
        diag_2_sum += square[i][DIM - i - 1];
    }

    if (diag_1_sum != diag_2_sum)
    {
        return false;
    }

    int curr_row_sum = 0;
    int curr_col_sum = 0;

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            curr_row_sum += square[i][j];
            curr_col_sum += square[j][i];
        }

        if (curr_col_sum != diag_1_sum || curr_row_sum != diag_1_sum)
        {
            return false;
        }

        curr_row_sum = 0;
        curr_col_sum = 0;
    }

    return true;
}

int main()
{
    int matrix[DIM][DIM] = { {2, 7, 6}, {9, 5, 1}, {4, 6, 5} };

    int n;

    std::cout << is_magic_square(matrix) << "\n";
}
