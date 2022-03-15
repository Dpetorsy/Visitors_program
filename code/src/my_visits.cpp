#include <iostream>
#include <fstream>
#include <string>

#include "../include/general_functions.hpp"
#include "../include/input.hpp"
#include "../include/colors.hpp"
#include "../include/my_visits.hpp" 

const int X = 58;
const int Y = 4;

void my_visits(const std::string first_name, int userDataStartLogin, int userDataStartPersonal)
{
    system("clear");
    gotoxy(X + 10, Y);
    std::cout << "MY VISITS" << std::endl;

    const char path_visits[] = "visits_program/data/visits.txt";
    std::fstream visits;
    visits.open(path_visits, std::ios::in); 

    std::string id = getId(first_name, userDataStartLogin, userDataStartPersonal);
    std::string border = "##############################";

    int y = Y;
    std::string lineVisits;
    if(visits.is_open())
    {
        while(getline(visits, lineVisits))
        {
            if(lineVisits == id)
            {
                gotoxy(X, Y + 3);
                std::cout << "Your ID:" << std::endl;
                gotoxy(X, Y + 4);
                std::cout << GREEN << id << RESET << std::endl;

                getline(visits, lineVisits);
                gotoxy(X, Y + 6);
                std::cout << "The user " << GREEN << lineVisits << RESET << " the system last time.\n";

                // display user visits from file "visits.txt"
                getline(visits, lineVisits);
                while(getline(visits, lineVisits))
                {
                    if(lineVisits != border)
                    {
                        gotoxy(X - 17, y + 9);
                        std::cout << lineVisits << std::endl;
                        ++y;
                    }
                    else
                    {
                        goto exit;
                    }
                }
            }
        }
    }
    else
    {
        visits.close();
        text_with_timer("Can not open the file \"visits.txt\".", X - 1, Y + 7);
        home(first_name, userDataStartLogin, userDataStartPersonal);        
        return;
    }

exit:
    visits.close();
    exit(first_name, userDataStartLogin, userDataStartPersonal);
}

std::string getId(const std::string first_name, const int startLog, const int startPer)
{
    const char path_login[] = "data/login.txt";
    std::fstream login;
    login.open(path_login, std::ios::in);

    std::string lineLogin;
    if(login.is_open())
    {
        int current = 0;
        while(getline(login, lineLogin))
        {
            ++current;
            if(current == startLog)
            {
                // get user ID and return it
                getline(login, lineLogin);
                getline(login, lineLogin);
                login.close();
                return lineLogin;
            }
        }
        login.close();
    }
    else
    {
        login.close();
        text_with_timer("Can not open the file \"login.txt\".", X - 1, Y + 7);
        home(first_name, startLog, startPer);
        return "#000";
    }
    return "#000";
}

void exit(std::string first_name, int userDataStartLogin, int userDataStartPersonal)
{
    const int arrow_left = 68;

    cbreak();
    while (true)
    {
        const char key = keypress();
        switch (key) {
        case arrow_left : case 'q': case 'a':
            home(first_name, userDataStartLogin, userDataStartPersonal);   
            return;
        }
    }
}
