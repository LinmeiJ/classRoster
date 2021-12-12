/*
 * Student.cpp
 *
 *  Created on: Dec 8, 2021
 *      Author: Linmei
 */

#include "Student.h"
#include "degree.h"
#include <iostream>
using namespace std;

//declare the Student constructor
Student::Student(string id, string fName, string lName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	studentID = id;
	firstName = fName;
	lastName = lName;
	emailAddress = email;
	this->age = age;
	setDaysInCourse(daysInCourse);
	this->degreeProgram = degreeProgram;
}

//below are declaring all setters and getters for Student object
int Student::getAge() const {
	return age;
}

void Student::setAge(int age) {
	this->age = age;
}

int* Student::getDaysInCourse(){
	return this->daysInCourse;
}

void Student::setDaysInCourse(int daysInCourse[]){
	for(int i = 0; i < 3;i++){
		this->daysInCourse[i] = daysInCourse[i];
	}
}

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
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


//below are all the function declaration
void Student::print(){
	cout << studentID <<"	First Name: "
		 << firstName <<"	Last Name: "
		 << lastName <<"	Age: "
		 << age << "	daysInCourse: {"
		 << daysInCourse[0] << ","
		 << daysInCourse[1] << ","
		 << daysInCourse[2]<< "}	Degree Program: "
		 << displayDegreeProgram(degreeProgram)
		 << endl;
}

string Student::displayDegreeProgram(DegreeProgram degree){
   switch(degree) {
       case 0:
    	   return "SECURITY";
           break;
       case 1:
    	   return "NETWORK";
           break;
       case 2:
    	   return "SOFTWARE";
           break;
       default:
    	   return "Unknown";
   }
}


//Destructor
Student::~Student() {}

