#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Date.h"
using namespace std;

class Student {
	
	public:
		Student();
		~Student();
		
		void setStudent(string num, string n, string sn);
		void setRegDate(string d, string m, string y);
		void setFullDate(string f, string s);
		void setDate_Ordered(string date);
		
		string getStudentName();
		string getStudentSname();
		string getStudentNumber();
		string getFullDate_F();
		string getFullDate_S();
		
		string getDate_Ordered();
		
	private:
		string name;
		string sname;
		string number;
		Date regdate;//Date.h class Object
};

#endif
