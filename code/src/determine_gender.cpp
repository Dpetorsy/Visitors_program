#include <iostream>
#include <string>

#include "../include/input.hpp"
#include "../include/general_functions.hpp"
#include "../include/colors.hpp"


/*
* Brief: Display gender menu
*/
void printGender(std::string arr[], int green_line, int x, int y);


std::string determine_gender(int x, int y)
{
    const std::string space4 = "    ";
    const std::string space2 = "  ";
    const int arrow_right = 67;
    const int arrow_left = 68;
    const int enter = 10;

    const int arr_size = 4;
    std::string arr[arr_size] = {space4, "Male", space2, "Female"};

    printGender(arr, 1, x, y);

    cbreak();
    while (true)
    {
        const char key = keypress();
        switch (key) {
        case arrow_right : case 'd':
            if(arr[0] == space4)
            {
                arr[0] = space2;
                arr[2] = space4;
                printGender(arr, 3, x, y);
                break;
            }
            break;
        case arrow_left : case 'a':
            if(arr[2] == space4)
            {
                arr[2] = space2; 
                arr[0] = space4; 
                printGender(arr, 1, x, y);
                break;
            }   
            break;
        case enter:
            if(arr[0] == space4)
            {
                std::cout << GREEN;
                return "Male";
            }
            else
            {
                std::cout << GREEN;
                return "Female";
            }
            break;
        }
    }
}

void printGender(std::string arr[], int green_line, int x, int y)
{
    gotoxy(x, y);
    if(green_line == 1)
    {
        std::cout << arr[0] << GREEN << arr[1] << RESET << arr[2] << "  " << arr[3] << std::endl;
    }
    else
    {
        std::cout << arr[0] << "  " << arr[1] << arr[2] << GREEN << arr[3] << RESET << std::endl;
    }
    return;
}
