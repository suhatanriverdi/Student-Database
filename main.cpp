#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include "Date.h"
#include "Student.h"

using namespace std;

bool datechecker(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);

int main(void) {
	
	Student arr[70];
	
	string start_date_day, end_date_day;
	string start_date_month, end_date_month;
	string start_date_year, end_date_year;
	
	string class_day, class_month, class_year;
	
	size_t pos;
	
	string getcontent, getcontent_reg, first, first_reg, second, second_reg, third, third_reg;//Class Only Members
	string input, name, surname, number, end_date, start_date, year;//Menu Only Members
	string temp;//for temporary strings
	
	int i=0;//Count for Cases
	int count=0, count_reg=0, count_class=0, count_class_reg=0, date_key=0;
	int key_else=0, key_3=0, key_4=0;
	
	int st_dt_D, end_dt_D;
	int st_dt_M, end_dt_M;
	int st_dt_Y, end_dt_Y;
	
	int class_D;
	int class_M;
	int class_Y;
	
	ifstream infile_no_name, infile_no_reg;
    infile_no_name.open ("Number-Name-Surname.txt");
	infile_no_reg.open ("Number-RegistrationDate.txt");
	
	//Saving StudentNoName.txt into Student arr[70] -> name/surname/number 
	if(infile_no_name.is_open()) {
		
		while(infile_no_name) {
			
			infile_no_name >> getcontent;
			
				if(count==0) {
					
					first = getcontent;
					//cout << first << endl;
				}
				
			
				if(count==1) {
				
					second = getcontent;
					//cout << second << endl;
				}
			
				if(count==2) {
				
					third = getcontent;
					//cout << third << endl;
					count=-1;
					
					arr[count_class].setStudent(first, second, third);
						count_class++;
				}
				
			count++;
		}
		
		//Reset Both Counters
		count_class=0;
		count=0;
	}
	
	//Saving StudentNoRegistration.txt into arr[70] Student/Date Class
	if(infile_no_reg.is_open()) {
					
		while(infile_no_reg) {
							
			infile_no_reg >> getcontent_reg;
					
				if(count_reg==0) {
								
					//StudentNo	
					first_reg = getcontent_reg;
	
				}
				
				else if(count_reg==1) {
					
					second_reg = getcontent_reg;
					
					arr[count_class].setFullDate(first_reg, second_reg);
						count_class++;
														
				count_reg=-1;
									
				count_class_reg++;
				
				}
				
				count_reg++;
		}			
	}
	
	
	//RegistDates in correct order
	for(int i=0; i<69 ; i++) {//StudentNoName Loop
			
		for(int j=0; j<69 ; j++) {//StudentNoRegisteration Loop
					
		if(  arr[i].getStudentNumber() == arr[j].getFullDate_F() ) {
			
			arr[i].setDate_Ordered( arr[j].getFullDate_S() );
			break;
			/*
			cout << arr[i].getStudentNumber() << " ";
			cout << arr[i].getStudentName() << " ";
			cout << arr[i].getStudentSname() << " ";
			cout << arr[j].getDate_Ordered() << " " << endl;*/	
			}		
		}	
	}				
	
	/*
	//Listing Correct Order
	for(int i=0; i<69 ; i++) {
		
	cout << arr[i].getStudentNumber() << " ";
	cout << arr[i].getStudentName() << " ";
	cout << arr[i].getStudentSname() << " ";
	cout << arr[i].getDate_Ordered() << " " << endl;

	}*/	
	
	//STUDENT DATABASE MENU
	cout << "		WELCOME TO STUDENT DATABASE" << endl << endl;
	
	do {
		
		key_else=1;
		key_3=1;
		key_4=1;
				
		cout << "1) Enter student name and surname to display registration date and student number" << endl;
		cout << "2) Enter student number to display registration date" << endl;	
		cout << "3) Enter a year to display all students" << endl;
		cout << "4) Enter registration date (start-date/end-date)" << endl << endl;
		cout << "-> 0 to exit: ";
	
		cin >> input; 
		cout << endl;	
		
		if(input=="1") {

			cout << "1) Enter student name and surname(name surname): " << endl;
			cin >> name >> surname;
			
			for(i=0;i<69;i++) {
				
				if( name == arr[i].getStudentName() && surname == arr[i].getStudentSname()) {
					
					cout << endl;
						
					cout << "		STUDENT FOUND!" << endl << endl;
					
					cout << "Student Name: ";
					cout << "			  " << arr[i].getStudentName() << endl;
					cout << "Student Surname: ";
					cout << "		  " <<  arr[i].getStudentSname() << endl;
					
					cout << "Student Number: ";
					cout << "		  " << arr[i].getStudentNumber() << endl;
					
					cout << "Student Registration Date is: ";
					cout << "	  " << arr[i].getDate_Ordered() << endl << endl;
					
				}	
				/*if( key_else==1 ) {
						
				cout << endl;
				cout << "		NO STUDENT(S) FOUND!" << endl << endl << endl;
					
				}*/	
			}
		}

		else if(input=="2") {
		
			cout << "2) Enter student number: " << endl;
			cin >> number;
			
			for(i=0;i<69;i++) {
				
				if( number == arr[i].getStudentNumber() ) {
					
					cout << endl;
					cout << "		STUDENT FOUND!" << endl << endl;
					
					cout << "Student Name: ";
					cout << "			  " << arr[i].getStudentName() << endl;
					cout << "Student Surname: ";
					cout << "		  " <<  arr[i].getStudentSname() << endl;
					
					cout << "Student Registration Date is: ";
					cout << "	  " << arr[i].getDate_Ordered() << endl << endl;
					
				}
				
				/*else if(key_else==1) {
					
					cout << endl;
					cout << "		NO STUDENT(S) FOUND BELONGS TO ENTERED NUMBER!" << endl << endl << endl;
					key_else=0;
				}*/	
			}
		}
	
		else if(input=="3") {
		
			cout << "3) Enter a year: " << endl;
			cin >> year;
			
			for(i=0;i<69;i++) {

				if(	arr[i].getDate_Ordered().substr(arr[i].getDate_Ordered().size() - 4) == year) {
					
					cout << endl;
					
					if(key_3==1) {
						
					cout << "		STUDENT(S) FOUND!" << endl << endl;
					
					}
					
					cout << "Student Name: ";
					cout << "			  " << arr[i].getStudentName() << endl;
					
					cout << "Student Surname: ";
					cout << "		  " <<  arr[i].getStudentSname() << endl;
					
					cout << "Student Number: ";
					cout << "		  " << arr[i].getStudentNumber() << endl << endl;
					
					key_3=0;
				}
				
				/*else if(key_else==1) {
				cout << endl;
				cout << "		NO STUDENT(S) FOUND ON THE ENTERED YEAR!" << endl << endl << endl;
				key_else=0;
				}*/
			}
		}

	
		else if(input=="4") {	
		
			cout << "4) Enter registration start & end date (dd.mm.yy): " << endl;
			cin >> start_date >> end_date;
			
			//ASSIGNING DAY _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
			//Finding DAY ->"3"<- .12.2018 from start_date
			start_date_day = start_date.substr( 0, start_date.find(".") );
			end_date_day = end_date.substr( 0, end_date.find(".") );
			//cout << start_date.substr(0, start_date.find(".")) << endl;
			//cout << end_date.substr(0, end_date.find(".")) << endl;	
			
			//ASSIGNING MONTH _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
			//Finding MONTH 3.-> "12" <-.2018 from start_date
			temp = start_date.substr( start_date.find( "." ) + 1 );
			pos = temp.find(".");
			start_date_month = temp.substr(0,pos);
    		//cout << start_date_month << endl;
			temp = end_date.substr( end_date.find( "." ) + 1 );
			pos = temp.find(".");
			end_date_month = temp.substr(0,pos);
    		//cout << end_date_month << endl;
		 					
			//ASSIGNING YEAR _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
			//Findeng YEAR 3.12. -> "2018" <- from start_date (Last 4 Letters of string :)
			start_date_year = start_date.substr(start_date.size() - 4);
			end_date_year = end_date.substr(end_date.size() - 4);
			//arr[i].getDate_Ordered().substr(arr[i].getDate_Ordered().size() - 4)
			
			//String to Integer Convertion
			st_dt_D=stoi(start_date_day);
			st_dt_M=stoi(start_date_month);
			st_dt_Y=stoi(start_date_year);
			
			end_dt_D=stoi(end_date_day);
			end_dt_M=stoi(end_date_month);
			end_dt_Y=stoi(end_date_year);
				
			cout << endl << endl << endl;
			cout << "Start Date: " << st_dt_D << ".";
			cout << st_dt_M << ".";
			cout << st_dt_Y << endl << endl;
			
			cout << "End Date: " << end_dt_D << ".";
			cout << end_dt_M << ".";
			cout << end_dt_Y << endl << endl;
			
			for(i=0;i<69;i++) {
				
				//For each day, month and year in ---> arr[i].getDate_Ordered();
				//cout << arr[i].getDate_Ordered() << endl << endl;

				//Finding Day
				class_day = arr[i].getDate_Ordered().substr( 0, arr[i].getDate_Ordered().find(".") );
				
				//Finding Month
				temp = arr[i].getDate_Ordered().substr( arr[i].getDate_Ordered().find( "." ) + 1 );
				pos = temp.find(".");
				class_month = temp.substr(0,pos);
				
				//Finding Year
				class_year = arr[i].getDate_Ordered().substr( arr[i].getDate_Ordered().size() - 4);
				
				//Converting Strings to Integers
				std::stringstream dd,mm,yy;
				
				dd << class_day;
				dd >> class_D;
				
				mm << class_month;
				mm >> class_M;
				
				yy << class_year;
				yy >> class_Y;	
				
				/*class_D, class_M, class_Y			
				st_dt_D=stoi(start_date_day);
				st_dt_M=stoi(start_date_month);
				st_dt_Y=stoi(start_date_year);
			
				end_dt_D=stoi(end_date_day);
				end_dt_M=stoi(end_date_month);
				end_dt_Y=stoi(end_date_year);*/

				if( datechecker( class_D, class_M, class_Y, st_dt_D, st_dt_M, st_dt_Y, end_dt_D, end_dt_M, end_dt_Y ) ) {
					
					cout << "		STUDENT(S) FOUND!" << endl << endl;
					
					cout << "Student Name: ";
					cout << "			  " << arr[i].getStudentName() << endl;
					
					cout << "Student Surname: ";
					cout << "		  " <<  arr[i].getStudentSname() << endl;
					
					cout << "Student Number: ";
					cout << "		  " << arr[i].getStudentNumber() << endl;
					
					cout << "Student Registration Date: ";
					cout << " 	  " << arr[i].getDate_Ordered() << endl << endl;	
				}			
			}							
		}
		
	} while(input!="0");


	return 0;
}

bool datechecker(int day, int month, int year, int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear) {
	
   	int Class_Date = (year * 10000) + (month * 100) + day;//Student Dates
   	
   	int Start_Date = (startYear * 10000) + (startMonth * 100) + startDay;
   	int End_Date = (endYear * 10000) + (endMonth * 100) + endDay;

   	if (Class_Date >= Start_Date && Class_Date <= End_Date) {
       	return true;
   	}
    	
   	else{
       	return false;
   	}
}
