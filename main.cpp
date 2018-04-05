#include <iostream>
#include "RecordHandler.h"
#include "Block.h"
#include "SequenceSet.h"
#include <fstream>
#include "RecordHandler.h"

using namespace std;

SequenceSet sequenceSet = SequenceSet();

int main() {
	int c = 0;
	ifstream inputStream;
	inputStream.open("out.csv");
	if(inputStream.is_open()) {
		string line;
		while(!inputStream.eof()) {
			getline(inputStream, line);
			sequenceSet.addRecord(csvRecordParser(line));
			//cout << c++ << endl;
			cout << csvRecordParser(line)->toString();
		}
	}

	cout << sequenceSet.toString(); 

	//cout << csvRecordParser("6350,Hanover,CT,New London,\"41,6445\",\"-72,0677\"")->toString();

	/*Block block = Block();

	Record* r1 = new Record(1, "maceio", "AL", "Brazil", 4.4, 5.5);
	Record* r2 = new Record(2, "maceio", "AL", "Brazil", 4.4, 5.5);
	Record* r3 = new Record(3, "maceio", "AL", "Brazil", 4.4, 5.5);
	Record* r4 = new Record(4, "maceio", "AL", "Brazil", 4.4, 5.5);
	Record* r5 = new Record(5, "maceio", "AL", "Brazil", 4.4, 5.5);
	Record* r6 = new Record(6, "maceio", "AL", "Brazil", 4.4, 5.5);

	/*block.addRecordToBlockSet(r1);
	block.addRecordToBlockSet(r2);
	block.addRecordToBlockSet(r3);
	block.addRecordToBlockSet(r4);
	block.addRecordToBlockSet(r5);
	block.addRecordToBlockSet(r6); */

	//cout << block.toString();
	/*
	SequenceSet sequenceSet = SequenceSet();

	sequenceSet.addRecord(r1);	
	sequenceSet.addRecord(r2);	
	sequenceSet.addRecord(r3);	
	sequenceSet.addRecord(r4);	
	sequenceSet.addRecord(r5);	
	sequenceSet.addRecord(r6);	

	cout << "total: " << sequenceSet.getTotalRecordsInsideSequenceSet() << endl;

	cout << sequenceSet.toString(); */

	return 0;	
}
