#include <iostream>

#include "../include/general_functions.hpp"

int main()
{
    // turn terminal window to fullscreen
    std::cout << "\e[8;100;400t";

    start_menu();

    return 0;
}
