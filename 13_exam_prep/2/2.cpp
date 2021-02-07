#include <iostream>
#include <cstring>

int digits_count(int num)
{
    if (num < 10)
    {
        return 1;
    }

    return 1 + digits_count(num / 10);
}

int get_len_of_encoded(const char* text)
{
    const int text_len = strlen(text);

    int len = 0;
    int curr_len = 1;
    for (int i = 0; i < text_len - 1; i++)
    {
        if (text[i] == text[i + 1])
        {
            curr_len++;
        }
        else
        {
            len += (curr_len < 4) ? curr_len : (3 + digits_count(curr_len));
            curr_len = 1;
        }
    }

    len += (curr_len < 4) ? curr_len : (3 + digits_count(curr_len));

    return len;
}

int reverse(int num)
{
    int reverse = 0;

    while (num != 0)
    {
        reverse *= 10;
        reverse += (num % 10);

        num /= 10;
    }

    return reverse;
}

char* int_to_str(int num)
{
    int reversed = reverse(num);
    int digits_count_num = digits_count(num);

    char* str = new char[digits_count_num];
    int index = 0;

    for (int i = 0; i < digits_count_num; i++)
    {
        str[index++] = (reversed % 10) + '0';
        reversed /= 10;
    }

    str[index] = '\0';
    return str;
}

char* rle_encode(const char* text)
{
    const int len_encoded = get_len_of_encoded(text);
    const int text_len = strlen(text);

    char* encoded = new char[len_encoded + 1];

    int index = 0;
    int curr_len = 1;

    for (int i = 0; i < text_len; i++)
    {
        if (text[i] == text[i + 1])
        {
            curr_len++;
        }
        else
        {
            if (curr_len < 4)
            {
                for (int j = 0; j < curr_len; j++)
                {
                    encoded[index++] = text[i];
                }
            }
            else
            {
                int digits_of_repeating_char = digits_count(curr_len);

                encoded[index++] = '(';
                char* count_to_str = int_to_str(curr_len);

                for (int i = 0; i < digits_of_repeating_char; i++)
                {
                    encoded[index++] = count_to_str[i];
                }

                encoded[index++] = text[i];
                encoded[index++] = ')';

                delete[] count_to_str;
            }

            curr_len = 1;
        }
    }

    return encoded;
}

bool has_equal_zero_and_one_bit_count(int num, int ones = 0, int zeros = 0)
{
    if (num == 0)
    {
        return ones == zeros && zeros != 0;
    }

    if (num & 1)
    {
        return has_equal_zero_and_one_bit_count(num >> 1, ones + 1, zeros);
    }
    else
    {
        return has_equal_zero_and_one_bit_count(num >> 1, ones, zeros + 1);
    }
}

// check if two int-arrays of same size are rotations of each other
bool are_rotations_of_each_other(int* arr1, int* arr2, const int n)
{
    bool found_rotation;

    for (int i = 0; i < n; i++)
    {
        found_rotation = true;

        for (int j = i; j < n + i && found_rotation; j++)
        {
            if (arr1[j - i] != arr2[j % n])
            {
                found_rotation = false;
            }
        }

        if (found_rotation)
        {
            return true;
        }
    }

    return false;
}

bool matrix_contains_rotations(int** matrix, const int rows, const int cols)
{
    // check diagonals first
    int min_dimension = (rows < cols) ? rows : cols;

    // turn diagonals into arrays - simplifies
    // to calling our function, but uses extra memory
    int* main_diagonal = new int[min_dimension];
    int* second_diagonal = new int[min_dimension];

    // fill diagonal arrays
    for (int i = 0; i < min_dimension; i++)
    {
        main_diagonal[i] = matrix[i][i];
        second_diagonal[i] = matrix[i][min_dimension - i - 1];
    }

    bool diagonals_are_rotations = are_rotations_of_each_other(main_diagonal, second_diagonal, min_dimension);

    delete[] main_diagonal;
    delete[] second_diagonal;

    // no need to check if diagonals satisfy
    if (diagonals_are_rotations)
    {
        return true;
    }

    // check rows
    bool found_rotation = false;

    for (int i = 0; i < rows - 1 && !found_rotation; i++)
    {
        for (int j = i + 1; j < rows && !found_rotation; j++)
        {
            if (are_rotations_of_each_other(matrix[i], matrix[j], cols))
            {
                found_rotation = true;
            }
        }
    }

    // already checked for diagonals
    return found_rotation;
}

int main()
{
    // Ex. 1
    //const char* str = "аbcdddddaaaaaaabccadddd";
    //char* encoded_str = rle_encode(str);

    //std::cout << encoded_str << '\n';

    // Ex. 2
    //std::cout << has_equal_zero_and_one_bit_count(0) << "\n";
    //std::cout << has_equal_zero_and_one_bit_count(1) << "\n";
    //std::cout << has_equal_zero_and_one_bit_count(2) << "\n";
    //std::cout << has_equal_zero_and_one_bit_count(10) << "\n";
    //std::cout << has_equal_zero_and_one_bit_count(3016) << "\n";

    // Ex. 3
    int rows, cols;
    do
    {
        std::cin >> rows >> cols;
    } while (rows <= 0 || cols <= 0);

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << matrix_contains_rotations(matrix, rows, cols) << "\n";

    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}
