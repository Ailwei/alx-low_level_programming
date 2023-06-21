#include "main.h"
#include <iostream>
/**
 */
int print_last_digit(int number)
{
	int last_digit = number % 10;  // Use modulo operator to get the remainder (last digit)
    std::cout << "Last digit: " << last_digit << std::endl;
    return last_digit;

}
