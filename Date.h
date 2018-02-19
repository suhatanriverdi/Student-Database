#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class Date
{
	public:
		Date();
		~Date();
		
		void setDate(string d, string y, string m);
		void setFullDate_unordered(string first, string second);
		void setFullDate_Ordered(string date);
		
		string getDay();
		string getYear();
		string getMonth();
		string getFullDate_F();
		string getFullDate_S();
		string getFullDate_Ordered();
		
	private:
		string dd;
		string mm;
		string yy;
		string fulldate_f;
		string fulldate_s;
		string fulldate_ordered;
};

#endif
