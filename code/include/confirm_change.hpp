#ifndef CONFIRM_CHANGE_HPP
#define CONFIRM_CHANGE_HPP

/*
* Brief: Control confirm menu with keypress
*/
bool confirmChangeMenu();

/*
* Brief: Display confirm menu
*/
void printConfirmChanges(std::string [][2], const int);


/*
* Brief: Write user data changes in files "login.txt" and "personal.txt"
*/
bool writeChangesInFile(std::string [], int, const int, const int);


#endif   /* CONFIRM_CHANGE_HPP */
