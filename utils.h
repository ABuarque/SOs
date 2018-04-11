#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
 * It parses a c like string (using char*) to 
 * a long in base 10.
 *
 * @param c like string
 * @return long in base 10
 */
long stringToLong(std::string cLikeString);

/**
 * It parses a c like string (using char*) 
 * to a floating point number
 * 
 * @param c like string
 * @retunr string as a float
 */
float stringToFloat(std::string cLikeString);

#endif
