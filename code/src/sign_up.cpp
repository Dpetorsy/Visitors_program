#include <iostream>
#include <string>
#include <fstream>

#include "../include/input.hpp"
#include "../include/general_functions.hpp"
#include "../include/colors.hpp"
#include "../include/sign_up.hpp"

const std::string space4 = "    ";
const std::string space2 = "  ";
const int arrow_up = 65;
const int arrow_down = 66;
const int arrow_right = 67;
const int arrow_left = 68; 
const int enter = 10;
const int X = 58;
const int Y = 6;

void sign_up()
{
    startOrExit();

    return;
}

void startOrExit()
{
    printReg();
    
        cbreak();
    while(true)
    {
        const char key = keypress();
        switch (key)
        {
        case arrow_right: case 'd':
            registration();
            return;
        case arrow_left: case 'a': case 'q':
            start_menu();
            return;
        }
    }
}

void printReg()
{
    system("clear");

    gotoxy(X + 10, Y - 3);
    std::cout << "SIGN UP\n";

    gotoxy(X, Y);
    std::cout << "First name" << "      " << "Last name\n";

    gotoxy(X, Y + 3);
    std::cout << "Gender:" << "    Male    " << "Female\n";

    gotoxy(X, Y + 5);
    std::cout << "Date of Birth(Day)" << "   Month   " << "Year\n";

    gotoxy(X, Y + 8);
    std::cout << "Phone:\n";

    gotoxy(X, Y + 11);
    std::cout << "Email:\n";

    gotoxy(X, Y + 14);
    std::cout << "Password:\n";

    return;
}

void registration()
{
    normal();
    std::cout << GREEN;

    std::string first_name, last_name, gender, birthday, phone, email, password; 
    int month, day, year;
    
    // user input personal data
    gotoxy(X, Y + 1);
    std::cin >> first_name;

    gotoxy(X + 16, Y + 1);
    std::cin >> last_name;

    gender = determine_gender(X + 7, Y + 3);
    normal();

    gotoxy(X, Y + 6);
    std::cin >> day;
    if(day < 10)
    {
        birthday = "0";
        birthday += std::to_string(day);
    }
    else
    {
        birthday = std::to_string(day);
    }
    birthday += ".";

    gotoxy(X + 21, Y + 6);
    std::cin >> month;
    if(month < 10)
    {
        birthday += "0";
        birthday += std::to_string(month);
    }
    else
    {
        birthday += std::to_string(month);
    }
    birthday += ".";

    gotoxy(X + 29, Y + 6);
    std::cin >> year;
    birthday += std::to_string(year);

    gotoxy(X, Y + 9);
    std::cin >> phone;

    gotoxy(X, Y + 12);
    std::cin >> email;

    cbreak();
    std::cout << RESET;
    gotoxy(X, Y + 15);
    std::cin >> password;

    std::string id;
    const int id_size = 6;
    id = generateID(id_size);

    gotoxy(X, Y + 17);
    std::cout << "Your ID is:\n";
    gotoxy(X, Y + 18);
    std::cout << GREEN << id << RESET << std::endl;

    normal();
    bool captchaComplete = false;
    captchaComplete = captcha(X, Y + 20);
    cbreak();
    
    bool confirm = false;
    if(captchaComplete)
    {
        confirm = confirmSignUpMenu();
    }
    else
    {
        startOrExit();
        return;
    }

    bool writted = false;
    int sizeI = 8;
    std::string data[8] = {first_name, last_name, gender, birthday, phone, email, password, id};
    if(confirm)
    {
        writted = writeDataInFile(data, sizeI);
    }
    else
    {
        startOrExit();
        return;
    }

    if(writted)
    {
        exit();
    }
    else
    {
        text_with_timer("Can not write your data in files, please try again.", X - 8, Y + 22);
        startOrExit();
        return;
    }

    return;
}

std::string generateID(const int size)
{
    const int l = 1;
    const int r = 9;
    std::string id = "#";

    for(int i = 0; i < size; ++i)
    {
        id += std::to_string(random_number(l, r));
    }
    return id;
}

