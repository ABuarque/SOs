#ifndef RECORDHANDLER_H
#define RECORDHANDLER_H

#include "Record.h"
#include <string>

// get a recort state as csv, builds a record and returns it
Record* csvRecordParser(std::string recordStateAsCSV);

#endif
