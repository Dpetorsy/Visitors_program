#include <iostream>

#include "../include/general_functions.hpp"
#include "../include/input.hpp"
#include "../include/colors.hpp"

bool captcha(const int x, const int y)
{
    const int r = 49;
    const int l = 10;
    const int a = random_number(l, r);
    const int b = random_number(l, r);
    const int sum = a + b;
    int input = 0;

    gotoxy(x, y);
    std::cout << "Complete captcha:    " << a << " + " << b  << " =" << std::endl;

    int shiftX = 0;

    // count shiftX for gotoxy
    if(a > 9) 
    {
        ++shiftX;
    }
    if(b > 9)
    {
        ++shiftX;
    }

    // user input answer
    gotoxy(x + 30 + shiftX, y);
    normal();
    std::cout << GREEN;
    std::cin >> input;
    std::cout << RESET;
    cbreak();

    if(input == sum)
    {
        return true;
    }
    else
    {
        return false;
    }
}
