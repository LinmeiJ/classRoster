//============================================================================
// Name        : main.cpp
// Author      : Linmei M.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Roster.h"
#include "Student.h"
using namespace std;

void printAvgDaysInCourse(Roster *roster) {
	for (size_t i = 0; i < roster->classRosterArray.size(); i++) {
		roster->printAverageDaysInCourse(
				roster->classRosterArray.at(i)->getStudentId());
	}
}

int main() {

	//given a set of student data
	string studentData[] = {"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
							"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
					     	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
							"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
							"A5,Linmei,Mills,linmeijiang@hotmail.com,25,15,28,66,SOFTWARE"}; // student personal information added to the data table here

	//get the size of studentData array
	int size = *(&studentData + 1) - studentData;

	//stores each student to the clasRoster
	Roster *classRoster = new Roster(size, studentData);

	// application author info
	cout << "C867-Scripting & Programming: Applications \n"
		 << "Language: C++ \n"
		 << "Student ID: #001530700 \n"
		 << "Name: Linmei Mills \n\n";


	classRoster->printAll();

	classRoster->printInvalidEmails();

	//loop through classRosterArray and use getter to get the student ID and passed to the function in the Roster class -> check above
	printAvgDaysInCourse(classRoster);

	classRoster->printByDegreeProgram(SOFTWARE);

	classRoster->remove("A3");

	classRoster->remove("A3");//remove it again

	cout << "DONE." << endl;

}
