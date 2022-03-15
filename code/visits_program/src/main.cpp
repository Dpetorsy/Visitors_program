#include <iostream>

#include "../include/general_func_visits.hpp"

int main()
{
    // turn terminal window to fullscreen
    std::cout << "\e[8;100;400t";

    visits_menu();

    return 0;
}
