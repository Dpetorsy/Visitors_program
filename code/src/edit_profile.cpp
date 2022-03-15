#include <iostream>
#include <string>
#include <fstream>

#include "../include/general_functions.hpp"
#include "../include/input.hpp"
#include "../include/colors.hpp"
#include "../include/edit_profile.hpp"

const int X = 55;
const int Y = 7;

void edit_profile(std::string userDataArr[], const int dataArrSize, const int startLog, const int startPer)
{
    const std::string oldUsername = userDataArr[0];
   
    gotoxy(0, Y + 22);
    std::cout << "\033[J";

    const int arrow_up = 65;
    const int arrow_down = 66;
    const int arrow_right = 67;
    const int arrow_left = 68;
    const int enter = 10;
    const std::string space2 = "  ";

    std::string arrow = ">>";
    std::string currentLine = "first_name";
    int sizeofSpaceLine = 8;
    
    gotoxy(X, Y);
    std::cout << arrow << std::endl;

    // controls ">>" arrow
    cbreak();
    while (true)
    {
        const char key = keypress();
        switch (key) {
        case arrow_up : case 'w':
            if(currentLine == "first_name")
            {
                gotoxy(X, Y);
                std::cout << space2 << std::endl;

                currentLine = "password";
                gotoxy(X, Y + 14);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "last_name")
            {
                gotoxy(X + 16, Y);
                std::cout << space2 << std::endl;

                currentLine = "first_name";
                gotoxy(X, Y);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "gender")
            {
                gotoxy(X, Y + 2);
                std::cout << space2 << std::endl;

                currentLine = "last_name";
                gotoxy(X + 16, Y);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "day")
            {
                gotoxy(X, Y + 5);
                std::cout << space2 << std::endl;
  
                currentLine = "gender";
                gotoxy(X, Y + 2);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "month")
            {
                gotoxy(X + 21, Y + 5);
                std::cout << space2 << std::endl;

                currentLine = "day";
                gotoxy(X, Y + 5);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "year")
            {
                gotoxy(X + 29, Y + 5);
                std::cout << space2 << std::endl;

                currentLine = "month";
                gotoxy(X + 21, Y + 5);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "phone")
            {
                gotoxy(X, Y + 8);
                std::cout << space2 << std::endl;

                currentLine = "year";
                gotoxy(X + 29, Y + 5);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "email")
            {
                gotoxy(X, Y + 11);
                std::cout << space2 << std::endl;

                currentLine = "phone";
                gotoxy(X, Y + 8);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "password")
            {
                gotoxy(X, Y + 14);
                std::cout << space2 << std::endl;

                currentLine = "email";
                gotoxy(X, Y + 11);
                std::cout << arrow << std::endl;
                break;
            }
            break;
        case arrow_down : case 's':
            if(currentLine == "first_name")
            {
                gotoxy(X, Y);
                std::cout << space2 << std::endl;

                currentLine = "last_name";
                gotoxy(X + 16, Y);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "last_name")
            {
                gotoxy(X + 16, Y);
                std::cout << space2 << std::endl;

                currentLine = "gender";
                gotoxy(X, Y + 2);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "gender")
            {
                gotoxy(X, Y + 2);
                std::cout << space2 << std::endl;

                currentLine = "day";
                gotoxy(X, Y + 5);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "day")
            {
                gotoxy(X, Y + 5);
                std::cout << space2 << std::endl;
  
                currentLine = "month";
                gotoxy(X + 21, Y + 5);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "month")
            {
                gotoxy(X + 21, Y + 5);
                std::cout << space2 << std::endl;

                currentLine = "year";
                gotoxy(X + 29, Y + 5);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "year")
            {
                gotoxy(X + 29, Y + 5);
                std::cout << space2 << std::endl;

                currentLine = "phone";
                gotoxy(X, Y + 8);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "phone")
            {
                gotoxy(X, Y + 8);
                std::cout << space2 << std::endl;

                currentLine = "email";
                gotoxy(X, Y + 11);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "email")
            {
                gotoxy(X, Y + 11);
                std::cout << space2 << std::endl;

                currentLine = "password";
                gotoxy(X, Y + 14);
                std::cout << arrow << std::endl;
                break;
            }
            if(currentLine == "password")
            {
                gotoxy(X, Y + 14);
                std::cout << space2 << std::endl;

                currentLine = "first_name";
                gotoxy(X, Y);
                std::cout << arrow << std::endl;
                break;
            }
            break;
        case enter:
            if(currentLine == "first_name")
            {
                sizeofSpaceLine = 16;
                gotoxy(X + 3, Y);
                std::cout << spaceLine(sizeofSpaceLine) << std::endl;

                userDataArr[0] = userInputData(X + 3, Y);
                break;
            }
            if(currentLine == "last_name")
            {
                sizeofSpaceLine = 16;
                gotoxy(X + 19, Y);
                std::cout << spaceLine(sizeofSpaceLine) << std::endl;

                userDataArr[1] = userInputData(X + 19, Y);
                break;
            }
            if(currentLine == "gender")
            {
                userDataArr[2] = determine_gender(X + 10, Y + 2);
                cbreak();
                std::cout << RESET;

                break;
            }
            if(currentLine == "day")
            {
                sizeofSpaceLine = 3;
                gotoxy(X + 3, Y + 5);
                std::cout << spaceLine(sizeofSpaceLine) << std::endl;

                userDataArr[3] = userInputData(X + 3, Y + 5);
                break;
            }
            if(currentLine == "month")
            {
                sizeofSpaceLine = 3;
                gotoxy(X + 24, Y + 5);
                std::cout << spaceLine(sizeofSpaceLine) << std::endl;

                userDataArr[4] = userInputData(X + 24, Y + 5);
                break;
            }
            if(currentLine == "year")
            {
                sizeofSpaceLine = 5;
                gotoxy(X + 32, Y + 5);
                std::cout << spaceLine(sizeofSpaceLine) << std::endl;

                userDataArr[5] = userInputData(X + 32, Y + 5);
                break;
            }
            if(currentLine == "phone")
            {
                sizeofSpaceLine = 25;
                gotoxy(X + 3, Y + 8);
                std::cout << spaceLine(sizeofSpaceLine) << std::endl;

                userDataArr[6] = userInputData(X + 3, Y + 8);
                break;
            }
            if(currentLine == "email")
            {
                sizeofSpaceLine = 30;
                gotoxy(X + 3, Y + 11);
                std::cout << spaceLine(sizeofSpaceLine) << std::endl;

                userDataArr[7] = userInputData(X + 3, Y + 11);
                break;
            }
            if(currentLine == "password")
            {
                sizeofSpaceLine = 25;
                gotoxy(X + 3, Y + 14);
                std::cout << spaceLine(sizeofSpaceLine) << std::endl;

                userDataArr[8] = userInputData(X + 3, Y + 14);
                break;
            }
            break;
        case arrow_right : case 'd':
            confirm_change(userDataArr, dataArrSize, oldUsername, startLog, startPer);
            return;
        case arrow_left : case 'a': case 'q':
            my_profile(oldUsername, startLog, startPer);
            return;
        }
    }
}

std::string spaceLine(int sizeofSpaceLine)
{
    std::string line = " ";

    for(int i = 0; i < sizeofSpaceLine - 1; ++i)
    {
            line += " ";
    }

    return line;
}

std::string userInputData(int x, int y)
{
    std::string userInput;

    gotoxy(x, y);
    normal();
    std::cout << GREEN;
    
    std::cin >> userInput;

    cbreak();
    std::cout << RESET;

    return userInput;
}
