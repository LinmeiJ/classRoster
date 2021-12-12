/*
 * Student.h
 *
 *  Created on: Dec 8, 2021
 *      Author: Linmei
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using namespace std;

class Student{
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysInCourse[3];
		DegreeProgram degreeProgram;

	public:
		// constructor
		Student(string id, string fName, string lName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);


		//below are setting and getters for the class members
		int getAge() const;
		void setAge(int age);

		int* getDaysInCourse();
		void setDaysInCourse(int daysInCourse[]);

		DegreeProgram getDegreeProgram();
		void setDegreeProgram(DegreeProgram degreeProgram);

		string getEmailAddress() const;
		void setEmailAddress(string emailAddress);

		string getFirstName() const;
		void setFirstName(string firstName);

		string getLastName() const;
		void setLastName(string lastName);

		string getStudentId() const;
		void setStudentId(string studentId);



		//print function
		void print();
		//function to display the degree program for individual student
		string displayDegreeProgram(DegreeProgram degree);


		//Destructor
		virtual~Student();
};

#endif /* STUDENT_H */
