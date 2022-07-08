//
//  Student.hpp
//  SalesciStudent
//
//  Created by Scott Alesci on 11/5/20.
//
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include "degreeType.hpp"
#ifndef Student_hpp
#define Student_hpp
using std::string;
using std::endl;
using std::cout;

#include <stdio.h>

class Student {
public:
    const static int daysInCourseSize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInCourse[daysInCourseSize];
    DegreeProgram degreeProgram;
public:
    // constructors
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);
    // destructor
    ~Student();
    
    // getters (accessors)
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();
    
    // setters (mutator)
    void setStudentID(string id);
    void setFirstName(string fName);
    void setLastName(string lName);
    void setEmail(string emailInput);
    void setAge(int ageInput);
    void setDaysInCourse(int daysInCourse[]);
    void setDegree(DegreeProgram degree);
    
    static void printHeader(); // header that displays the column names
    
    void print(); // print out the current object

};

#endif /* Student_hpp */
