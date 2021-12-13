/*
 * roster.h
 *
 *  Created on: Dec 8, 2021
 *      Author: Linmei
 */

#ifndef ROSTER_H_
#define ROSTER_H_

#include "student.h"
#include <string>
#include <vector>

using namespace std;

class Roster {
	public:
		//declare the array to store all student object
		vector<Student*> classRosterArray;

		//constructor
		Roster();

		//functions
		void add(string studentID, string firstName, string lastName,
				string emailAddress, int age, int daysInCourse1, int daysInCourse2,
				int daysInCourse3, DegreeProgram degreeprogram);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);
		DegreeProgram parseDegreeProgram(string degreeProgram);
		void init();

		//destructor
		virtual~Roster();
};

#endif /* ROSTER_H_ */
