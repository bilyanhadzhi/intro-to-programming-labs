#include <iostream>

const int DIM = 3;

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_col_with_row(int matrix[DIM][DIM], int col)
{
    for (int i = 0; i < DIM; i++)
    {
        swap(&matrix[i][col], &matrix[col][i]);
    }
}

void swap_all_even_cols_with_rows(int matrix[DIM][DIM])
{
    for (int i = 0; i < DIM; i += 2)
    {
        swap_col_with_row(matrix, i);
    }
}

int main()
{
    int matrix[DIM][DIM] = { {1, 2, 3}, {4,5,6}, {7,8,9} };

    swap_all_even_cols_with_rows(matrix);

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
