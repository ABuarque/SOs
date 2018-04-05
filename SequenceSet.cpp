#include "SequenceSet.h"
#include <list>
#include "Block.h"
#include <string>
#include "Record.h"

using namespace std;

SequenceSet::SequenceSet() {
	isBlockListEmpty = true;
	recordsQuantityPerBlock = 10000;
	totalRecordsInsideSequenceSet = 0;

	recordsInCurrentBlock = 0;
}

SequenceSet::~SequenceSet() {}

long  SequenceSet::getTotalRecordsInsideSequenceSet() {
	return totalRecordsInsideSequenceSet;
}

void SequenceSet::addRecord(Record* record) {
	if(recordsInCurrentBlock == 0) 
		blockList.push_back(new Block());

	for(list<Block*>::iterator i = blockList.begin(); i != blockList.end(); i++) {
		Block* currentBlock = (*i);
		if(currentBlock->getRecordsSizeInsideBlockSet() < recordsQuantityPerBlock) {
			currentBlock->addRecordToBlockSet(record);
			totalRecordsInsideSequenceSet++;
			recordsInCurrentBlock++;
			if(recordsInCurrentBlock == recordsQuantityPerBlock)
				recordsInCurrentBlock = 0;
		} 
	}	
}

Record* queryRecordByZipCode(long zipCode);

void removeRecordByZipCode(long zipCode);

string SequenceSet::toString() {
	string state = "SequenceSet {\n totalRecordsInsideSequenceSet: " + to_string(totalRecordsInsideSequenceSet);
	state += ",\n recordsInCurrentBlock: " + to_string(recordsInCurrentBlock) + ",\n";
	state += ",\n recordsQuantityPerBlock: " + to_string(recordsQuantityPerBlock) + ",\n";
	state += " blockList {\n";
	//for(list<Block*>::iterator i = blockList.begin(); i != blockList.end(); i++)
	//	state += "\t " + (*i)->toString();
	state += "  }\n}\n";
	return state;
}