bool confirmSignUpMenu()
{
    const int x = X + 5;
    const int y = Y + 24;
    const int sizeI = 2;
    const int sizeJ = 2;

    std::string arr[sizeI][sizeJ] = {
        {space4, "SIGN UP"},
        {space2, "CANCEL"}
    };

    printConfirm(arr, 0, x, y);

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
                printConfirm(arr, 0, x, y);
                break;
            }
            break;
        case arrow_down : case 's':
            if(arr[0][0] == space4)
            {
                arr[0][0] = space2;
                arr[1][0] = space4;
                printConfirm(arr, 1, x, y);
                break;
            }
            break;
        case arrow_right : case enter: case 'd':
            if(arr[0][0] == space4)
            {
                return true;
            }
            if(arr[1][0] == space4)
            {
                return false;
            }
            break;
        case arrow_left : case 'q': case 'a':
            return false;
        }
    }
}

void printConfirm(std::string arr[][2], const int green_line, const int x, const int y)
{
    gotoxy(x, y);
     
    if(green_line == 0)
    {
        std::cout << arr[0][0] << BG_BOLDBLUE << GREEN << arr[0][1] << RESET << std::endl;
        gotoxy(x, y + 1);
        std::cout << arr[1][0] << "  " << arr[1][1] << std::endl;
    }
    else
    {
        std::cout << arr[0][0] << "  " << BG_BLUE << arr[0][1] << RESET << std::endl;
        gotoxy(x, y + 1);
        std::cout << arr[1][0] << GREEN << arr[1][1] << RESET << std::endl;
    }
    return;
}

bool writeDataInFile(std::string data[], int sizeI)
{
    const std::string path_login = "data/login.txt";
    const std::string path_personal = "data/personal.txt";
    std::fstream login, personal;

    login.open(path_login, std::ios::out | std::ios::app);
    personal.open(path_personal, std::ios::out | std::ios::app);

    std::string border = "##############################";

    if(login.is_open() && personal.is_open())
    {
        // writes user entered data in files "login.txt" and "personal.txt"
        for(int i = 0; i < sizeI; ++i)
        {
            if(i >= 5)
            {
                login << data[i] << "\n";
            }
            personal << data[i] << "\n";
        }

        login << border << std::endl;
        personal << border << std::endl;

        gotoxy(X, Y + 22);
        std::cout << BOLDYELLOW << "Registration completed successfully\n" << RESET;
        login.close();
        personal.close();
        return true;
    }
    else
    {
        login.close();
        personal.close();
        return false;
    }
}

void exit()
{
    const int x = X + 5;
    const int y = Y + 24;
    const int sizeI = 2;
    const int sizeJ = 2;

    std::string arr[sizeI][sizeJ] = {
        {space4, "SIGN IN"},
        {space2, "BACK TO MENU"}
    };

    printExit(arr, 0, x, y);

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
                printExit(arr, 0, x, y);
                break;
            }
            break;
        case arrow_down : case 's':
            if(arr[0][0] == space4)
            {
                arr[0][0] = space2;
                arr[1][0] = space4;
                printExit(arr, 1, x, y);
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
                start_menu();
                return;
            }
            break;
        case arrow_left : case 'q': case 'a':
            start_menu();
            return;
        }
    }
}

void printExit(std::string arr[][2], int green_line, int x, int y)
{
    gotoxy(x, y);
    std::cout << "\033[J";

    if(green_line == 0)
    {
        std::cout << arr[0][0] << GREEN << arr[0][1] << RESET << std::endl;
        gotoxy(x, y + 1);
        std::cout << arr[1][0] << "  " << arr[1][1] << std::endl;
    }
    else
    {
        std::cout << arr[0][0] << "  " << arr[0][1] << std::endl;
        gotoxy(x, y + 1);
        std::cout << arr[1][0] << GREEN << arr[1][1] << RESET << std::endl;
    }

    return;
}
