#include <iostream>
#include "RecordHandler.h"

using namespace std;

int main() {

	Record* record = csvRecordParser("1036,Hampden,MA,Hampden,\"42,0648\",\"-72,4318\"");
	cout << record->toString();
	return 0;
}
