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
		int daysInCourse[];
		Degree degreeProgram;

	// constructor
	public:Student(string id, string fName, string lName, string email, int age, int* daysInCourse[], Degree degree);

public:
	//below are setting and getters for the class members
	int getAge() const;

	void setAge(int age);

	int* getDaysInCourse() const;

	Degree getDegreeProgram() const;//fix me

	void setDegreeProgram(Degree degreeProgram);

	string getEmailAddress() const;

	void setEmailAddress(string emailAddress);

	string getFirstName() const;

	void setFirstName(string firstName);

	string getLastName() const;

	void setLastName(string lastName);

	string getStudentId() const;

	void setStudentId(string studentId);

	//function to print a student date
	void print() const;

	//Destructor
	~Student();


};

#endif /* STUDENT_H */
