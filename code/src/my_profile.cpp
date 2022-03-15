#include <iostream>
#include <string>
#include <fstream>

#include "../include/general_functions.hpp"
#include "../include/input.hpp"
#include "../include/colors.hpp"
#include "../include/my_profile.hpp"

const int X = 58;
const int Y = 6;   
    
void my_profile(std::string first_name, int startLog, int startPer)
{
    system("clear");

    gotoxy(X + 8, Y - 3);
    std::cout << "MY PROFILE\n";

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

    gotoxy(X, Y + 17);
    std::cout << "Your ID is:\n";

    const std::string path_personal = "data/personal.txt";
    std::fstream personal;
    personal.open(path_personal, std::ios::in);

    std::string last_name, gender, birthday, phone, email, password, id;
    std::string data = "000";

    int sizeofArr = 10;
    std::string userPersonalDataArray[sizeofArr];
    userPersonalDataArray[0] = first_name;

    if(personal.is_open())
    {
        int currentLine = 0;
        while(getline(personal, data))
        {
            ++currentLine;
            if(currentLine == startPer)
            {
                // write data from file "personal.txt" into array
                getline(personal, data);
                last_name = data;
                userPersonalDataArray[1] = last_name;

                getline(personal, data);
                gender = data;
                userPersonalDataArray[2] = gender;

                getline(personal, data);
                birthday = data;
                userPersonalDataArray[3] = "";
                userPersonalDataArray[3] += birthday[0];
                userPersonalDataArray[3] += birthday[1];

                userPersonalDataArray[4] += birthday[3];
                userPersonalDataArray[4] += birthday[4];

                userPersonalDataArray[5] = "";
                userPersonalDataArray[5] += birthday[6];
                userPersonalDataArray[5] += birthday[7];
                userPersonalDataArray[5] += birthday[8];
                userPersonalDataArray[5] += birthday[9];

                getline(personal, data);
                phone = data;
                userPersonalDataArray[6] = phone;

                getline(personal, data);
                email = data;
                userPersonalDataArray[7] = email;

                getline(personal, data);
                password = data;
                userPersonalDataArray[8] = password;

                getline(personal, data);
                id = data;
                userPersonalDataArray[9] = id;

                break;
            }
        }
        if(data == "000")
        {
            personal.close();
            text_with_timer("Can not find you in file personal.txt", X, Y + 20);
            home(first_name, startLog, startPer);
            return;
        }
    }
    else
    {
        personal.close();
        text_with_timer("Can not open the file \"personal.txt\".", X, Y + 20);
        home(first_name, startLog, startPer);
        return;
    }

    // display user data in "MY PROFILE" menu
    std::cout << GREEN;
    gotoxy(X, Y + 1);
    std::cout << first_name << std::endl;
    gotoxy(X + 16, Y + 1);
    std::cout << last_name << std::endl;

    if(gender == "Male")
    {
        gotoxy(X + 11, Y + 3);
        std::cout << "Male" << std::endl;
    }
    else
    {
        gotoxy(X + 19, Y + 3);
        std::cout << "Female" << std::endl;
    }

    gotoxy(X, Y + 6);
    std::cout << birthday[0] << birthday[1] << "\n"; 
    gotoxy(X + 21, Y + 6);
    std::cout << birthday[3] << birthday[4] << "\n";
    gotoxy(X + 29, Y + 6);
    std::cout << birthday[6] << birthday[7] << birthday[8] << birthday[9] << "\n";

    gotoxy(X, Y + 9);
    std::cout << phone;

    gotoxy(X, Y + 12);
    std::cout << email;

    gotoxy(X, Y + 15);
    std::cout << password;

    gotoxy(X, Y + 18);
    std::cout << id << std::endl;
    std::cout << RESET;

    editOrExit(startLog, startPer, userPersonalDataArray, sizeofArr);

    return;
}

void editOrExit(int startLog, int startPer, std::string userDataArr[], int sizeofArr)
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
        {space4, "EDIT PROFILE"},
        {space2, "BACK TO HOME"}
    };

    printEditOrExit(arr, 0);

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
                printEditOrExit(arr, 0);
                break;
            }
            break;
                case arrow_down : case 's':
            if(arr[0][0] == space4)
            {
                arr[0][0] = space2;
                arr[1][0] = space4;
                printEditOrExit(arr, 1);
                break;
            }
            break;
        case arrow_right : case enter: case 'd':
            if(arr[0][0] == space4)
            {
                edit_profile(userDataArr, sizeofArr, startLog, startPer);
                return;
            }
            if(arr[1][0] == space4)
            {
                home(userDataArr[0], startLog, startPer);
                return;
            }
            break;
        case arrow_left : case 'q': case 'a':
            home(userDataArr[0], startLog, startPer);
            return;
        }
    }
}

void printEditOrExit(std::string arr[][2], int green_line)
{
    const int x = X + 5;
    const int y = Y + 23;
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
