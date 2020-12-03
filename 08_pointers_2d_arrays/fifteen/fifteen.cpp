#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

// constants
const int DIM = 4;

// board
int board[DIM][DIM];

// prototypes
void clear();
void swap(int* a, int* b);
void init();
void draw();
bool move(int tile);
bool won();

int main()
{
    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            std::cout << "Won!\n";
            break;
        }

        // prompt for move
        std::cout << "Tile to move: ";
        int tile;
        std::cin >> tile;

        // quit if user inputs 0
        if (tile == 0)
        {
            break;
        }

        // move if possible, else report illegality
        if (!move(tile))
        {
            std::cout << "\nIllegal move.\n";
        }
    }

    return 0;
}

void clear()
{
    for (int i = 0; i < 100; i++)
    {
        std::cout << "\n";
    }
}

void swap(int* a, int* b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

void init()
{
    int num = DIM * DIM - 1;

    for (int i = 0; i < DIM; ++i)
    {
        for (int j = 0; j < DIM; ++j)
        {
            board[i][j] = num--;
        }
    }

    if ((DIM - 1) % 2 != 0)
    {
        swap(&board[DIM - 1][DIM - 3], &board[DIM - 1][DIM - 2]);
    }
}

void draw()
{
    for (int i = 0; i < DIM; ++i)
    {
        for (int j = 0; j < DIM; ++j)
        {
            if (board[i][j] == 0)
                std::cout << " _ ";
            else
                std::cout << std::setw(2) << board[i][j] << " ";
        }

        std::cout << "\n";
    }
}

bool move(int tile)
{
    // if tile is next to empty tile, switch them and return true;
    // otherwise return false
    return false;
}

bool won()
{
    // check if board is in winning configuration
    return false;
}
