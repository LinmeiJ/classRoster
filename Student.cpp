/*
 * Student.cpp
 *
 *  Created on: Dec 8, 2021
 *      Author: Linmei
 */

#include "Student.h"
#include <iostream>
using namespace std;

//declare the Student constructor
Student::Student(string id, string fName, string lName, string email, int age, int* daysInCourse, string degree) {
				studentID = id;
				firstName = fName;
				lastName = lName;
				emailAddress = email;
				this->age = age;
				this->daysInCourse = daysInCourse;
				degreeProgram = degree;
}

//below are declaring all setters and getters for Student object
int Student::getAge() const {
	return age;
}

void Student::setAge(int age) {
	this->age = age;
}

int* Student::getDaysInCourse() const {
	return daysInCourse;
}

Degree Student::getDegreeProgram() const {
	return degreeProgram;
}

void Student::setDegreeProgram(Degree degreeProgram) {
	this->degreeProgram = degreeProgram;
}

string Student::getEmailAddress() const {
	return emailAddress;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

string Student::getFirstName() const {
	return firstName;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

string Student::getLastName() const {
	return lastName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

string Student::getStudentId() const {
	return studentID;
}

void Student::setStudentId(string studentId) {
	studentID = studentId;
}

//Destructor
Student::~Student() {}

