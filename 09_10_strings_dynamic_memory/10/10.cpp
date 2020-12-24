#include <iostream>
#include <cstring>

const int MAX_LEN = 257;

bool is_whitespace(char ch)
{
    return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r';
}

int main()
{
    char input[MAX_LEN];
    std::cin.getline(input, MAX_LEN);

    bool reading_word = false;
    const int len = strlen(input);

    int all_chars_count = 0;
    int words_count = 0;

    int curr_word_len = 0;
    int longest_word_len = 0;

    char* longest_word_beg = nullptr;

    for (int i = 0; i < len; i++)
    {
        char curr = input[i];

        if (is_whitespace(curr))
        {
            if (reading_word)
            {
                if (curr_word_len > longest_word_len)
                {
                    longest_word_len = curr_word_len;
                    longest_word_beg = &input[i - longest_word_len];
                }
                curr_word_len = 0;
                reading_word = false;
            }
        }
        else
        {
            curr_word_len++;
            all_chars_count++;

            if (!reading_word)
            {
                words_count++;
                reading_word = true;
            }
        }
    }

    if (curr_word_len > longest_word_len)
    {
        longest_word_len = curr_word_len;
        longest_word_beg = &input[len - longest_word_len];
    }

    std::cout << "Word count: " << words_count << "\n";

    double avg = words_count == 0 ? 0 : (double)all_chars_count / words_count;
    std::cout << "Average word length: " << avg << "\n";

    std::cout << "Longest word: ";
    for (int i = 0; i < longest_word_len; i++)
    {
        std::cout << longest_word_beg[i];
    }
    std::cout << std::endl;
}
