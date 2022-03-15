#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

#include "../include/general_functions.hpp"
#include "../include/input.hpp"
#include "../include/colors.hpp"
#include "../include/home.hpp"

const std::string space4 = "    ";
const std::string space2 = "  ";
const int arrow_up = 65;
const int arrow_down = 66;
const int arrow_right = 67;
const int arrow_left = 68;
const int enter = 10;
const int X = 63;
const int Y = 8;
std::string Username;
int startLog;
int startPer;

void home(const std::string first_name, int userDataStartLogin, int userDataStartPersonal)
{
    Username = first_name;
    startLog = userDataStartLogin;
    startPer = userDataStartPersonal;

    system("clear");

    gotoxy(X + 6, Y - 5);
    std::cout << "HOME\n";

    const int sizeOfUsername = Username.size();
    gotoxy(X - 14 - sizeOfUsername/2, Y - 3);
    std::cout << "Hello " << Username << ". Please choose an option you want to do\n";

    const int sizeI = 5;
    const int sizeJ = 2;

    std::string arr[sizeI][sizeJ] = {
        {space4, "MY PROFILE"},
        {space2, "MY VISITS"},
        {space2, "IT SUPPORT"},
        {space2, "BACK TO MENU"},
        {space2, "EXIT"}
    };

    printHomeMenu(arr, sizeI, 0);
    
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
                printHomeMenu(arr, sizeI, 0);
                break;
            }
            else if(arr[2][0] == space4)
            {
                arr[2][0] = space2;
                arr[1][0] = space4;
                printHomeMenu(arr, sizeI, 1);
                break;
            }
            else if(arr[3][0] == space4)
            {
                arr[3][0] = space2;
                arr[2][0] = space4;
                printHomeMenu(arr, sizeI, 2);
                break;
            }
            else if(arr[4][0] == space4)
            {
                arr[4][0] = space2;
                arr[3][0] = space4;
                printHomeMenu(arr, sizeI, 3);
                break;
            }
            break;
        case arrow_down : case 's': 
            if(arr[0][0] == space4)
            {
                arr[0][0] = space2;
                arr[1][0] = space4;
                printHomeMenu(arr, sizeI, 1);
                break;
            }
            else if(arr[1][0] == space4)
            {
                arr[1][0] = space2;
                arr[2][0] = space4;
                printHomeMenu(arr, sizeI, 2);
                break;
            }
            else if(arr[2][0] == space4)
            {
                arr[2][0] = space2;
                arr[3][0] = space4;
                printHomeMenu(arr, sizeI, 3);
                break;
            }
            else if(arr[3][0] == space4)
            {
                arr[3][0] = space2;
                arr[4][0] = space4;
                printHomeMenu(arr, sizeI, 4);
                break;
            }
            break;
        case arrow_right : case enter: case 'd':
            if(arr[0][0] == space4)
            {
                my_profile(Username, startLog, startPer);
                return;
            }
            else if(arr[1][0] == space4)
            {
                my_visits(Username, startLog, startPer);
                return;
            }
            else if(arr[2][0] == space4)
            {
                itSupportMenu();
                return;
            }
            else if(arr[3][0] == space4)
            {
                start_menu();
                return;
            }
            else if(arr[3][0] == space4)
            {
                std::cout << "Quitting. By " << Username << ".\n";
                normal();
                return;
            }
            break;
        case arrow_left : case 'q': case 'a':
            sign_in();
            return;
        }
    }
}

void printHomeMenu(std::string arr[][2], const int sizeI, const int greenLine)
{
    gotoxy(0, Y);
    std::cout << "\033[J";

    printImage();

    int y = Y;
    for(int i = 0; i < sizeI; ++i)
    { 
        if(i == greenLine)
        {
            gotoxy(X, y);
            std::cout << arr[i][0] << GREEN << arr[i][1] << RESET << std::endl;
        }
        else
        {
            gotoxy(X, y);
            std::cout << arr[i][0] << "  " << arr[i][1] << std::endl;
        }
        ++y;
    }
    return;
}

void printImage()
{
    int x = X + 57;
    int y = Y + 16;

    std::cout << BOLDCYAN;
    gotoxy(x, y);
    std::cout << "      .:::.      \n";
    gotoxy(x, ++y);
    std::cout << "    -+:::::+-    \n";
    gotoxy(x, ++y);
    std::cout << "   :%:::::.:%:   \n";
    gotoxy(x, ++y);
    std::cout << "   ==       ==   \n";
    gotoxy(x, ++y);
    std::cout << "    =   o-::=    \n";
    gotoxy(x, ++y);
    std::cout << "     %-...-%     \n";
    gotoxy(x, ++y);
    std::cout << "  ,...-:::-...,  \n";
    gotoxy(x, ++y);
    std::cout << " /:     ;     :\\ \n";
    gotoxy(x, ++y);
    std::cout << ":::.....:.....:::\n";
    std::cout << RESET;

    return;
}

void itSupportMenu()
{
    const int sizeI = 2;
    const int sizeJ = 2;

    std::string arr[sizeI][sizeJ] = {
        {space4, "WRITE MESSAGE"},
        {space2, "BACK TO HOME"}
    };

    printSupportMenu(arr, 0);

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
                printSupportMenu(arr, 0);
                break;
            }
            break;
        case arrow_down : case 's':
            if(arr[0][0] == space4)
            {
                arr[0][0] = space2;
                arr[1][0] = space4;
                printSupportMenu(arr, 1);
                break;
            }
            break;
        case arrow_right : case enter: case 'd':
            if(arr[0][0] == space4)
            {
                writeMessage();
                return;
            }
            if(arr[1][0] == space4)
            {
                home(Username, startLog, startPer);
                return;
            }
            break;
        case arrow_left : case 'q': case 'a':
            home(Username, startLog, startPer);
            return;
        }
    }
}

void printSupportMenu(std::string arr[][2], const int green_line)
{
    int x = X + 40; 
    int y = Y + 18;

    gotoxy(x, y);

    if(green_line == 0)
    {
        std::cout << arr[0][0] << GREEN << arr[0][1] << RESET << std::endl;
        gotoxy(x, y + 1);
        std::cout << arr[1][0] << "  " << arr[1][1] << std::endl;
    }
    else
    {
        std::cout << arr[0][0] << "  " << arr[0][1] << RESET << std::endl;
        gotoxy(x, y + 1);
        std::cout << arr[1][0] << GREEN << arr[1][1] << RESET << std::endl;
    }
    return;
}

void writeMessage()
{ 
    const std::string path_messages = "data/messages.txt";
    std::fstream messages;
    messages.open(path_messages, std::ios::out | std::ios::app);
    std::string border = "############################";
    system("clear");

    if(messages.is_open())
    {
        gotoxy(X, Y - 5);
        std::cout << BOLDYELLOW << "Your message." << RESET << std::endl;
        
        // get and write user message in file "messages.txt"
        normal();
        gotoxy(0, Y - 3);
        std::string userMessage;
        std::cin.ignore();
        std::getline(std::cin, userMessage);
        messages << Username << std::endl;
        messages << userMessage << std::endl;
        messages << border << std::endl;
        cbreak();

        std::cout << BOLDYELLOW;
        text_with_timer("Your message was sent successfully. Return to home in", X - 18, Y);
        std::cout << RESET;
        messages.close();
        home(Username, startLog, startPer);
        return;
    }
    else
    {
        text_with_timer("Can not open file \"messages.txt\" .Return to home in", X - 18, Y - 5);
        messages.close();
        home(Username, startLog, startPer);
        return;
    }
}
