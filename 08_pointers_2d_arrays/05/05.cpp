#include <iostream>

const int ROWS = 3;
const int COLS = 3;

void print_lucky_numbers(int matrix[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        int min_pos_in_row = 0;
        for (int j = 1; j < COLS; j++)
        {
            if (matrix[i][j] < matrix[i][min_pos_in_row])
            {
                min_pos_in_row = j;
            }
        }

        // min element in current row
        int min_el_row = matrix[i][min_pos_in_row];

        // find max element in the col of min element found
        int max_el_col = matrix[0][min_pos_in_row];
        for (int j = 1; j < ROWS; j++)
        {
            if (matrix[j][min_pos_in_row] > max_el_col)
            {
                max_el_col = matrix[j][min_pos_in_row];
            }
        }

        if (min_el_row == max_el_col)
        {
            std::cout << min_el_row << " ";
        }
    }
}

int main()
{
    int matrix[ROWS][COLS] = { {1, 5, 9}, {2, 8, 3}, {4, 6, 7} };

    print_lucky_numbers(matrix);
}
