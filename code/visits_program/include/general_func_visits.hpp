#ifndef GENERAL_FUNC_VISITS_HPP
#define GENERAL_FUNC_VISITS_HPP


/*
* Brief: Controls "VISITS MENU" with keypress()
*/
void visits_menu();

/*
* Brief: Returns user entered ID
*/
std::string get_id();

/*
* Brief: Writes user "visit" or "leave" in file "visits.txt"
*/
void writeInFile(std::string);



/*
* Brief: Moves the cursor to the given coordinates of X and Y.
*/
void gotoxy(int, int);

/*
* Brief: Display given text with timer in given X and Y coordinates
*/
void text_with_timer(std::string, const int, const int);


#endif   /* GENERAL_FUNC_VISITS_HPP */
