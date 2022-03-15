#ifndef HOME_HPP
#define HOME_HPP

/*
* Brief: Display home menu
*/
void printHomeMenu(std::string [][2], int, int);

/*
* Brief: Display IT Support ascii art
*/
void printImage();

/*
* Brief: Control IT Support menu with keypress
*/
void itSupportMenu();

/*
* Brief: Display IT Support menu
*/
void printSupportMenu(std::string [][2], const int);

/*
* Brief: User writes a message, it's written in the file
*/
void writeMessage();


#endif   /* HOME_HPP */
