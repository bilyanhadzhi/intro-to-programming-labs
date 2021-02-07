#include <iostream>
#include <cstring>

int get_len_of_next(const char* seq)
{
    const int len = strlen(seq);

    int new_len = 0;
    for (int i = 0; i < len - 1; i++)
    {
        if (seq[i] != seq[i + 1])
        {
            new_len += 2;
        }
    }

    new_len += 2;
    return new_len;
}

char* generate_look_and_say_rec(int level, char* curr)
{
    if (level == 1)
    {
        return curr;
    }

    const int len = strlen(curr);
    const int next_len = get_len_of_next(curr);

    char* next = new char[next_len + 1];
    int index = 0;

    char curr_ch = curr[0];
    char curr_ch_count = 1;

    for (int i = 0; i < len - 1; i++)
    {
        if (curr[i] == curr[i + 1])
        {
            curr_ch_count++;
        }
        else
        {
            next[index++] = curr_ch_count + '0';
            next[index++] = curr_ch;

            curr_ch_count = 1;
            curr_ch = curr[i + 1];
        }
    }

    next[index++] = curr_ch_count + '0';
    next[index++] = curr_ch;

    next[index] = '\0';

    delete[] curr;

    return generate_look_and_say_rec(level - 1, next);
}

// 11 ->

char* generate_look_and_say(int level)
{
    char* result = new char[2];
    strcpy_s(result, 2, "1");

    if (level < 1)
    {
        return result;
    }

    return generate_look_and_say_rec(level, result);
}

bool all_digits_are_unique_rec(int num, int mask);

bool all_digits_are_unique(int num)
{
    return all_digits_are_unique_rec(num, 0);
}

bool all_digits_are_unique_rec(int num, int mask)
{
    /*std::cout << num << " " << mask << "\n";*/

    if (num == 0)
    {
        return mask != 0;
    }

    int curr_digit = num % 10;
    int digit_place = 1 << curr_digit;

    if ((mask & digit_place) != 0)
    {
        return false;
    }

    return all_digits_are_unique_rec(num / 10, mask + digit_place);
}

int** make_copy_of_matrix(int** matrix, const int rows, const int cols)
{
    int** copy_matrix = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        copy_matrix[i] = new int[cols];

        for (int j = 0; j < cols; j++)
        {
            copy_matrix[i][j] = matrix[i][j];
        }
    }

    return copy_matrix;
}

void insertion_sort(int* arr, const int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = curr;
    }
}

void sort_matrix(int** matrix, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        insertion_sort(matrix[i], cols);
    }
}

bool matrix_contains_permutations(int** matrix, const int rows, const int cols)
{
    int** matrix_sorted = make_copy_of_matrix(matrix, rows, cols);
    sort_matrix(matrix_sorted, rows, cols);

    bool found_permutation_rows = false;
    for (int i = 0; i < rows - 1 && !found_permutation_rows; i++)
    {
        for (int j = i + 1; j < rows && !found_permutation_rows; j++)
        {
            bool found_violation = false;

            for (int k = 0; k < cols; k++)
            {
                if (matrix[i][k] != matrix[j][k])
                {
                    found_violation = true;
                    break;
                }
            }

            if (!found_violation)
            {
                found_permutation_rows = true;
            }
        }
    }

    int main_diag_sum = 0, main_diag_product = 1, main_diag_zeros = 0;
    int second_diag_sum = 0, second_diag_product = 1, second_diag_zeros = 0;

    int min_dimension = (rows < cols) ? rows : cols;

    for (int i = 0; i < min_dimension; i++)
    {
        int curr_main = matrix[i][i];
        int curr_secondary = matrix[min_dimension - i - 1][min_dimension - i - 1];

        if (curr_main != 0)
        {
            main_diag_sum += curr_main;
            main_diag_product *= curr_main;
        }
        else
        {
            main_diag_zeros++;
        }

        if (curr_secondary != 0)
        {
            second_diag_sum += curr_secondary;
            second_diag_product *= curr_secondary;
        }
        else
        {
            second_diag_zeros++;
        }
    }

    bool diagonals_are_permutations = main_diag_zeros == second_diag_zeros
        && main_diag_sum == second_diag_sum
        && main_diag_product == main_diag_product;

    for (int i = 0; i < rows; i++)
    {
        delete[] matrix_sorted[i];
    }
    delete[] matrix_sorted;

    return found_permutation_rows && diagonals_are_permutations;
}

int main()
{
    /*for (int i = 0; i < 10; i++)
    {
        char* result = generate_look_and_say(i);
        std::cout << result << "\n";

        delete[] result;
    }*/

    /*int n;
    std::cin >> n;
    bool all_unique = all_digits_are_unique_rec(n, 0);
    std::cout << all_unique << "\n";*/

    int rows, cols;
    std::cin >> rows >> cols;

    // проверка...

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }

    int matrix2[5][5];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    matrix_contains_permutations(matrix, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
