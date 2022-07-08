//
//  roster.hpp
//  SalesciStudent
//
//  Created by Scott Alesci on 11/6/20.
//
#pragma once
#ifndef roster_hpp
#define roster_hpp

#include <stdio.h>
#include "student.hpp"

class Roster{
public:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];
    
public:
    // declare the methods
    void parse(string row);
    void add(string studentID,
             string firstName,
             string lastName,
             string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
};



#endif /* roster_hpp */
