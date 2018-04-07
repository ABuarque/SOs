#ifndef PERSISTENCEHANDLER_H
#define PERSISTENCEHANDLER_H

#include "SequenceSet.h"
#include <string>

/**
 * It gets a path for a stored SequenceSet state
 * to bufferize it, put inside a SequenceSet object
 * and returns it;
 *
 * @param path to read
 * @return SequenceSet object
 */
SequenceSet* bufferizeDataSet(std::string dataSetPath);

/**
 * It gets a SequenceSet's state and a path to a file
 * and writes it inside;
 *
 * @param SequenceSet object
 * @param path to store
 */
void updateDataSet(SequenceSet* sequenceSet, std::string dataSetPath);

#endif
