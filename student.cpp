//
//  Student.cpp
//  SalesciStudent
//
//  Created by Scott Alesci on 11/5/20.
//

#include "student.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

// Define empty constructor
Student::Student(){
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i=0; i < daysInCourseSize; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

// Define full constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram){
	
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i=0; i < daysInCourseSize; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}

// Define Destructor
Student::~Student(){}

// Define getters
string Student::getStudentID() {return this->studentID;}
string Student::getFirstName() {return this->firstName;}
string Student::getLastName() {return this->lastName;}
string Student::getEmail() {return this->email;}
int Student::getAge() {return this->age;}
int* Student::getDaysInCourse() {return this->daysInCourse;}
DegreeProgram Student::getDegreeProgram() {return this->degreeProgram;}

// Define Setters
void Student::setStudentID(string id){this->studentID = id;}
void Student::setFirstName(string fName){this->firstName = fName;}
void Student::setLastName(string lName){this->lastName = lName;}
void Student::setEmail(string emailInput){this->email = emailInput;}
void Student::setAge(int ageInput){this->age=ageInput;}
void Student::setDaysInCourse(int daysInCourse[]){
	for (int i=0; i<daysInCourseSize; i++) this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegree(DegreeProgram degree){this->degreeProgram = degree;}

void Student::printHeader(){
	cout << "Student ID|First Name|Last Name|Email|Age|Days in Course|Degree Program" << endl;
}

void Student::print(){
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysInCourse()[1] << ',';
	cout << this->getDaysInCourse()[2] << ',';
	cout << this->getDaysInCourse()[3] << '\t';
	cout << degreeProgramString[this->getDegreeProgram()] << endl;
}
