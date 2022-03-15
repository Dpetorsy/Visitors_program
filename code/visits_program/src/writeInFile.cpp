#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

#include "../../include/input.hpp"
#include "../include/general_func_visits.hpp"

/*
* Brief: Checks user entered ID in file "login.txt"
*/
bool checkUserExistence(std::string id);

const int X = 53;
const int Y = 9;

void writeInFile(std::string id)
{
    const char path_visits[] = "data/visits.txt";
    const char path_visitsTemp[] = "data/visitsTemp.txt";
    std::fstream visits, visitsTemp;
    visits.open(path_visits, std::ios::in | std::ios::out | std::ios::app);
    visitsTemp.open(path_visitsTemp, std::ios::out | std::ios::app);

    std::string lineVisits;
    std::string border = "##############################";

    if(!checkUserExistence(id))
    {
        visits.close();
        visitsTemp.close();
        remove(path_visitsTemp);
        goto exit;
    }
    else if(visits.is_open() && visitsTemp.is_open())
    {
        while(getline(visits, lineVisits))
        {
            if(lineVisits != ("#" + id))
            {
                visitsTemp << lineVisits << std::endl;
            }
            else
            {
                visitsTemp << lineVisits << std::endl;
                getline(visits, lineVisits);

                if(lineVisits == "visit")
                {
                    // write last user action in file
                    visitsTemp << "leave" << std::endl;

                    getline(visits, lineVisits);
                    // number of last line with user visits information
                    int dateLines = stoi(lineVisits);
                    visitsTemp << dateLines << std::endl;

                    for(int i = 0; i < dateLines; ++i)
                    {
                        getline(visits, lineVisits);
                        if(i == dateLines - 1)
                        {
                            // get and write system time in file
                            auto end = std::chrono::system_clock::now();
                            std::time_t end_time = std::chrono::system_clock::to_time_t(end);
                            std::string date(std::ctime(&end_time));
                            date.pop_back();
                            
                            visitsTemp << lineVisits + "   -->   " + date << std::endl;
                            
                            // writes remaining data in file                            
                            while(getline(visits, lineVisits))
                            {
                                visitsTemp << lineVisits << std::endl;
                            }

                            visits.close();
                            visitsTemp.close();
                            remove(path_visits);
                            rename(path_visitsTemp, path_visits);

                            goto exit;
                        }
                        visitsTemp << lineVisits << std::endl;
                    }
                }
                else
                {    
                    // write last user action in file
                    visitsTemp << "visit" << std::endl;

                    getline(visits, lineVisits);
                    // number of last line with user visits information
                    int dateLines = stoi(lineVisits);
                    visitsTemp << (dateLines + 1) << std::endl;

                    for(int i = 0; i < dateLines + 1; ++i)
                    {
                        getline(visits, lineVisits);
                        if(i == dateLines)
                        {
                            // get and write system time in file
                            auto end = std::chrono::system_clock::now();
                            std::time_t end_time = std::chrono::system_clock::to_time_t(end);
                            std::string date(std::ctime(&end_time));
                            date.pop_back();

                            visitsTemp << date << std::endl;
                            visitsTemp << lineVisits << std::endl;

                            // writes remaining data in file
                            while(getline(visits, lineVisits))
                            {
                                visitsTemp << lineVisits << std::endl;
                            }

                            visits.close();
                            visitsTemp.close();
                            remove(path_visits);
                            rename(path_visitsTemp, path_visits);

                            goto exit;
                        }
                        visitsTemp << lineVisits << std::endl;
                    }
                }
            }
        }

        // if first time
        visitsTemp << "#" + id << std::endl;
        visitsTemp << "visit" << std::endl;
        visitsTemp << "1" << std::endl;

        // get and write system time in file
        auto end = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        std::string date(std::ctime(&end_time));
        date.pop_back();
        visitsTemp << date << std::endl;
        visitsTemp << border << std::endl;
        
        visits.close();
        visitsTemp.close();
        remove(path_visits);
        rename(path_visitsTemp, path_visits);

        goto exit;
    }
    else
    {
        visits.close();
        visitsTemp.close();
        remove(path_visitsTemp);

        text_with_timer("Could not open files, please try again.", X, Y + 1);
        goto exit;
    }

exit:
    system("clear");
    visits_menu();
    return;
}

bool checkUserExistence(std::string id)
{
    const std::string path_login = "../data/login.txt";
    std::fstream login;
    login.open(path_login, std::ios::in);

    std::string lineLogin;
    if(login.is_open())
    {
        while(getline(login, lineLogin))
        {
            // find user id
            if(lineLogin == ("#" + id))
            {
                login.close();
                return true;
            }
        }
        login.close();
        text_with_timer("Could not find a user with this ID.", X, Y + 1);
        return false;
    }
    else
    {
        login.close();
        text_with_timer("Could not open file \"login.txt\", please try again.", X - 8, Y + 1);
        return false;
    } 
}
