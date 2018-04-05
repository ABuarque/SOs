#include "App.h"
#include "RecordHandler.h"
#include "Record.h"
#include "SequenceSet.h"
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
#define DATA_SET_PATH "proper_data_set.cvs"

SequenceSet* sequenceSet;

// Show header 
void showHeader();

// Show menu
void showMenu();

// retrieve data from csv file and put inside SequenceSet object
void bufferizeDataSet();

void showState();

void insertRecord();

void sequenceSetEntryPoint() {
	sequenceSet = new SequenceSet();
	bool shouldRun = true;
	while(shouldRun) {
		system("clear || cls");
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
				insertRecord();
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
				break;
			case CLOSE_APP:
				shouldRun = false;
				break;
		}
	}
	delete sequenceSet;
}

void insertRecord() {
	cout << "Type zip code: ";
	long zipCode;
	cin >> zipCode;
	cout << "Type state: ";
	string state;
	getline(cin, state);
	cout << "Type county: ";
	string county;
	getline(cin, county);
	string placeName;
	cout << "Type placeName:";
	getline(cin, placeName);
	cout << "Type latitute: ";
	double latitute;
	cin >> latitute;
	double longitude;
	cout << "Type longitude: ";
	cin >> longitude;
	sequenceSet->addRecord(new Record(zipCode, state, county, placeName, latitute, longitude));
}

void showHeader() {
	string* fieldsNames = sequenceSet->getFieldsNames();
	cout << "-----------------------" << endl;
	cout << "| Sequence set Header|" << endl;
	cout << "-----------------------" << endl;
	cout << "-> Fields per record: " << 6 << endl;
	cout << "-> Attributes names: " << endl;
	cout << "\t* "<< fieldsNames[0] << endl;
	cout << "\t* "<< fieldsNames[1] << endl;
	cout << "\t* "<< fieldsNames[2] << endl;
	cout << "\t* "<< fieldsNames[3] << endl;
	cout << "\t* "<< fieldsNames[4] << endl;
	cout << "\t* "<< fieldsNames[5] << endl;
	cout << "-> Total records inside: " << sequenceSet->getTotalRecordsInsideSequenceSet() << endl;
	cout << "-> Total records per node: " << sequenceSet->getRecordsQuantityPerBlock() << endl;
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
