#ifndef SEQUENCESET_H
#define SEQUENCESET_H

#include <list>
#include "Block.h"
#include <string>
#include "Record.h"

class SequenceSet {
private:
	long totalRecordsInsideSequenceSet;
	long recordsQuantityPerBlock;
	std::list<Block*> blockList;

public:
	SequenceSet();
	~SequenceSet();

	void addRecord(Record* record);

	Record* queryRecordByZipCode(long zipCode);

	void removeRecordByZipCode(long zipCode);

	std::string toString();

};

#endif
