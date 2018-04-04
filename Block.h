#ifndef BLOCK_H
#define BLOCK_H

#include "Record.h"
#include <set>
#include <string>

class Block {
private:
	long quantity;
	std::set<Record*> recordsSet;

public:
	Block();
	~Block();

	void addRecordToBlockSet(Record* record);

	void removeRecordFromBlockSet(Record* record);

	void removeRecordFromBlockByZipCode(long zipCode);

	Record* findRecordByZipCode(long zipCode);

	long getRecordsSizeInsideBlockSet();

	std::string toString();
};

#endif
