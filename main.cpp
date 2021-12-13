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

	// application author info
	cout << "C867-Scripting & Programming: Applications \n"
		 << "Language: C++ \n"
		 << "Student ID: #001530700 \n"
		 << "Name: Linmei Mills \n\n";

	Roster *classRoster = new Roster();
	classRoster->printAll();
	classRoster->printInvalidEmails();
	//loop through classRosterArray and use getter to get the student ID and passed to the function in the Roster class -> check above
	printAvgDaysInCourse(classRoster);
	classRoster->printByDegreeProgram(SOFTWARE);
	classRoster->remove("A3");
	classRoster->remove("A3");//remove it again

	cout << "DONE." << endl;

	delete classRoster;

}
