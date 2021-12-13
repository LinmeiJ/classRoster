/*
 * roster.cpp
 *
 *  Created on: Dec 8, 2021
 *      Author: Linmei
 */

#include "Roster.h"
#include "Student.h"
#include "degree.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//constructor and initialize a set of student data
Roster::Roster(){
	init();
}

void Roster::init(){
	//given a set of student data
		string studentData[] = {"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
								"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
						     	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
								"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
								"A5,Linmei,Mills,linmeijiang@hotmail.com,25,15,28,66,SOFTWARE"}; // student personal information added to the data table here

		//get the size of studentData array
		int size = *(&studentData + 1) - studentData;
		int i = 0;

		 //split strings by comma
		 while(i < size){
			vector<string> student;
			stringstream ss(studentData[i]);

			while(ss.good()){
				string substr;
				getline(ss, substr, ',');
				student.push_back(substr);
			}

			//store each string to student object
			add(student.at(0), student.at(1), student.at(2), student.at(3), stoi(student.at(4)),
							stoi(student.at(5)),  stoi(student.at(6)), stoi(student.at(7)), parseDegreeProgram(student.at(8)));
			i++;
		 }
}

DegreeProgram Roster::parseDegreeProgram(string degreeProgram){
	if(degreeProgram == "SECURITY"){
		return SECURITY;
	}
	else if(degreeProgram == "NETWORK"){
		return NETWORK;
	}
	else
		return SOFTWARE;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){

	int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
	classRosterArray.push_back(new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram));

}

void Roster::printAll(){
	cout << "Displaying all students: \n";

	for(size_t i =0; i < classRosterArray.size(); i++){
		classRosterArray.at(i)->print();
	}
	cout << endl;
}

void Roster::printInvalidEmails(){
	cout << "Displaying invalid emails: \n\n";

	for(size_t i =0; i < classRosterArray.size(); i++){
		string email = classRosterArray.at(i)->getEmailAddress();

		int countAt = 0;
		int countDot = 0;
		int countSpace = 0;

		//check if email address contains giving chars and also store their occurrence
		for(size_t i = 0; i < email.length(); i++){
			if(email[i] == '@'){
				countAt++;
			}
			if(email[i] == '.'){
				countDot++;
			}
			if(email[i] == ' '){
				countSpace++;
			}
		}
		//if there is no @, dot and has space OR there are more than one of @ and dot in the email,
		//the if statement becomes true - results invalid email
		if(countAt != 1 || countDot != 1 || countSpace != 0){
			cout << email << " is invalid." << endl;
		}
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID){
	//loop through each student object
	for(size_t i = 0; i < classRosterArray.size(); i++){
		if(classRosterArray.at(i)->getStudentId() == studentID) {
			int avg = (classRosterArray.at(i)->getDaysInCourse()[0] + classRosterArray.at(i)->getDaysInCourse()[1] + classRosterArray.at(i)->getDaysInCourse()[2])/3;
			cout << "Student ID: " << studentID << ", average days in course is: " << avg <<endl;
	    }
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
	cout << "\nShowing students in degree program: SOFTWARE \n\n";

	for(size_t i = 0; i < classRosterArray.size(); i++){
		if (classRosterArray.at(i)->getDegreeProgram() == degreeProgram) {
			classRosterArray.at(i)->print();
		}
	}
	cout << endl;
}

void Roster::remove(string studentID){
	int found = 0;

	for(size_t i = 0; i < classRosterArray.size(); i++){
		//if the student exists, the record will be deleted from the classRosterArray
		if(classRosterArray.at(i)->getStudentId() == studentID){
			classRosterArray.erase(classRosterArray.begin() + i , classRosterArray.begin()+ i + 1);
			found++;
		}
	}
	//as long as find a record, print the remaining ones
	if(found != 0){
		cout << "Removing A3: \n\n";
		printAll();
	}
	else{ //If the student ID does not exit at all, display this error message
		cout << "Removing A3 again: \n\n";
		cout << "Student with the ID : " << studentID << " was not found " << endl;
	}
}

    //destructor
Roster::~Roster(){
	vector<Student*>().swap(classRosterArray);
};

