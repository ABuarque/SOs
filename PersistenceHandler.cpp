#include "PersistenceHandler.h"
#include "RecordHandler.h"
#include "SequenceSet.h"
#include "Record.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

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

