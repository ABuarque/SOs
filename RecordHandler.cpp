#include "RecordHandler.h"
#include "Record.h"
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iterator>

using namespace std;

// handle spliting string process
template<typename Out>
void split(const std::string &s, char delim, Out result);

// handle spliting string process
std::vector<std::string> split(const std::string &s, char delim);

// remove substrings
void removeSubstrings(std::string& s, std::string& p);

// return how many digits has a number
int digitsOfNumber(int number);

// return 10 ** number of digits
double getRightValue(int digits);

// get a recort state as csv, builds a record and returns it
Record* csvRecordParser(std::string recordStateAsCSV);

//////////////////IMPLEMENTATION/////////////////

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

void removeSubstrings(string& s, string& p) { 
  string::size_type n = p.length();
  for (string::size_type i = s.find(p);
      i != string::npos;
      i = s.find(p))
      s.erase(i, n);
}

int digitsOfNumber(int number) {
	int digits = 0;
	while(number > 0) {
		number /= 10;
		digits++;
	}
	return digits;
}

double getRightValue(int digits) {
	return pow(10, digits);
}

Record* csvRecordParser(string recordStateAsCSV) {
	vector<string> parts = split(recordStateAsCSV, ',');
	long zipCode = stol(parts[0]);
	string placeName = parts[1];
	string state = parts[2];
	string county = parts[3];
	string pattern = "\"";
	removeSubstrings(parts[4], pattern);
	double latitude = stod(parts[4]);
    
    removeSubstrings(parts[5], pattern);
	
    int floatingPointerStringPart = 0; // to handle the first zero like 0.0654
    int digitsOfStringNumber = 0;

	if(latitude >= 0) {
		floatingPointerStringPart = parts[5].size(); 
		digitsOfStringNumber = digitsOfNumber(stod(parts[5]));
		if(floatingPointerStringPart == digitsOfStringNumber)
			latitude += stod(parts[5]) / getRightValue(digitsOfStringNumber);
		else
			latitude += stod(parts[5]) / getRightValue(digitsOfStringNumber + 1);
	} else {
		latitude = abs(latitude);
		
		floatingPointerStringPart = parts[5].size(); 
		digitsOfStringNumber = digitsOfNumber(stod(parts[5]));
		if(floatingPointerStringPart == digitsOfStringNumber)
			latitude += stod(parts[5]) / getRightValue(digitsOfStringNumber);
		else
			latitude += stod(parts[5]) / getRightValue(digitsOfStringNumber + 1);

		latitude = latitude * (-1); 
	}

	floatingPointerStringPart = 0;
    digitsOfStringNumber = 0;

	removeSubstrings(parts[6], pattern);
	double longitude = stod(parts[6]);

	removeSubstrings(parts[7], pattern);

	if(longitude >= 0) {
		floatingPointerStringPart = parts[7].size(); 
		digitsOfStringNumber = digitsOfNumber(stod(parts[7]));
		if(floatingPointerStringPart == digitsOfStringNumber)
			longitude += stod(parts[7]) / getRightValue(digitsOfStringNumber);
		else
			longitude += stod(parts[7]) / getRightValue(digitsOfStringNumber + 1);
	}
	else {
		longitude = abs(longitude);

		floatingPointerStringPart = parts[7].size(); 
		digitsOfStringNumber = digitsOfNumber(stod(parts[7]));
		if(floatingPointerStringPart == digitsOfStringNumber)
			longitude += stod(parts[7]) / getRightValue(digitsOfStringNumber);
		else
			longitude += stod(parts[7]) / getRightValue(digitsOfStringNumber + 1);

		longitude = longitude * (-1);
	}

	return new Record(zipCode, state, county, placeName, latitude, longitude);
}

