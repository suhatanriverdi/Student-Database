#include "Student.h"
#include <string>
using namespace std;
#include "Date.h"

Student::Student() {
	
}

Student::~Student() {
	
}
//SET MOETHODS
void Student::setStudent(string num, string n, string sn) {
		
	number=num;
	name=n;
	sname=sn;
	
}

void Student::setRegDate(string d, string m, string y) {
	regdate.setDate(d, m, y);
}

void Student::setFullDate(string f, string s) {
	regdate.setFullDate_unordered(f, s);
}

void Student::setDate_Ordered(string date) {
	regdate.setFullDate_Ordered(date);
}



//GET METHODS
string Student::getStudentName() {
	return name;
}


string Student::getStudentSname() {
	return sname;
}


string Student::getStudentNumber() {
	return number;
}

string Student::getFullDate_F() {
	return regdate.getFullDate_F();
}

string Student::getFullDate_S() {
	return regdate.getFullDate_S();
}

string Student::getDate_Ordered() {
	return regdate.getFullDate_Ordered();
}
