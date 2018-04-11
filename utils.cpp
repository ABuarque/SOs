#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

long stringToLong(std::string cLikeString) {
	char* parsedString = new char[cLikeString.size() + 1];
	strcpy(parsedString, cLikeString.c_str());
	return strtol(parsedString, NULL, 10);
}

float stringToFloat(std::string cLikeString) {
	char* parsedString = new char(cLikeString.size() + 1);
	strcpy(parsedString, cLikeString.c_str());
	return strtod(parsedString, NULL);
}
