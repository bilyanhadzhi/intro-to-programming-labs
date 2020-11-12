#include <iostream>

int main()
{
    int num;
    std::cin >> num;

    // Обръщаме числото и запазваме колко цифри има
    int num_reverse = 0;
    int digits_count = 0;

    int num_copy = num;
    while (num_copy != 0)
    {
        num_reverse *= 10;
        num_reverse += num_copy % 10;

        num_copy /= 10;
        digits_count++;
    }

    // Позиция в числото отляво надясно
    int pos = 1;

    // digit_to_be_switched -> най-лявата цифра, която не е по-голяма/равна от всички след нея
    // pos_to_be_switched -> самата ѝ позиция, започвайки да броим от 1 отляво на входа
    // при 7266: digit_to_be_switched = 2; pos_to_be_switched = 2
    int pos_to_be_switched = -1, digit_to_be_switched = -1;

    // digit_to_go -> най-голямата цифра, гледайки след pos_to_be_switched
    // pos_to_go -> най-крайната позиция, където се среща най-голямата от останалите цифри
    // при 7266: digit_to_go = 6; pos_to_go = 4
    int pos_to_go = -1, digit_to_go = -1;

    // Вземаме най-лявата цифра, която не е на мястото си, и на коя позиция е
    while (num_reverse != 0 && pos_to_be_switched == -1)
    {
        int curr_digit = num_reverse % 10;
        int curr_max_digit = -1;
        int left_over = num_reverse;

        while (left_over != 0)
        {
            if (left_over % 10 > curr_max_digit)
            {
                curr_max_digit = left_over % 10;
            }
            left_over /= 10;
        }

        if (curr_digit != curr_max_digit)
        {
            pos_to_be_switched = pos;
            digit_to_be_switched = curr_digit;
            digit_to_go = curr_max_digit;
        }

        num_reverse /= 10;
        pos++;
    }

    // не сме намерили цифри не-на-мястото си
    if (pos_to_be_switched == -1)
    {
        std::cout << num << "\n";
        return 0;
    }

    /*
       Забележете, че спираме горния while в момента, в който намерим digit_to_be_switched.
       При 7266 (т.е. 6627 обърнато), ще сме спрели, щом сме видели 2-ката.
       num_reverse ще е станало 66 != 0.
    */

    // Остава да намерим най-крайната от позициите,
    // на които стои най-голямата цифра, която не е на мястото си.
    // Отново, при 7266: pos_to_go = 4

    while (num_reverse != 0)
    {
        if (num_reverse % 10 == digit_to_go)
        {
            pos_to_go = pos;
        }
        pos++;
        num_reverse /= 10;
    }

    int multiplier = 1;
    int result = 0;

    // Създаваме ново число, което ще е резултатът, строейки го отдясно наляво
    pos = digits_count;

    while (num != 0)
    {
        if (pos == pos_to_be_switched)
        {
            result += multiplier * digit_to_go;
        }
        else if (pos == pos_to_go)
        {
            result += multiplier * digit_to_be_switched;
        }
        else
        {
            result += multiplier * (num % 10);
        }

        multiplier *= 10;
        num /= 10;
        pos--;
    }

    std::cout << result << "\n";
}
