#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long stringToLong(char* cLikeString) {
	return strtol(cLikeString, NULL, 10);
}

float stringToFloat(char* cLikeString) {
	return strtod(cLikeString, NULL);
}
