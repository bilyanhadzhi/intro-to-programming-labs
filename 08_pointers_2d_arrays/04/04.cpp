#include <iostream>

const int ROWS = 3;
const int COLS = 3;

void add(int m1[ROWS][COLS], int m2[ROWS][COLS], int m3[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

int main()
{
    int m1[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int m2[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int m3[ROWS][COLS] = {};

    add(m1, m2, m3);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            std::cout << m3[i][j] << " ";
        }
        std::cout << "\n";
    }
}
