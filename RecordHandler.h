#ifndef RECORDHANDLER_H
#define RECORDHANDLER_H

#include "Record.h"
#include <string>

// get a recort state as csv, builds a record and returns it
Record* csvRecordParser(std::string recordStateAsCSV);

// some records are bad formated, it cleans up data set
void cleanDataSet(std::string inputDataSet, std::string outputDataset);

#endif
