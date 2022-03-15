#include <iostream>
#include <string>
#include <unistd.h>

#include "../include/general_functions.hpp"
#include "../include/colors.hpp"

void text_with_timer(const std::string text, const int x, const int y)
{
    // set timer value
    const int sleepTime = 3;

    gotoxy(x, y);
    std::cout << text << std::endl;
    const int size = text.size();

    // display timer
    std::cout << RED;
    for(int i = sleepTime; i >= 0; --i)
    {
        gotoxy(x + size + 3, y);
        std::cout << i << std::endl;
        sleep(1);
    }
    std::cout << RESET;

    return;
}
