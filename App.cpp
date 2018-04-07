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
#define DATA_SET_PATH "proper_data_set.cvs"

#define DEBUG if(true)

SequenceSet* sequenceSet;

// Show header 
void showHeader();

// Show menu
void showMenu();

// retrieve data from csv file and put inside SequenceSet object
void bufferizeDataSet();

void showState();

string feedBackMessage;
bool shouldShowFeedBackMessage = false;

//////////////////////////APP's ToDos///////////////////
void insertRecord();
void deleteRecord();
void modifyFieldInRecord();
void displayRecord();
/////////////////////////////////////////////////////

void sequenceSetEntryPoint() {
	sequenceSet = new SequenceSet();
	bool shouldRun = true;
	while(shouldRun) {
		system("clear || cls");
		string input;
		int option;
		showHeader();
		showMenu();
		if(shouldShowFeedBackMessage) {
			cout << "| System says: " << feedBackMessage << " |" << endl;
			shouldShowFeedBackMessage = false;
		}
		cout << "Type an option >>> ";
		bool isTryingToGetInput = true;
		while(isTryingToGetInput) {
			try {
				getline(cin, input);
				option = stoi(input);
				isTryingToGetInput = false;
			} catch(...) {
				system("clear || cls");
				showHeader();
				showMenu();
				cout << "| System says: " << "Bad input!" << " |" << endl;
				cout << "Type an option >>> ";
			}
	    }

		switch(option) {
			case INSERT_RECORD:
				insertRecord();
				break;
			case DELETE_RECORD:
				deleteRecord();
				break;
			case MODIFY_FIELD_IN_RECORD:
				modifyFieldInRecord();
				break;
			case DISPLAY_SPECIFIC_FIELD:
				break;
			case DISPLAY_RECORD:
				displayRecord();
				break;
			case CLOSE_APP:
				shouldRun = false;
				break;
			default:
				shouldShowFeedBackMessage = true;
				feedBackMessage = "Invalid paramenter";
				break;
		}
	}
	delete sequenceSet;
}

void insertRecord() {
	cout << "Type zip code: ";
	long zipCode;
	cin >> zipCode;
	getchar();
	cout << "Type state: ";
	string state;
	getline(cin, state);
	cout << "Type county: ";
	string county;
	getline(cin, county);
	string placeName;
	cout << "Type place name: ";
	getline(cin, placeName);
	cout << "Type latitute: ";
	double latitute;
	cin >> latitute;
	getchar();
	double longitude;
	cout << "Type longitude: ";
	cin >> longitude;
	getchar();
	Record* givenRecord = new Record(zipCode, state, county, placeName, latitute, longitude);
	DEBUG cout << givenRecord->toString();
	sequenceSet->addRecord(givenRecord);
}

void deleteRecord() {
	if(sequenceSet->getTotalRecordsInsideSequenceSet() > 0) {
		cout << "Type record zip code: ";
		long zipCode;
		cin >> zipCode;
		getchar();
		sequenceSet->removeRecordByZipCode(zipCode); 
	} else {
		shouldShowFeedBackMessage = true;
		feedBackMessage = "There are no records inside the set.";
	}
}

void modifyFieldInRecord() {
	if(sequenceSet->getTotalRecordsInsideSequenceSet() > 0) {
		cout << "Type record zip code: ";
		long zipCode;
		cin >> zipCode;
		getchar();
		Record* recordToChange = sequenceSet->queryRecordByZipCode(zipCode);
		while(recordToChange == NULL) {
			cout << "Was not found any record with given zip code. Type it again: \n";
			cout << ">>> ";
			cin >> zipCode;
			getchar();
			recordToChange = sequenceSet->queryRecordByZipCode(zipCode);
		}
		cout << "Type what you want to change: \n";
		cout << "\t1 Place name" << endl;
		cout << "\t2 State" << endl;
		cout << "\t3 County" << endl;
		cout << "\t4 Latitute" << endl;
		cout << "\t5 Longitude" << endl;
		cout << ">>> ";
		bool isTryingToGetInput = true;
		string input;
		int option;
		while(isTryingToGetInput) {
			try {
				getline(cin, input);
				option = stoi(input);
				getchar();
				isTryingToGetInput = false;
			} catch(...) {
				cout << "Invalid input\n";
			}
	    }

	    sequenceSet->removeRecordByZipCode(zipCode);

	    switch(option) {
	    	case 1:
	    		cout << "Type new place name: ";
	    		string placeName;
	    		getline(cin, placeName);
	    		recordToChange->setPlaceName(placeName);
	    		sequenceSet->addRecord(recordToChange);
	    		break;
	    }
	} else {
		shouldShowFeedBackMessage = true;
		feedBackMessage = "There are no records inside the set.";
	}
}

void displayRecord() {
	if(sequenceSet->getTotalRecordsInsideSequenceSet() > 0) {
		cout << "Type record zip code: ";
		long zipCode;
		cin >> zipCode;
		getchar();
		Record* record = sequenceSet->queryRecordByZipCode(zipCode);
		cout << "Record resume: \n";
		cout << "\tZip code: " << record->getZipCode() << endl;
		cout << "\tPlace name: " << record->getPlaceName() << endl;
		cout << "\tState: " << record->getState() << endl;
		cout << "\tCounty: " << record->getCounty() << endl;
		cout << "\tLatitude: " << record->getLatitute() << endl;
		cout << "\tLongitude: " << record->getLongitude() << endl;
		cout << "Press any key to get back";
		string input;
		getline(cin, input);
	} else {
		shouldShowFeedBackMessage = true;
		feedBackMessage = "There are no records inside the set.";
	}
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
