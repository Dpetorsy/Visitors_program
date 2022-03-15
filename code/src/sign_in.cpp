#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

#include "../include/general_functions.hpp"
#include "../include/input.hpp"
#include "../include/colors.hpp"
#include "../include/sign_in.hpp" 

const int arrow_right = 67;
const int arrow_left = 68;
const int enter = 10;
const int X = 58;
const int Y = 3;

void sign_in()
{
    startOrExitSignIn();

    return;
}

void startOrExitSignIn()
{
    printSignInMenu();

    cbreak();
    while(true)
    {
        const char key = keypress();
        switch (key)
        {
        case 68: case 'a': case 'q':
            start_menu();
            return;
        case 67: case 'd':
            dataCheck();
            return;
        }
    }
}

void printSignInMenu()
{
    system("clear");

    gotoxy(X + 10, Y);
    std::cout << "SIGN IN\n";

    gotoxy(X, Y + 3);
    std::cout << "Email:\n";

    gotoxy(X, Y + 6);
    std::cout << "Password:\n";
    return;
}

void dataCheck()
{
    const std::string path_login = "data/login.txt";
    std::fstream login;
    login.open(path_login, std::ios::in); 

    std::string email, password;
    normal();
    std::cout << GREEN;
    gotoxy(X, Y + 4);
    std::cin >> email;
    std::cout << RESET;
    cbreak();

    gotoxy(X, Y + 7);
    std::cin >> password;

    std::string fileEmail, filePassword;

    if((email == "exit") && (password == "exit"))
    {
        login.close();
        startOrExitSignIn();
        return;
    }
    else if(login.is_open())
    {
        int currentLine = 0;
        while(getline(login, fileEmail))
        {
            ++currentLine;
            if(fileEmail == email)
            {
                getline(login, filePassword);

                if(filePassword == password)
                {
                    bool captchaComplete = captcha(X, Y + 9);

                    if(captchaComplete)
                    {
                        login.close();

                        // find user data start point in file "personal.txt"
                        int userDataStartPersonal = ((currentLine / 4) * 9) + 1;

                        std::string first_name = getUserName(userDataStartPersonal);
                        home(first_name, currentLine, userDataStartPersonal);
                        return;
                    }
                    else
                    {
                        login.close();
                        text_with_timer("Captcha failed, please try again.", X, Y + 12);
                        startOrExitSignIn();
                        return;
                    }
                }
                else
                {
                    login.close();
                    text_with_timer("The password or email you entered is incorrect. Please try again.", X - 15, Y + 11);
                    startOrExitSignIn(); 
                    return; 
                }
            }
        }

        login.close();
        text_with_timer("You are not registered in our system, please register.", X - 10, Y + 11);
        startOrExitSignIn();
        return;
    }
    else
    {
        login.close();
        text_with_timer("Can not open the file \"login.txt\".", X - 5, Y + 10);
        startOrExitSignIn();
        return;
    }
}

std::string getUserName(const int firstNameLine)
{
    const std::string path_personal = "data/personal.txt";
    std::fstream personal;
    personal.open(path_personal, std::ios::in);

    std::string first_name;
    if(personal.is_open())
    {
        // find user first name in file "personal.txt"
        for(int i = 0; i < firstNameLine; ++i)
        {
            getline(personal, first_name);
        }

        personal.close();
        return first_name;
    }
    else
    {
        personal.close();
        return "NAN";
    }
}
