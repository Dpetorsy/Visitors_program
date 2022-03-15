#include <iostream>
#include <string>

#include "../../include/input.hpp"
#include "../include/general_func_visits.hpp"
#include "../../include/colors.hpp"

std::string get_id()
{
    system("clear");   

    const int x = 58;
    const int y = 6;

    gotoxy(x, y);
    std::cout << "Enter your ID:" << std::endl;

    std::string id;
    normal();
    std::cout << GREEN;

    gotoxy(x, y + 1);
    std::cout << "#";
    std::cin >> id;

    cbreak();
    std::cout << RESET;

    return id;
}
