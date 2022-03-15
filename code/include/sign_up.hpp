#ifndef SIGN_UP_HPP
#define SIGN_UP_HPP


/*
* Brief: Controls start "SIGN UP" or exit to "START MENU" with keypress()
*/
void startOrExit();

/*
* Brief: Display registration menu
*/
void printReg();

/*
* Brief: Get user entered data and call captcha()
*/
void registration();

/*
* Brief: Generates ID for user and return it
*/
std::string generateID(int);

/*
* Brief: Controls "SIGN UP" confirm menu with keypress()
*/
bool confirmSignUpMenu();

/*
* Brief: Display "SIGN UP" confirm menu
*/
void printConfirm(std::string [][2], int, int, int);

/*
* Brief: Writes user entered data in files "login.txt" and "personal.txt"
*/
bool writeDataInFile(std::string [], int);

/*
* Brief: Controls exit menu with keypress()
*/
void exit();

/*
* Brief: Display exit menu
*/
void printExit(std::string [][2], int, int, int);


#endif   /* SIGN_UP_HPP */
