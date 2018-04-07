#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <iostream>
#include <cstdlib>

class Record {
private:
    long zipCode;
    std::string state;
    std::string county;
    std::string placeName;
    double latitude;
    double longitude;

public:
	Record(long zipCode, std::string state, std::string county, 
		std::string placeName, double latitude, double longitude);
    Record();
    ~Record();

    long getZipCode();

    void setZipCode(long zipCode);

    std::string getState();

    void setState(std::string state);

    std::string getCounty();

    void setCounty(std::string county);

    std::string getPlaceName();

    void setPlaceName(std::string placeName);

    double getLatitute();

    void setLatitude(double latitude);

    double getLongitude();

    void setLongigute(double longigute);

    std::string toString();
};

#endif

