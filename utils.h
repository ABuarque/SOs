#ifndef UTILS_H
#define UTILS_H

/**
 * It parses a c like string (using char*) to 
 * a long in base 10.
 *
 * @param c like string
 * @return long in base 10
 */
long stringToLong(char* cLikeString);

/**
 * It parses a c like string (using char*) 
 * to a floating point number
 * 
 * @param c like string
 * @retunr string as a float
 */
float stringToFloat(char* cLikeString);

#endif
