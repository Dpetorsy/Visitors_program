#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

#include "../include/general_functions.hpp"
#include "../include/input.hpp"
#include "../include/colors.hpp"
#include "../include/confirm_change.hpp"

const int X = 63;
const int Y = 29;
int startLoginTemp;
int startPersonalTemp;

void confirm_change(std::string userDataArr[], int dataArrSize, std::string oldUsername, const int startLogin, const int startPersonal)
{
    bool completeCaptcha = false;
    completeCaptcha = captcha(X - 5, Y - 3);

    if(completeCaptcha)
    { 
        bool confirmChanges = false;
        confirmChanges = confirmChangeMenu();
        
        if(confirmChanges)
        {
            bool changesWritted = false;
            changesWritted = writeChangesInFile(userDataArr, dataArrSize, startLogin, startPersonal);

            if(changesWritted)
            {
                std::cout << BOLDYELLOW;
                text_with_timer("You have changed your data succesfully.", X - 5, Y - 1);
                home(userDataArr[0], startLoginTemp, startPersonalTemp);
            }
            else
            {
                text_with_timer("Can not write your changes in file, please try again.", X - 11, Y - 1);
                my_profile(oldUsername, startLogin, startPersonal);
                return;
            }   
        }   
        else
        {
            my_profile(oldUsername, startLogin, startPersonal);
            return;
        }
    }
    else
    {
        text_with_timer("Captcha failed, please try again.", X - 5, Y - 1);
        my_profile(oldUsername, startLogin, startPersonal);
        return;
    }
}

bool confirmChangeMenu()
{
    const std::string space4 = "    ";
    const std::string space2 = "  ";
    const int arrow_up = 65;
    const int arrow_down = 66;
    const int arrow_right = 67;
    const int arrow_left = 68;
    const int enter = 10;
    const int sizeI = 2;
    const int sizeJ = 2;

    std::string arr[sizeI][sizeJ] = {
        {space4, "CONFIRM CHANGES"},
        {space2, "CANCEL"}
    };

    printConfirmChanges(arr, 0);

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
                printConfirmChanges(arr, 0);
                break;
            }
            break;    
        case arrow_down : case 's':
            if(arr[0][0] == space4)
            {
                arr[0][0] = space2;
                arr[1][0] = space4;
                printConfirmChanges(arr, 1);
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

void printConfirmChanges(std::string arr[][2], const int green_line)
{
    int x = X;
    int y = Y + 1;

    gotoxy(x, y);
    std::cout << "\033[J";

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

bool writeChangesInFile(std::string userDataArr[], int dataArrSize, const int startLogin, const int startPersonal)
{
    const char path_login[] = "data/login.txt";
    const char path_personal[] = "data/personal.txt";
    const char path_loginTemp[] = "data/login_temp.txt";
    const char path_personalTemp[] = "data/personal_temp.txt";
    std::fstream login, personal, loginTemp, personalTemp;

    login.open(path_login, std::ios::in);
    personal.open(path_personal, std::ios::in);
    loginTemp.open(path_loginTemp, std::ios::out | std::ios::app);
    personalTemp.open(path_personalTemp, std::ios::out | std::ios::app);

    int currentLineLogin = 0;
    int currentLinePersonal = 0;
    std::string readedLineLogin;
    std::string readedLinePersonal;
    const std::string border = "##############################"; 

    if(login.is_open() && personal.is_open() && loginTemp.is_open() && personalTemp.is_open())
    {
        // writes data from file "login.txt" into file "login_temp.txt" with user changes
        int currentLineLogin = 0;
        while(getline(login, readedLineLogin))
        {
            ++currentLineLogin;
            if(currentLineLogin != startLogin)
            {
                loginTemp << readedLineLogin << std::endl;
            }
            else if (currentLineLogin == startLogin)
            {
                for(int i = 7; i < dataArrSize; ++i)
                {
                    getline(login, readedLineLogin);
                    ++currentLineLogin;

                    loginTemp << userDataArr[i] << std::endl;
                }

                loginTemp << border << std::endl;
                ++currentLineLogin;
                startLoginTemp = currentLineLogin - 4;
            }
        }

        // writes data from file "personal.txt" into file "personal_temp.txt" with user changes
        std::string birthday = "";
        int currentLinePersonal = 0;
        while(getline(personal, readedLinePersonal))
        {
            ++currentLinePersonal;
            if(currentLinePersonal != startPersonal)
            {
                personalTemp << readedLinePersonal << std::endl;
            }
            else if (currentLinePersonal == startPersonal)
            {
                for(int i = 0; i < dataArrSize; ++i)
                {
                    if(i == 3)
                    {
                        birthday += userDataArr[i] + "." + userDataArr[i + 1] + "." + userDataArr[i + 2];
                        personalTemp << birthday << std::endl;
                        i = 5;
                    }
                    else
                    {
                        personalTemp << userDataArr[i] << std::endl;
                    }

                    getline(personal, readedLinePersonal);
                    ++currentLinePersonal;
                }
                personalTemp << border << std::endl;
                ++currentLinePersonal;
                startPersonalTemp = currentLinePersonal - 9;
            }
        }
        
        login.close();
        personal.close();
        loginTemp.close();
        personalTemp.close();
       
        // remove and rename files
        std::remove(path_login);
        std::remove(path_personal);

        std::rename(path_loginTemp, path_login);
        std::rename(path_personalTemp, path_personal);

        return true;
    }
    else
    {
        login.close();
        personal.close();
        loginTemp.close();
        personalTemp.close();
        return false;
    }
}
