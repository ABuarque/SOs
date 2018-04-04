#include "App.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iterator>

using namespace std;

#define INSERT_RECORD 1
#define DELETE_RECORD 2
#define MODIFY_FIELD_IN_RECORD 3
#define DISPLAY_SPECIFIC_FIELD 4
#define DISPLAY_RECORD 5
#define CLOSE_APP 6
#define SHOW_STATE 7
#define DATA_SET_PATH "data_set.cvs"

/*
// Show header 
void showHeader();

// Show menu
void showMenu();

// retrieve data from csv file and put inside SequenceSet object
void bufferizeDataSet();

void showState();

void sequenceSetEntryPoint() {
	bool shouldRun = true;
	while(shouldRun) {
		string input;
		int option;
		showHeader();
		showMenu();
		cout << "Type an option: ";
		bool isTryingToGetInput = true;
		while(isTryingToGetInput) {
			try {
				cout << ">>> ";
				getline(cin, input);
				option = stoi(input);
				isTryingToGetInput = false;
			} catch(...) {
				cout << "Bad input! Try again.\n";
			}
	    }

		switch(option) {
			case INSERT_RECORD:
				break;
			case DELETE_RECORD:
				break;
			case MODIFY_FIELD_IN_RECORD:
				break;
			case DISPLAY_SPECIFIC_FIELD:
				break;
			case DISPLAY_RECORD:
				break;
			case SHOW_STATE:
				showState();
				break;
			case CLOSE_APP:
				shouldRun = false;
				break;
		}
	}
	delete sequenceSet;
}

void showHeader() {
	Header* header = sequenceSet->getHeader();
	string* fieldsNames = header->getFieldsNames();
	cout << "-----------------------" << endl;
	cout << "| Sequence set Header|" << endl;
	cout << "-----------------------" << endl;
	cout << "-> Fields per record: " << header->getFieldsPerRecord() << endl;
	cout << "-> Attributes names: " << endl;
	cout << "\t* "<< fieldsNames[0] << endl;
	cout << "\t* "<< fieldsNames[1] << endl;
	cout << "\t* "<< fieldsNames[2] << endl;
	cout << "\t* "<< fieldsNames[3] << endl;
	cout << "\t* "<< fieldsNames[4] << endl;
	cout << "\t* "<< fieldsNames[5] << endl;
	cout << "-> Total records inside per node: " << header->getTotalRecordsInside() << endl;
	cout << endl;
}

void showMenu() {
	cout << "1. Insert a record\n";
	cout << "2. Delete a record\n";
	cout << "3. Modify a field in a record\n";
	cout << "4. Display a specific field in a record\n";
	cout << "5. Display a record\n";	
	cout << "6. Close app\n";
}

void bufferizeDataSet() {
	ifstream input;
	input.open("data_set.csv");
	if(input.is_open()) {
		string line;
		while(!input.eof()) {
			getline(input, line);
			Record* currentRecord = csvRecordParser(line);
			sequenceSet->addRecordToCurrentBlock(currentRecord);
		}
	}
	input.close();
} */
