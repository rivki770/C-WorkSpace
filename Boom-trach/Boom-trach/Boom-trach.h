#ifndef _BOOMTRACH
#define _BOOMTRACH

#include <stdio.h>

/**
* @file
* The game Boom-Trach.
* The program get number from the user, and print all the number from 1 to input.
* The print by roles.
*/

/**
* @brief define number of BOOM 
*/
#define BOOM 3
/**
* @brief define number of TRACH
*/
#define TRACH 5

/**
* @brief The function receives 1 number and print the number according rols.
* @param choiceNumber is the input number from a user.
* @see Move_digits(size_t choiceNumber).
*/
void boomTrach(size_t choiceNumber);

/**
* @brief The inner function receives 1 from boomTrach function  and print the number according rols..
* @param choiceNumber is the input number from a user..
* @return Multiply by a numbers
*/
void Move_digits(size_t choiceNumber);

#endif // !_BOOMTRACH
