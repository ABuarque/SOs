#include "Block.h"
#include <set>
#include <algorithm> 
#include <string>

using namespace std;

////////////////////////////////////////////////

long zipCodeToFind = 0;

bool onSearchUtil(Record* record) {
	return record->getZipCode() == zipCodeToFind;
}
///////////////////////////////////////////////

Block::Block() {
	quantity = 0;
}

Block::~Block() {}

Record* Block::findRecordByZipCode(long zipCode) {
	zipCodeToFind = zipCode;
	set<Record*>::iterator recordsIterator 
				= std::find_if(recordsSet.begin(), recordsSet.end(), onSearchUtil);	
	if(recordsIterator != recordsSet.end())
		return (*recordsIterator);
	return NULL;
}

void Block::addRecordToBlockSet(Record* record) {
	recordsSet.insert(record);
	quantity++;
}

void Block::removeRecordFromBlockSet(Record* record) {
	recordsSet.erase(record);
	quantity--;
}

void Block::removeRecordFromBlockByZipCode(long zipCode) {
	recordsSet.erase(findRecordByZipCode(zipCode));
	quantity--;
}

long Block::getRecordsSizeInsideBlockSet() {
	return quantity;
}

string Block::toString() {
	string blockSatate = "Block {\n quantity: " + to_string(quantity) + ", \n recordsSet: \n";
	for(set<Record*>::iterator i = recordsSet.begin(); i != recordsSet.end(); i++)
		blockSatate += "\t" +(*i)->toString();
	blockSatate += " } \n";
	return blockSatate;
}
