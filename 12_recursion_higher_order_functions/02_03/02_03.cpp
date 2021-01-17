#include <iostream>

// Зад. 2:
// Дадени с 4 туби и n литра вода. Да се намери по колко начини
// може да се разпредели водата в тубите, ако във всяка една туба
// трябва да има поне 1л вода, като във всяка туба има <= литри от миналата

// Зад. 3:
// Дадени са m туби с неограничен обем и n литра вода.
// Да се намери по колко начини може водата да се разпредели по тубите.

bool tubes_are_valid(int* tubes, const int tubes_count)
{
    for (int i = 0; i < tubes_count - 1; i++)
    {
        if (tubes[i] < tubes[i + 1])
        {
            return false;
        }
    }

    return true;
}

int ways(int* tubes, const int litres, int& result, int index = 0)
{
    if (litres == 0)
    {
        return 0;
    }

    int curr_litres = 0;
    for (int i = 0; i < 4; i++)
    {
        curr_litres += tubes[i];
    }

    if (curr_litres == litres && tubes_are_valid(tubes, 4))
    {
        result++;

        for (int i = 0; i < 4; i++)
        {
            std::cout << tubes[i] << " ";
        }
        std::cout << "\n";
    }

    if (index >= 4)
    {
        return 0;
    }

    for (int i = 1; i <= litres - 3; i++)
    {
        tubes[index] = i;
        ways(tubes, litres, result, index + 1);
    }

    return result;
}

// Зад. 3
void ways_supertubes(int* tubes, const int tubes_count,
    const int litres, int& result, int index = 0)
{
    if (litres == 0)
    {
        return;
    }

    int curr_litres = 0;
    for (int i = 0; i < tubes_count; i++)
    {
        curr_litres += tubes[i];
    }

    if (curr_litres == litres)
    {
        result++;

        for (int i = 0; i < tubes_count; i++)
        {
            std::cout << tubes[i] << " ";
        }
        std::cout << "\n";
    }

    if (index >= tubes_count)
    {
        return;
    }

    for (int i = 0; i <= litres; i++)
    {
        tubes[index] = i;
        ways_supertubes(tubes, tubes_count, litres, result, index + 1);
    }
}

int main()
{
    int tubes[100] = {};
    int result = 0;

    int litres;
    std::cin >> litres;

    int tubes_count;
    std::cin >> tubes_count;

    //std::cout << ways(tubes, litres, result) << "\n";

    ways_supertubes(tubes, tubes_count, litres, result);
    std::cout << result << "\n";
}
