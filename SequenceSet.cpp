#include "SequenceSet.h"
#include <list>
#include "Block.h"
#include <string>
#include "Record.h"

using namespace std;

SequenceSet::SequenceSet() {
	recordsQuantityPerBlock = 5;
	totalRecordsInsideSequenceSet = 0;
}

SequenceSet::~SequenceSet() {}

void SequenceSet::addRecord(Record* record) {
	for(list<Block*>::iterator i = blockList.begin(); i != blockList.end(); i++) {
		Block* currentBlock = (*i);
		if(currentBlock->getRecordsSizeInsideBlockSet() < recordsQuantityPerBlock) {
			currentBlock->addRecordToBlockSet(record);
			totalRecordsInsideSequenceSet++;
		}
	}	
}

Record* queryRecordByZipCode(long zipCode);

void removeRecordByZipCode(long zipCode);

string SequenceSet::toString() {
	string state = "SequenceSet {\n totalRecordsInsideSequenceSet: " + to_string(totalRecordsInsideSequenceSet);
	state += ",\n recordsQuantityPerBlock: " + to_string(recordsQuantityPerBlock) + ",\n";
	state += " blockList {\n";
	for(list<Block*>::iterator i = blockList.begin(); i != blockList.end(); i++)
		state += "\t " + (*i)->toString();
	state += "  }\n}\n";
	return state;
}
