#include "Date.h"

Date::Date() {
	
}

Date::~Date() {
	
}

void Date::setDate(string d, string y, string m) {
	
	dd=d;
	yy=y;
	mm=m;
	
}

void Date::setFullDate_unordered(string f, string s) {
	fulldate_f=f;
	fulldate_s=s;
}

void Date::setFullDate_Ordered(string date) {
	fulldate_ordered=date;
}

string Date::getDay() {
	return dd;
}


string Date::getYear() {
	return yy;
}


string Date::getMonth() {
	return mm;
}

string Date::getFullDate_F() {
	return fulldate_f;
}

string Date::getFullDate_S() {
	return fulldate_s;
}

string Date::getFullDate_Ordered() {
	return fulldate_ordered;
}

