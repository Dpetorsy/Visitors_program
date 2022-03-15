#ifndef SIGN_IN_HPP
#define SIGN_IN_HPP


/*
* Brief: Control start "SIGN IN" or exit "START MENU" with keypress()
*/
void startOrExitSignIn();

/*
* Brief: Display "SIGN IN" menu
*/
void printSignInMenu();

/*
* Brief: Checks user entered data in files "login.txt" and "personal.txt"
*/
void dataCheck();

/*
* Brief: Finds user first name in file "personal.txt" and return it
*/
std::string getUserName(const int);


#endif   /* SIGN_IN_HPP */
