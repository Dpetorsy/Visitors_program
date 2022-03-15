#include <iostream>
#include <string>

#include "../include/input.hpp"
#include "../include/general_functions.hpp"
#include "../include/colors.hpp"
#include "../include/start_menu.hpp"

void start_menu()
{
    const std::string space4 = "    ";
    const std::string space2 = "  ";

    const int sizeI = 3;
    const int sizeJ = 2;

    const int arrow_up = 65; 
    const int arrow_down = 66;
    const int arrow_right = 67;
    const int arrow_left = 68;
    const int enter = 10;

    std::string arr[sizeI][sizeJ] = {
        {space4, "SIGN IN"},
        {space2, "SIGN UP"},
        {space2, "EXIT"}
    };

    printStartMenu(arr, sizeI, 0);
    
    cbreak();
    while (true) 
    {
        const char key = keypress();
        switch (key) {
        case arrow_up : case 'w': 
            if(arr[1][0] == space4)
            {
                arr[1][0] = space2;
                arr[0][0] = space4;
                printStartMenu(arr, sizeI, 0);
                break;
            }
            else if(arr[2][0] == space4)
            {
                arr[2][0] = space2;
                arr[1][0] = space4;
                printStartMenu(arr, sizeI, 1);
                break;
            }
            break;
        case arrow_down : case 's': 
            if(arr[0][0] == space4)
            {
                arr[0][0] = space2;
                arr[1][0] = space4;
                printStartMenu(arr, sizeI, 1);
                break;
            }
            else if(arr[1][0] == space4)
            {
                arr[1][0] = space2;
                arr[2][0] = space4;
                printStartMenu(arr, sizeI, 2);
                break;
            }
            break;
        case arrow_right : case enter: case 'd':
            if(arr[0][0] == space4)
            {
                sign_in();
                return;
            }
            if(arr[1][0] == space4)
            {
                sign_up();
                return;
            }
            if(arr[2][0] == space4)
            {
                std::cout << "Quitting." << std::endl;
                normal();
                return;
            }
            break;
        case arrow_left : case 'q': case 'a':
            std::cout << "Quitting." << std::endl;
            normal();
            return;
        }
    }
}

void printStartMenu(std::string arr[][2], int sizeI, int green_line)
{
    system("clear");

    const int x = 64;
    int y = 7;

    gotoxy(x + 4, y - 4);
    std::cout << "WELCOME\n";

    gotoxy(x - 12, y - 2);
    std::cout << "Please choose an option you want to do\n";

    for(int i = 0; i < sizeI; ++i)
    { 
        if(i == green_line)
        {
            gotoxy(x, y);
            std::cout << arr[i][0] << GREEN << arr[i][1] << RESET << std::endl;
        }
        else
        {
            gotoxy(x, y);
            std::cout << arr[i][0] << "  " << arr[i][1] << std::endl;
        }
        ++y;
    }
    return;
}
