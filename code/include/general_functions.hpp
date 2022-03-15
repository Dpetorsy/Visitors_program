#ifndef GENERAL_FUNCTIONS_HPP
#define GENERAL_FUNCTIONS_HPP


/*
* Brief: Controls start menu with keypress()
*/
void start_menu();

/*
* Brief: Call startOrExitSignIn() function for start "SIGN IN"
*/
void sign_in();

/*
* Brief: Call startOrExit() function for start "SIGN UP"
*/
void sign_up();

/*
* Brief: Controls home menu with keypress()
*/
void home(std::string, int, int);

/*
* Brief: Controls "MY PROFILE" menu with keypress()
*/
void my_profile(std::string, int, int);

/*
* Brief: Display user visits readed from file "visits.txt"
*/
void my_visits(const std::string, int, int);

/*
* Brief: Controls ">>" arrow in "EDIT PROFILE" menu with keypress()
*/
void edit_profile(std::string [], const int, const int, const int);

/*
* Brief: Call captcha(), confirmChangeMenu() and writeChangesInFile()
*/
void confirm_change(std::string [], int, std::string, const int, const int);



/*
* Brief: Controls "determine gender" menu with keypress()
*/
std::string determine_gender(int, int);

/*
* Brief: Moves the cursor to the given coordinates of X and Y.
*/
void gotoxy(int, int);

/*
* Brief: Display captcha and return bool expression
*/
bool captcha(int, int);

/*
* Brief: Returns random number from given range
*/
int random_number(int, int);

/*
* Brief: Display given text with timer in given X and Y coordinates
*/
void text_with_timer(std::string, const int, const int);


#endif   /* GENERAL_FUNCTIONS_HPP */
