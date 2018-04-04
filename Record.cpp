#include "Record.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

Record::Record(long zipCode, string state, 
               string county, string placeName, 
               double latitute, double longitude) {
	this->zipCode = zipCode;
	this->state = state;
	this->county = county;
	this->placeName = placeName;
	this->latitute = latitute;
	this->longitude = longitude;
}

Record::Record() {
    this->zipCode = -505;
    this->state = "";
    this->county = "";
    this->placeName = "";
    this->latitute = 0;
    this->longitude = 0;    
}

Record::~Record() {}

long Record::getZipCode() {
    return zipCode;
}

void Record::setZipCode(long zipCode) {
    this->zipCode = zipCode;
}

string Record::getState() {
    return state;
}

void Record::setState(string state) {
    this->state = state;
}

string Record::getCounty() {
    return county;
}

void Record::setCounty(string county) {
    this->county = county;
}

string Record::getPlaceName() {
    return placeName;
}

void Record::setPlaceName(string placeName) {
    this->placeName = placeName;
}

double Record::getLatitute() {
    return latitute;
}

void Record::setLatitute(double latitute) {
    this->latitute = latitute;
}

double Record::getLongitude() {
    return longitude;
}

void Record::setLongigute(double longitude) {
    this->longitude = longitude;
}

string Record::toString() {
    string state = "Record: { zipCode: " + to_string(zipCode);
    state += ", state: " + this->state;
    state += ", county: " + county;
    state += ", placeName: " + placeName;
    state += ", latitute: " + to_string(latitute);
    state += ", longitude: " + to_string(longitude) + " } \n";
    return state;
}
