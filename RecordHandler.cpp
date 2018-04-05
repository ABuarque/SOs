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

double parseFloatingPointString(string decimalString, string floatingPointString) {
	string pattern = "\"";
	removeSubstrings(floatingPointString, pattern);
	
    int floatingPointerStringPart = 0; // to handle the first zero like 0.0654
    int digitsOfStringNumber = 0;

    removeSubstrings(decimalString, pattern);
    double properNumber = stod(decimalString);

	if(properNumber >= 0) {
		floatingPointerStringPart = floatingPointString.size(); 
		digitsOfStringNumber = digitsOfNumber(stod(floatingPointString));
		if(floatingPointerStringPart == digitsOfStringNumber)
			properNumber += stod(floatingPointString) / getRightValue(digitsOfStringNumber);
		else
			properNumber += stod(floatingPointString) / getRightValue(digitsOfStringNumber + 1);
	} else {
		properNumber = abs(properNumber);
		
		floatingPointerStringPart = floatingPointString.size(); 
		digitsOfStringNumber = digitsOfNumber(stod(floatingPointString));
		if(floatingPointerStringPart == digitsOfStringNumber)
			properNumber += stod(floatingPointString) / getRightValue(digitsOfStringNumber);
		else
			properNumber += stod(floatingPointString) / getRightValue(digitsOfStringNumber + 1);

		properNumber = properNumber * (-1); 
	}
	return properNumber;
}

Record* csvRecordParser(string recordStateAsCSV) {
	vector<string> parts = split(recordStateAsCSV, ',');
	long zipCode = stol(parts[0]);
	string placeName = parts[1];
	string state = parts[2];
	string county = parts[3];
	double latitude = parseFloatingPointString(parts[4], parts[5]);
	double longitude = parseFloatingPointString(parts[6], parts[7]);
	return new Record(zipCode, state, county, placeName, latitude, longitude);
}

void cleanDataSet(string inputDataSet, string outputDataset) {
	fstream inputStream;
	ofstream outfile;
  	outfile.open(outputDataset);
	inputStream.open(inputDataSet);
	if(inputStream.is_open()) {
		string line;
		while(!inputStream.eof()) {
			getline(inputStream, line);
			if(split(line, ',').size() == 8) {
				outfile << line << endl;
			}
		}
	}

	outfile.close();
}
