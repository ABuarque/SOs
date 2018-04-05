#ifndef SEQUENCESET_H
#define SEQUENCESET_H

#include <list>
#include "Block.h"
#include <string>
#include "Record.h"

class SequenceSet {
private:
	long recordsInCurrentBlock;
	bool isBlockListEmpty;
	long totalRecordsInsideSequenceSet;
	long recordsQuantityPerBlock;
	std::list<Block*> blockList;
	std::string fieldsName[6];

public:
	SequenceSet();
	~SequenceSet();

	void addRecord(Record* record);

	Record* queryRecordByZipCode(long zipCode);

	long getRecordsQuantityPerBlock();

	void removeRecordByZipCode(long zipCode);

	long getTotalRecordsInsideSequenceSet();

	std::string* getFieldsNames();

	std::string toString();

};

#endif
