#include <iostream>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool board_is_full(bool** board, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!board[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

void print_board(bool** board, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << (board[i][j] ? "x" : "-");
        }
        std::cout << "\n";
    }
}

bool can_add_rectangle(int x, int y, int rect_width, int rect_height, bool** board, const int n)
{
    const int new_x = x + rect_width;
    const int new_y = y + rect_height;

    // check still in bounds
    if (new_x > n || new_y > n)
    {
        return false;
    }

    // check area is free
    for (int i = x; i < new_x; i++)
    {
        for (int j = y; j < new_y; j++)
        {
            if (board[j][i] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

void set_rectangle(int x, int y, int rect_width, int rect_height, bool** board, const int n, bool set_as = true)
{
    const int end_x = x + rect_width;
    const int end_y = y + rect_height;

    for (int i = y; i < end_y; i++)
    {
        for (int j = x; j < end_x; j++)
        {
            board[i][j] = set_as;
        }
    }
}

bool save_first_empty_position(bool** board, int* x, int* y, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                *x = j;
                *y = i;
                return true;
            }
        }
    }

    *x = -1;
    *y = -1;
    return false;
}

bool can_order_rectangles(int* rect_w, int* rect_h, int i, const int rect_count,
    bool** board, const int n)
{
    if (i >= rect_count)
    {
        // print_board(board, n);

        if (board_is_full(board, n))
        {
            return true;
        }
    }

    // the first i-1 squares are fixed, try all possible positions for the i-th
    for (int curr = i; curr < rect_count; curr++)
    {
        swap(&rect_w[i], &rect_w[curr]);
        swap(&rect_h[i], &rect_h[curr]);

        int next_pos_x = -1;
        int next_pos_y = -1;

        if (save_first_empty_position(board, &next_pos_x, &next_pos_y, n))
        {
            if (can_add_rectangle(next_pos_x, next_pos_y, rect_w[i], rect_h[i], board, n))
            {
                set_rectangle(next_pos_x, next_pos_y, rect_w[i], rect_h[i], board, n, 1);

                if (can_order_rectangles(rect_w, rect_h, i + 1, rect_count, board, n))
                {
                    return true;
                }

                set_rectangle(next_pos_x, next_pos_y, rect_w[i], rect_h[i], board, n, 0);
            }
        }

        swap(&rect_w[i], &rect_w[curr]);
        swap(&rect_h[i], &rect_h[curr]);
    }

    return false;
}

int main()
{
    int n;
    std::cin >> n;

    bool** board = new bool* [n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    int rect_count;
    std::cin >> rect_count;

    int* rect_w = new int[rect_count];
    int* rect_h = new int[rect_count];

    for (int i = 0; i < rect_count; i++)
    {
        std::cin >> rect_w[i] >> rect_h[i];
    }

    if (can_order_rectangles(rect_w, rect_h, 0, rect_count, board, n))
    {
        // print order
        std::cout << "Order: \n";
        for (int i = 0; i < rect_count; i++)
        {
            std::cout << rect_w[i] << " " << rect_h[i] << "\n";
        }
    }
    else
    {
        std::cout << "No possible ordering\n";
    }

    // free memory
    for (int i = 0; i < n; i++)
    {
        delete[] board[i];
    }
    delete[] board;

    delete[] rect_w;
    delete[] rect_h;
}
