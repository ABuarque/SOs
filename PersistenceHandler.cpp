#include "PersistenceHandler.h"
#include "RecordHandler.h"
#include "SequenceSet.h"
#include "Record.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/** 
 * Auxiliar function that gets a record and
 * parses it's state into a csv record.
 *
 * @param a Record object
 * @return a string in csv format
 */
string recordToCSV(Record* record);

SequenceSet* bufferizeDataSet(string dataSetPath) {
	ifstream inputStream;
	inputStream.open(dataSetPath);
	SequenceSet* sequenceSet = new SequenceSet();
	if(inputStream.is_open()) {
		string line;
		while(!inputStream.eof()) {
			getline(inputStream, line);
			sequenceSet->addRecord(csvRecordParser(line));
		}
	}
	inputStream.close();
	return sequenceSet;
}

void updateDataSet(SequenceSet* sequenceSet, string dataSetPath) {

}

string doubleToString(double number) {
	
}

string recordToCSV(Record* record) {
	string csv = to_string(record->getZipCode());
	csv += "," + record->getPlaceName();
	csv += "," + record->getState();
	csv += "," + record->getCounty();
	csv += ",\"" + to_string(record->getLatitude()) + "\"";
	csv += ",\"" + to_string(record->getLongitude()) + "\"";
 	return csv;
}
